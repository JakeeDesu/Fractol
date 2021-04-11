/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 08:57:01 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/19 11:37:40 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_m_move(t_o *objs, int id, int key, t_point point)
{
	t_o		*o;
	t_set_1	*data;

	if ((o = get_area(objs, id)))
	{
		data = (t_set_1*)(o->data);
		if (on_area(point, o->w, o->h, o->posi))
		{
			o->cursor.x = point.x - o->posi.x;
			o->cursor.y = point.y - o->posi.y;
		}
	}
}
