/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_to_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 07:36:17 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 21:17:58 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	images_to_window(t_obj *obj)
{
	t_o		*o;
	t_point	pt;
	t_f_eng	f;

	o = obj->objs;
	while (o)
	{
		f = get_area_engine(obj->engines, o);
		f(o);
		p(&pt, o->posi.x, o->posi.y, 0);
		mlx_put_image_to_window(obj->x_p, obj->x_w, o->m->x_m, pt.x, pt.y);
		o = o->next;
	}
}
