/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:50:30 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 14:02:00 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_data(t_engine *eng, t_o *o, t_sets data_set)
{
	if (data_set == set_1)
		eng->data = set_1_init(o);
	else
	{
		ft_putstr("alloc data brob");
		exit(0);
	}
	o->data = eng->data;
}
