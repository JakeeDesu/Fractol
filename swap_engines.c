/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_engines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:44:31 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 20:52:14 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	swap_v1(t_o *o, t_o *o2)
{
	void	*data2;
	t_set_1	*d1;
	t_set_1	*d2;
	double	pas;

	d1 = (t_set_1*)(o->data);
	d2 = (t_set_1*)(o2->data);
	pas = d1->pas;
	d1->pas *= (double)((o->s_ox.max - o->s_ox.min) /
			(o2->s_ox.max - o2->s_ox.min));
	d2->pas *= (double)((o2->s_ox.max - o2->s_ox.min) /
			(o->s_ox.max - o->s_ox.min));
	data2 = o->data;
	o->data = o2->data;
	o2->data = data2;
}

void	swap_engines(t_o *o, t_o *o2)
{
	int		id;
	t_point	ps;

	if (o != o2)
	{
		if (o->active != 1)
			o->active = 1;
		else
			o2->active = -1;
		p(&(o->cursor), o2->cursor.x, o2->cursor.y, 0);
		p(&(o2->cursor), ps.x, ps.y, 0);
		id = o->id;
		o->id = o2->id;
		o2->id = id;
	}
}
