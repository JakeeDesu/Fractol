/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_accelerator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 10:48:07 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/19 18:13:18 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	exec(cl_command_queue *c_q, cl_program *program, cl_mem *mem, t_o *o)
{
	int			size;
	cl_kernel	kernel;
	size_t		global_item_size;
	size_t		local_item_size;

	size = o->h * o->w;
	kernel = clCreateKernel(*program, "julia_gen", NULL);
	clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&(mem[2]));
	clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&(mem[0]));
	clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&(mem[1]));
	clSetKernelArg(kernel, 3, sizeof(cl_mem), (void *)&(mem[3]));
	clSetKernelArg(kernel, 4, sizeof(cl_mem), (void *)&(mem[4]));
	clSetKernelArg(kernel, 5, sizeof(cl_mem), (void *)&(mem[5]));
	global_item_size = size;
	local_item_size = 64;
	clEnqueueNDRangeKernel(*c_q, kernel, 1, NULL,
			&global_item_size, &local_item_size, 0, NULL, NULL);
	clEnqueueReadBuffer(*c_q, mem[2], CL_TRUE, 0,
			size * sizeof(int), o->m->data, 0, NULL, NULL);
	clFlush(*c_q);
	clFinish(*c_q);
	clReleaseKernel(kernel);
}

void	parallel(cl_device_id *device_id, cl_context *c, t_o *o, t_complex *cz)
{
	t_set_1				*data;
	cl_command_queue	command_queue;
	cl_mem				*mem;
	cl_program			program;

	data = (t_set_1*)(o->data);
	command_queue = clCreateCommandQueue(*c, *device_id, 0, NULL);
	mem = creat_mem(c, o);
	cpm(&command_queue, mem, o, cz);
	program = read_kernel("julia_gen_kernel.cl", c);
	clBuildProgram(program, 1, device_id, NULL, NULL, NULL);
	exec(&command_queue, &program, mem, o);
	clReleaseProgram(program);
	clReleaseMemObject(mem[0]);
	clReleaseMemObject(mem[1]);
	clReleaseMemObject(mem[2]);
	clReleaseMemObject(mem[3]);
	clReleaseMemObject(mem[4]);
	clReleaseMemObject(mem[5]);
	clReleaseCommandQueue(command_queue);
	free(mem);
}

void	j_accelerator(t_complex c, t_complex z, t_o *o)
{
	t_complex			*cz;
	cl_platform_id		platform_id;
	cl_device_id		device_id;
	cl_context			context;

	cz = (t_complex*)malloc(sizeof(t_complex) * 2);
	cp(&(cz[0]), c.im, c.re);
	cp(&(cz[1]), z.im, z.re);
	platform_id = NULL;
	device_id = NULL;
	clGetPlatformIDs(1, &platform_id, NULL);
	clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);
	context = clCreateContext(NULL, 1, &device_id, NULL, NULL, NULL);
	parallel(&device_id, &context, o, cz);
	clReleaseContext(context);
}
