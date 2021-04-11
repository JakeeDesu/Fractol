/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 11:51:21 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 20:42:58 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	new_image(t_obj *obj, t_o *o)
{
	t_m		*m;
	void	*n;

	if (o->active != 0)
	{
		m = o->m;
		mlx_destroy_image(obj->x_p, m->x_m);
		m->x_m = mlx_new_image(obj->x_p, o->w, o->h);
		m->data = (int*)mlx_get_data_addr(m->x_m, &(m->bpp),
				&(m->line), &(m->endi));
	}
}
