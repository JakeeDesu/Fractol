/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:22:48 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 08:24:59 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		find_place(t_obj *obj, t_point *posi, t_point *size)
{
	t_point	v;
	int		j;

	j = full_test(obj->available.posi, obj->s2_size);
	if (j)
	{
		remake_places(obj);
		return (find_place(obj, posi, size));
	}
	else
	{
		p(posi, obj->available.posi.x, obj->available.posi.y, 0);
		p(size, obj->s2_size.x, obj->s2_size.y, 0);
		next_place(&(obj->available.posi), obj->s2_size);
		return (1);
	}
	return (0);
}
