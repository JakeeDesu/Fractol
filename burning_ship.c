/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 05:41:54 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/19 14:24:04 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		get_burning_ship_p(t_complex c, long long iter)
{
	long long	i;
	t_complex	z;
	double		mz;

	i = 0;
	cp(&z, 0, 0);
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

void	burning_ship(t_o *o)
{
	double		pas;
	t_set_1		*data;
	t_complex	c;

	data = (t_set_1*)(o->data);
	if (o->active > 0)
	{
		b_transform(o);
		cp(&c, data->oy.min, data->ox.min);
		b_accelerator(c, o);
	}
	else if (o->active < 0)
	{
		b_transform(o);
		cp(&c, data->oy.max, data->ox.min);
		b_accelerator(c, o);
		o->active = 0;
	}
}
