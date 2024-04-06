/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heights.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduhau <gduhau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:57:03 by gatsby            #+#    #+#             */
/*   Updated: 2023/02/16 12:36:03 by gduhau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	calcul_height(t_point obs, double px, double py, t_eq eq)
{
	t_point	tr;

	tr.x = -1;
	tr.y = -1;
	if (obs.ori == N)
	{
		tr.y = -(obs.y + 1);
		tr.x = (tr.y - eq.b) / eq.a;
	}
	else if (obs.ori == E)
	{
		tr.x = obs.x + 1;
		tr.y = eq.a * tr.x + eq.b;
	}
	else if (obs.ori == O)
	{
		tr.x = obs.x;
		tr.y = eq.a * (obs.x) + eq.b;
	}
	else if (obs.ori == S)
	{
		tr.y = -obs.y;
		tr.x = (tr.y - eq.b) / eq.a;
	}
	return (sqrt(pow(tr.x - px, 2) + pow(tr.y + py, 2)));
}

double	calcul_height5(t_point obs, double px, double py, t_eq eq)
{
	t_point	tr;

	tr.x = -1;
	tr.y = -1;
	if (obs.ori == S)
	{
		tr.y = -(obs.y);
		tr.x = (tr.y - eq.b) / eq.a;
	}
	else if (obs.ori == E)
	{
		tr.x = obs.x + 1;
		tr.y = eq.a * tr.x + eq.b;
	}
	else if (obs.ori == O)
	{
		tr.x = obs.x + 1;
		tr.y = eq.a * (tr.x) + eq.b;
	}
	else if (obs.ori == N)
	{
		tr.y = -(obs.y + 1);
		tr.x = (tr.y - eq.b) / eq.a;
	}
	return (sqrt(pow(tr.x - px, 2) + pow(tr.y + py, 2)));
}

double	calcul_height3(t_point obs, double px, double py, t_eq eq)
{
	t_point	tr;

	tr.x = -1;
	tr.y = -1;
	if (obs.ori == N)
	{
		tr.y = -(obs.y + 1);
		tr.x = (tr.y - eq.b) / eq.a;
	}
	else if (obs.ori == S)
	{
		tr.y = -obs.y;
		tr.x = (tr.y - eq.b) / eq.a;
	}
	else if (obs.ori == E)
	{
		tr.x = obs.x;
		tr.y = eq.a * tr.x + eq.b;
	}
	else if (obs.ori == O)
	{
		tr.x = obs.x;
		tr.y = eq.a * (obs.x) + eq.b;
	}
	return (sqrt(pow(tr.x - px, 2) + pow(tr.y + py, 2)));
}
