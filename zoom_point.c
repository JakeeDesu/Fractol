/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:03:20 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/19 16:11:27 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	zoom_point(t_o *o, t_point p)
{
	t_set_1		*d;
	t_complex	c;
	t_lim		center_x;
	t_lim		center_y;

	d = (t_set_1*)(o->data);
	d->pas *= d->ev.z;
	cp(&(c), (o->s_oy.max - p.y), (p.x + o->s_ox.min));
	lim(&center_x, o->s_ox.max - c.re, c.re - o->s_ox.min);
	lim(&center_y, o->s_oy.max - c.im, c.im - o->s_oy.min);
	cp(&(c), c.im * d->pas * (1 / d->ev.z), c.re * d->pas * (1 / d->ev.z));
	d->ox.max = (c.re) + (center_x.max * d->pas);
	d->ox.min = (c.re) - (center_x.min * d->pas);
	d->oy.max = (c.im) + (center_y.max * d->pas);
	d->oy.min = (c.im) - (center_y.min * d->pas);
	o->s_ox.max = d->ox.max / d->pas;
	o->s_ox.min = d->ox.min / d->pas;
	o->s_oy.max = d->oy.max / d->pas;
	o->s_oy.min = d->oy.min / d->pas;
	d->ev.z = 1;
}
