/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:59:47 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/19 19:23:50 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	show_available(void)
{
	ft_putstr("USAGE :\n");
	ft_putstr("	./fractol [fract_name]\n");
	ft_putstr("available fracts :\n");
	ft_putstr("	1) - mandlbrot\n");
	ft_putstr("	2) - julia\n");
	ft_putstr("	3) - julia2\n");
	ft_putstr("	4) - drop\n");
	ft_putstr("	5) - burning_ship\n");
	ft_putstr("	6) - tricorn\n");
	ft_putstr("	7) - heart\n");
}

t_f_eng	ret_f(char *name)
{
	if (!(ft_strcmp(name, "mandlbrot")))
		return (&mandlbrot);
	else if (!(ft_strcmp(name, "julia")))
		return (&julia);
	else if (!(ft_strcmp(name, "julia2")))
		return (&julia3);
	else if (!(ft_strcmp(name, "drop")))
		return (&drop);
	else if (!(ft_strcmp(name, "burning_ship")))
		return (&burning_ship);
	else if (!(ft_strcmp(name, "tricorn")))
		return (&tricorn);
	else if (!(ft_strcmp(name, "heart")))
		return (&heart);
	return (NULL);
}

int		main(int argc, char **argv)
{
	t_obj	obj;
	int		i;
	int		size;
	t_f_eng	f;

	if (argc > 1 && (f = ret_f(argv[1])))
	{
		i = 0;
		obj.x_p = mlx_init();
		obj.x_w = mlx_new_window(obj.x_p, W_S, H_S, "FRACTALS");
		obj.objs = NULL;
		obj.engines = NULL;
		init_obj(&obj, f);
		images_to_window(&obj);
		catch_events(&obj);
		mlx_loop(obj.x_p);
	}
	else
		show_available();
	return (0);
}
