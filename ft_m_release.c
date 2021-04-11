/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_release.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:08:12 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/19 00:10:39 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_m_release(t_o *objs, int id, int button, t_point point)
{
	t_o *o;
	t_o *o2;

	if ((o = get_area(objs, id)))
	{
		if (o->holded && button == 1)
		{
			o->holded = 0;
			if ((o2 = get_area_by_point(objs, point)))
				swap_engines(o, o2);
		}
	}
}
