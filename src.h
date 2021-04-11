/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 02:42:36 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/18 09:32:09 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_SRC_H
# define H_SRC_H

typedef struct	s_lim
{
	double max;
	double min;
}				t_lim;

typedef struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		c;
	t_color	color;
}				t_point;

typedef struct	s_area
{
	t_point	posi;
	t_point	size;
}				t_area;

typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
}				t_vec;

typedef struct	s_complex
{
	double	im;
	double	re;
}				t_complex;

void			lim(t_lim *l, double max, double min);
int				c_int(char r, char g, char b);
void			p(t_point *p, int x, int y, int z);
void			p_p(t_point *p1, t_point p2);
void			p_c(t_point *p, int c);
void			p_tc(t_point *p, char r, char g, char b);
void			cp(t_complex *z, double im, double re);
t_complex		cp_plus(t_complex z1, t_complex z2);
double			cp_abs(t_complex z);
void			cp_sqr(t_complex *z);
void			v(t_vec *v, double x, double y, double z);
int				on_area(t_point p, int w, int h, t_point posi);
int				color_generator(int n, long long range);

#endif
