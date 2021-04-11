/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_generator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 11:41:24 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 09:23:25 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		color_generator(int n, long long range)
{
	double gr;

	gr = ((double)(0xFFFFFF) / (double)25);
	return ((int)(gr * (double)n));
	if (n % 2)
		return (0xFFFFFF);
	else
		return (0x000);
}
