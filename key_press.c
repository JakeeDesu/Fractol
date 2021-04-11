/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 07:40:01 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/19 19:33:26 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	key_press(int key_code, t_obj *obj)
{
	t_point		point;
	t_o			*o;
	t_f_k_pr	k_pr;

	o = obj->objs;
	while (o)
	{
		k_pr = get_area_engine_k_pr(obj->engines, o);
		p(&point, 0, 0, 0);
		if (k_pr && o->selected)
		{
			new_image(obj, o);
			k_pr(obj->objs, o->id, key_code, point);
			images_to_window(obj);
		}
		if (((t_set_1*)(obj->objs->data))->ev.exit == 1)
		{
			free_obj(obj);
			exit(0);
		}
		o = o->next;
	}
	return (1);
}
