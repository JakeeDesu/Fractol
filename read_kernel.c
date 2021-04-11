/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_accelerator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 10:48:07 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/19 14:19:36 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

cl_program	read_kernel(char *name, cl_context *c)
{
	int			fd;
	char		*str;
	size_t		size;
	cl_program	p;

	fd = open(name, O_RDONLY);
	str = (char*)malloc(MAX_SOURCE_SIZE);
	size = read(fd, str, MAX_SOURCE_SIZE);
	close(fd);
	p = clCreateProgramWithSource(*c, 1, (const char **)&str,
			(const size_t *)&size, NULL);
	return (p);
}
