/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_1_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:04:18 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/19 19:19:50 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	*set_1_init(t_o *o)
{
	t_set_1 *d;

	if (!(d = malloc(sizeof(t_set_1))))
		return (NULL);
	d->iter = 500;
	d->pas = o->pas;
	lim(&(d->ox), o->s_ox.max * d->pas, o->s_ox.min * d->pas);
	lim(&(d->oy), o->s_oy.max * d->pas, o->s_oy.min * d->pas);
	d->zoom = 1;
	d->ev.z = 1;
	d->ev.z_out = 1.2;
	d->ev.z_in = 1 / 1.2;
	d->ev.x = 0;
	d->ev.y = 0;
	d->ev.follow = 0;
	d->ev.c = 1;
	d->ev.exit = 0;
	return (d);
}
