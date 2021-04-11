/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 06:37:18 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/19 19:25:45 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	catch_events(t_obj *obj)
{
	if (obj->objs)
	{
		mlx_hook(obj->x_w, m_mv, 0, mouse_move, obj);
		mlx_hook(obj->x_w, m_pr, 0, mouse_press, obj);
		mlx_hook(obj->x_w, m_re, 0, mouse_release, obj);
		mlx_hook(obj->x_w, k_pr, 0, key_press, obj);
	}
}
