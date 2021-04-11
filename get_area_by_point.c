/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_area_by_point.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:39:38 by hmhindat          #+#    #+#             */
/*   Updated: 2019/04/14 15:57:35 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_o		*get_area_by_point(t_o *objs, t_point point)
{
	t_o *o;

	o = objs;
	while (o)
	{
		if (on_area(point, o->w, o->h, o->posi))
			return (o);
		o = o->next;
	}
	return (NULL);
}
