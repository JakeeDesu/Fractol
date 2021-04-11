/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 07:40:01 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 21:19:00 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mouse_release(int button, int x, int y, t_obj *obj)
{
	t_point		point;
	t_o			*o;
	t_f_m_re	m_re;

	o = obj->objs;
	while (o)
	{
		p(&point, x, y, 0);
		m_re = get_area_engine_m_re(obj->engines, o);
		if (m_re)
		{
			new_image(obj, o);
			m_re(obj->objs, o->id, button, point);
			images_to_window(obj);
		}
		o = o->next;
	}
	return (1);
}
