/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 02:36:07 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 08:17:02 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_o		*add_o(t_obj *obj)
{
	t_o *o;

	if (obj)
	{
		o = obj->objs;
		if (!(obj->objs))
		{
			obj->objs = malloc(sizeof(t_o));
			obj->objs->id = 0;
			o = obj->objs;
		}
		else
		{
			while (o->next)
				o = o->next;
			o->next = malloc(sizeof(t_o));
			o->next->id = o->id + 1;
			o = o->next;
		}
		o->m = NULL;
		o->next = NULL;
		return (o);
	}
	return (NULL);
}
