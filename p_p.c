/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_p.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 05:37:29 by hmhindat          #+#    #+#             */
/*   Updated: 2019/04/12 09:11:52 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	p_p(t_point *p1, t_point p2)
{
	p1->x = p2.x;
	p1->y = p2.y;
	p1->z = p2.z;
}
