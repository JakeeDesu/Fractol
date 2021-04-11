/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 05:41:54 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 20:39:47 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		get_julia_p(t_complex z, t_complex c, long long iter)
{
	long long	i;
	double		mz;

	i = 0;
	mz = 0;
	while (mz < 4 && i < iter)
	{
		cp_sqr(&z);
		z = cp_plus(z, c);
		mz = cp_abs(z);
		i++;
	}
	if (i == iter)
		return (0x000);
	else
		return (color_generator(i, iter));
}

void	julia(t_o *o)
{
	double		pas;
	t_complex	z;
	t_complex	c;
	t_set_1		*data;

	data = (t_set_1*)(o->data);
	if (o->active > 0)
	{
		j_transform(o);
		cp(&z, data->oy.max, data->ox.min);
		cp(&c, data->mouse.im, data->mouse.re);
		j_accelerator(c, z, o);
	}
	else if (o->active < 0)
	{
		data->ev.follow = 0;
		j_transform(o);
		cp(&z, data->oy.max, data->ox.min);
		cp(&c, data->mouse.im, data->mouse.re);
		j_accelerator(c, z, o);
		o->active = 0;
	}
}
