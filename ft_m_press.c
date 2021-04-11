/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_press.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 12:50:00 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/19 16:11:41 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	m_zoom(t_set_1 *data, int button)
{
	if (button == 5 && (data->ev.z == 1))
		data->ev.z = data->ev.z_in;
	else if (button == 4 && (data->ev.z == 1))
		data->ev.z = data->ev.z_out;
}

void	ft_m_press(t_o *objs, int id, int button, t_point point)
{
	t_o		*o;
	t_set_1	*data;

	if ((o = get_area(objs, id)) && on_area(point, o->w, o->h, o->posi))
	{
		data = (t_set_1*)(o->data);
		o->cursor.x = point.x - o->posi.x;
		o->cursor.y = point.y - o->posi.y;
		if (button == 1)
			o->holded = 1;
		else
			o->holded = 0;
		m_zoom(data, button);
	}
}
