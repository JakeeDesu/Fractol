/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 20:11:40 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 22:15:06 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	p(t_point *p, int x, int y, int z)
{
	p->x = x;
	p->y = y;
	p->z = z;
}

int		c_int(char r, char g, char b)
{
	return ((int)(r * 65536) + (int)(g * 256) + (int)(b));
}

void	p_c(t_point *p, int c)
{
	p->color.r = (char)(c / 65536);
	p->color.g = (char)((c % 65536) / 256);
	p->color.b = (char)(c % 256);
	p->c = c;
}

void	p_tc(t_point *p, char r, char g, char b)
{
	p->color.r = r;
	p->color.g = g;
	p->color.b = b;
	p->c = c_int(r, g, b);
}

void	v(t_vec *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}
