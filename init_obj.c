/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 05:08:33 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/19 14:51:00 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_obj(t_obj *obj, t_f_eng f)
{
	t_point		posi;
	t_point		size;
	int			a_id;
	t_engine	*eng;

	p(&posi, 0, 0, 0);
	p(&size, MAIN_S, MAIN_S, 0);
	a_id = make_area(obj, size.x, size.y, posi);
	eng = add_engine(obj, f, a_id);
	init_data(eng, get_area(obj->objs, a_id), set_1);
	add_event(eng, &ft_m_press, m_press);
	add_event(eng, &ft_m_release, m_release);
	add_event(eng, &ft_m_move, m_move);
	add_event(eng, &ft_k_press, k_press);
	p(&(obj->available.posi), MAIN_S, 0, 0);
	p(&(obj->available.size), SECOND_S, SECOND_S, 0);
	p(&(obj->available.size), SECOND_S, SECOND_S, 0);
	p_p(&(obj->s2_size), obj->available.size);
}
