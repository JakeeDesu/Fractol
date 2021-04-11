/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:36:35 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/19 19:19:38 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_DATA_H
# define H_DATA_H
# include "src.h"
# define W_S 1280
# define H_S (W_S)
# define MAIN_S H_S
# define SECOND_S H_S
# define MIN_A_S SECOND_S / 100
# define PADDIN 4

typedef enum	e_sets
{
	set_1, set_2
}				t_sets;

typedef struct	s_events
{
	int			exit;
	double		x;
	double		y;
	double		z;
	double		z_in;
	double		z_out;
	int			follow;
	int			c;
}				t_events;

typedef struct	s_set_1
{
	long long	iter;
	t_complex	mouse;
	t_lim		ox;
	t_lim		oy;
	double		zoom;
	double		pas;
	double		ss_pas;
	t_events	ev;
}				t_set_1;

typedef struct	s_set_2
{
	t_complex	mouse;
	t_lim		ox;
	t_lim		oy;
	t_vec		io;
	t_point		curr;
	double		zoom;
	double		pas;

}				t_set_2;

#endif
