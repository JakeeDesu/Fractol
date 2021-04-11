/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remake_places.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:50:20 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 08:24:23 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		count_s2_o(t_o *o)
{
	t_o		*ox;
	int		cnt;

	cnt = 0;
	ox = o;
	while (ox)
	{
		if (ox->id > 0)
			cnt++;
		ox = ox->next;
	}
	return (cnt);
}

void	make_n_obj(t_obj *obj, t_o **o, int n)
{
	t_obj	beta;
	int		i;
	t_point	posi;
	t_point	size;

	i = 0;
	beta.x_p = obj->x_p;
	beta.x_w = obj->x_w;
	beta.objs = NULL;
	while (i < n)
	{
		find_place(obj, &posi, &size);
		make_area(&beta, size.x, size.y, posi);
		i++;
	}
	*o = beta.objs;
}

void	copy_list_o(t_o *o, t_o *o2)
{
	t_o *l;
	t_o *l2;

	l = o;
	l2 = o2;
	while (l2 && l)
	{
		copy_o(l, l2);
		l = l->next;
		l2 = l2->next;
	}
}

int		remake_places(t_obj *obj)
{
	t_o		*o;
	t_o		*o_new;
	t_point	posi;
	t_point	size;

	o = obj->objs->next;
	p(&(obj->s2_size), obj->s2_size.x / 2, obj->s2_size.y / 2, 0);
	p(&(obj->available.posi), MAIN_S, 0, 0);
	p(&(obj->available.size), SECOND_S, SECOND_S, 0);
	if (obj->s2_size.x <= MIN_A_S)
		return (0);
	make_n_obj(obj, &o_new, count_s2_o(o));
	copy_list_o(o_new, o);
	obj->objs->next = o_new;
	return (1);
}
