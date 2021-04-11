/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 18:48:52 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/19 19:34:49 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	free_o(t_o **o)
{
	t_o *so;

	so = *o;
	if (so->m)
	{
		free(so->m);
		so->m = NULL;
	}
	if (so->data)
	{
		free(so->data);
		so->data = NULL;
	}
	free(so);
	*o = NULL;
}

void	free_eng(t_engine **eng)
{
	t_engine *seng;

	seng = *eng;
	if (seng)
		free(seng);
	*eng = NULL;
}

void	free_obj(t_obj *obj)
{
	free_o(&(obj->objs));
	free_eng(&(obj->engines));
}
