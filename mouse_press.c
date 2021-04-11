/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 07:40:01 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 21:27:42 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mouse_press(int button, int x, int y, t_obj *obj)
{
	t_point		point;
	t_o			*o;
	t_f_m_pr	m_pr;

	o = obj->objs;
	while (o)
	{
		p(&point, x, y, 0);
		m_pr = get_area_engine_m_pr(obj->engines, o);
		if (m_pr)
		{
			new_image(obj, o);
			m_pr(obj->objs, o->id, button, point);
			images_to_window(obj);
		}
		o = o->next;
	}
	return (1);
}
