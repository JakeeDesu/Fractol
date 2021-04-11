/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:20:55 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 21:04:08 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	copy_o(t_o *o, t_o *o2)
{
	t_set_1 *data;

	o->data = o2->data;
	o->id = o2->id;
	data = (t_set_1*)(o->data);
	data->pas = o->pas;
	o->active = o2->active;
	o->selected = o2->selected;
	o->holded = o2->holded;
}
