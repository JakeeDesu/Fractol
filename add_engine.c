/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_engine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 02:36:07 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 21:17:11 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		null_fun(t_engine *eng, int a_id, t_f_eng f)
{
	eng->a_id = a_id;
	eng->f = f;
	eng->next = NULL;
	eng->m_mv = NULL;
	eng->m_pr = NULL;
	eng->m_re = NULL;
	eng->k_pr = NULL;
}

t_engine	*add_engine(t_obj *obj, t_f_eng f, int a_id)
{
	t_engine	*eng;

	if (obj)
	{
		eng = obj->engines;
		if (!(obj->engines))
		{
			obj->engines = malloc(sizeof(t_engine));
			eng = obj->engines;
		}
		else
		{
			while (eng->next)
				eng = eng->next;
			eng->next = malloc(sizeof(t_engine));
			eng = eng->next;
		}
		null_fun(eng, a_id, f);
		return (eng);
	}
	return (NULL);
}
