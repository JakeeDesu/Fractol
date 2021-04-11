/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_area.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:10:29 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 21:16:30 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		add_area(t_obj *obj, t_f_eng f)
{
	t_point		posi;
	t_point		size;
	int			a_id;
	t_engine	*eng;

	if (find_place(obj, &posi, &size) > 0)
	{
		a_id = make_area(obj, size.x, size.y, posi);
		eng = add_engine(obj, f, a_id);
		init_data(eng, get_area(obj->objs, a_id), set_1);
		add_event(eng, &ft_m_press, m_press);
		add_event(eng, &ft_m_release, m_release);
		add_event(eng, &ft_m_move, m_move);
		add_event(eng, &ft_k_press, k_press);
		return (0);
	}
	return (1);
}
