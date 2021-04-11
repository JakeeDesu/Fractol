/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 00:47:18 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 22:15:16 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		cp(t_complex *z, double im, double re)
{
	z->im = im;
	z->re = re;
}

t_complex	cp_plus(t_complex z1, t_complex z2)
{
	t_complex n;

	n.im = z1.im + z2.im;
	n.re = z1.re + z2.re;
	return (n);
}

double		cp_abs(t_complex z)
{
	double r;

	r = (z.im * z.im) + (z.re * z.re);
	return (r);
}

void		cp_sqr(t_complex *z)
{
	double i;
	double r;

	i = z->im;
	r = z->re;
	z->im = i * r * 2;
	z->re = (r * r) - (i * i);
}
