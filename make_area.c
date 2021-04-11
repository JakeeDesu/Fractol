/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_area.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 03:31:18 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/19 19:00:39 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_image(t_obj *obj, t_o *o)
{
	t_m		*m;
	int		*data;

	o->m = malloc(sizeof(t_o));
	m = o->m;
	m->size = o->h * o->w;
	m->x_m = mlx_new_image(obj->x_p, o->w, o->h);
	data = (int*)mlx_get_data_addr(m->x_m, &(m->bpp), &(m->line), &(m->endi));
	m->data = data;
}

int		make_area(t_obj *obj, int w, int h, t_point posi)
{
	t_o *o;
	t_m *m;

	o = add_o(obj);
	if (o)
	{
		o->h = h;
		o->w = w;
		p_p(&(o->posi), posi);
		if (o->id == 0 && (o->selected = 1))
			o->active = 1;
		else
		{
			o->selected = 0;
			o->active = -1;
		}
		o->holded = 0;
		o->pas = ((o->w < o->h) ? 4 / (double)(o->w) : 4 / (double)(o->h));
		lim(&(o->s_ox), ((double)(o->w) / 2), -(((double)(o->w) / 2)));
		lim(&(o->s_oy), ((double)(o->h) / 2), -(((double)(o->h) / 2)));
		p(&(o->cursor), o->w / 2, o->h / 2, 0);
		init_image(obj, o);
		return (o->id);
	}
	return (-1);
}
