/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_transform.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:03:20 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/19 16:16:35 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	m_transform(t_o *o)
{
	t_set_1	*d;
	t_point	center;

	d = (t_set_1*)(o->data);
	if (d->ev.x || d->ev.y)
	{
		lim(&(o->s_ox), o->s_ox.max + d->ev.x, o->s_ox.min + d->ev.x);
		lim(&(o->s_oy), o->s_oy.max + d->ev.y, o->s_oy.min + d->ev.y);
		d->ev.y = 0;
		d->ev.x = 0;
	}
	if (d->ev.follow)
	{
		zoom_point(o, o->cursor);
	}
	else
	{
		p(&center, o->w / 2, o->h / 2, 0);
		zoom_point(o, center);
	}
}
