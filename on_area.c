/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_area.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 09:35:10 by hmhindat          #+#    #+#             */
/*   Updated: 2019/04/14 10:21:22 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		on_area(t_point p, int w, int h, t_point posi)
{
	if (p.x > posi.x && p.x < posi.x + w)
		if (p.y > posi.y && p.y < posi.y + h)
			return (1);
	return (0);
}
