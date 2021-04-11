/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accelerator_fun.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 10:48:07 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/19 14:23:20 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

cl_mem	*b_creat_mem(cl_context *c, t_o *o)
{
	int		s;
	cl_mem	*m_o;
	cl_int	r;

	s = o->h * o->w;
	m_o = (cl_mem*)malloc(sizeof(cl_mem) * 4);
	m_o[0] = clCreateBuffer(*c, CL_MEM_READ_ONLY, s * sizeof(double), NULL, &r);
	m_o[1] = clCreateBuffer(*c, CL_MEM_READ_ONLY, s * sizeof(double), NULL, &r);
	m_o[2] = clCreateBuffer(*c, CL_MEM_WRITE_ONLY, s * sizeof(int), NULL, &r);
	m_o[3] = clCreateBuffer(*c, CL_MEM_READ_ONLY, sizeof(int), NULL, &r);
	return (m_o);
}

void	b_fill_array(t_o *o, double **z_im, double **z_re, t_complex z)
{
	t_set_1	*data;
	int		s;
	int		i;

	data = (t_set_1*)(o->data);
	i = 0;
	s = o->h * o->w;
	*z_im = (double*)malloc(sizeof(double) * s);
	*z_re = (double*)malloc(sizeof(double) * s);
	(*z_im)[0] = z.im;
	(*z_re)[0] = z.re;
	while (++i < s)
	{
		(*z_re)[i] = (*z_re)[i - 1] + data->pas;
		(*z_im)[i] = (*z_im)[i - 1];
		if (!(i % o->w) && ((*z_re)[i] = z.re))
			(*z_im)[i] += data->pas;
	}
}

void	bcpm(cl_command_queue *c_q, cl_mem *m_o, t_o *o, t_complex z)
{
	t_set_1 *data;
	int		s;
	double	*z_im;
	double	*z_re;

	s = o->h * o->w;
	data = (t_set_1*)(o->data);
	b_fill_array(o, &z_im, &z_re, z);
	clEnqueueWriteBuffer(*c_q, m_o[3], CL_TRUE, 0, sizeof(int), &(data->iter),
			0, NULL, NULL);
	clEnqueueWriteBuffer(*c_q, m_o[0], CL_TRUE, 0, s * sizeof(double), z_im, 0,
			NULL, NULL);
	clEnqueueWriteBuffer(*c_q, m_o[1], CL_TRUE, 0, s * sizeof(double), z_re,
			0, NULL, NULL);
	free(z_im);
	free(z_re);
}
