/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:25:07 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 08:23:32 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	next_place(t_point *posi, t_point size)
{
	if (posi->x + size.x >= MAIN_S + SECOND_S)
	{
		posi->x = SECOND_S;
		posi->y += size.y;
	}
	else
		posi->x += size.x;
}

int		full_test(t_point posi, t_point size)
{
	if (posi.y + size.y > SECOND_S)
		return (1);
	return (0);
}
