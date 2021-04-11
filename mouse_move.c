/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 07:40:01 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 21:18:32 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mouse_move(int x, int y, t_obj *obj)
{
	t_point		point;
	t_o			*o;
	t_f_m_mv	m_mv;

	o = obj->objs;
	while (o)
	{
		p(&point, x, y, 0);
		m_mv = get_area_engine_m_mv(obj->engines, o);
		if (m_mv && o->selected)
		{
			new_image(obj, o);
			m_mv(obj->objs, o->id, 0, point);
			images_to_window(obj);
		}
		o = o->next;
	}
	return (1);
}
