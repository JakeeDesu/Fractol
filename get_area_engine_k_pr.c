/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_area_engine_k_pr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 07:38:54 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 21:12:54 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_f_m_mv	get_area_engine_k_pr(t_engine *engines, t_o *o)
{
	t_engine *engs;

	engs = engines;
	if (engs)
	{
		while (engs && engs->a_id != o->id)
			engs = engs->next;
		if (engs)
			return (engs->k_pr);
	}
	return (NULL);
}
