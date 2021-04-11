/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_init_td.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:12:19 by hmhindat          #+#    #+#             */
/*   Updated: 2019/04/23 10:22:36 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_td	m_init_td(t_complex c, t_o *o)
{
	t_td	td;

	lim(&(td.ox), ((t_set_1*)(o->data))->ox.max, c.re);
	td.iter = ((t_set_1*)(o->data))->iter;
	td.pas = ((t_set_1*)(o->data))->pas;
	td.c.re = c.re;
	td.c.im = c.im;
	td.data = o->m->data;
	td.td_line = o->w;
	return (td);
}
