/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 02:36:07 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 21:13:11 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	add_event(t_engine *eng, t_f_ev f_event, t_type type)
{
	if (!(eng->m_mv) && type == m_move)
		eng->m_mv = f_event;
	else if (!(eng->m_pr) && type == m_press)
		eng->m_pr = f_event;
	else if (!(eng->m_re) && type == m_release)
		eng->m_re = f_event;
	else if (!(eng->k_pr) && type == k_press)
		eng->k_pr = f_event;
}
