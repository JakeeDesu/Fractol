/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_k_press.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 10:17:13 by hmhindat          #+#    #+#             */
/*   Updated: 2019/05/19 19:32:00 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	k_arrows(t_set_1 *data, int key)
{
	if (key == 123)
	{
		data->ev.x = 40;
	}
	else if (key == 124)
	{
		data->ev.x = -40;
	}
	else if (key == 125)
	{
		data->ev.y = 40;
	}
	else if (key == 126)
	{
		data->ev.y = -40;
	}
}

void	k_zoom(t_set_1 *data, int key)
{
	if (key == 69)
		data->ev.z = data->ev.z_in;
	else if (key == 78)
		data->ev.z = data->ev.z_out;
}

void	swap_and_iter(t_set_1 *data, int key)
{
	k_zoom(data, key);
	if (key == 24)
	{
		data->iter += 10;
	}
	else if (key == 27)
	{
		if (data->iter - 10 > 0)
			data->iter -= 10;
	}
}

void	ft_k_press(t_o *objs, int id, int key, t_point point)
{
	t_o		*o;
	t_set_1	*data;

	if ((o = get_area(objs, id)))
	{
		data = (t_set_1*)(o->data);
		if (key == 53)
			data->ev.exit = 1;
		else if (key == 3)
		{
			if (data->ev.follow)
				data->ev.follow = 0;
			else
				data->ev.follow = 1;
		}
		else if (key == 8)
		{
			if (data->ev.c)
				data->ev.c = 0;
			else
				data->ev.c = 1;
		}
		swap_and_iter(data, key);
		k_arrows(data, key);
	}
}
