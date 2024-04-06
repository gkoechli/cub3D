/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduhau <gduhau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:01:52 by gduhau            #+#    #+#             */
/*   Updated: 2023/02/16 12:34:47 by gduhau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	fcase90(double angle, int **tab, t_all *p, int ray)
{
	double	dist;
	t_point	obs;
	t_eq	eq;

	if (angle == 135)
		eq = attribute(-1, -p->perso->y + p->perso->x);
	else if (angle == 180)
		eq = attribute(0, -p->perso->y);
	else if (angle == 90)
		eq = attribute(p->perso->x, 0);
	else
	{
		eq.a = -1 / tan((angle - 90) * M_PI / 180);
		eq.b = -p->perso->y + p->perso->x / tan((angle - 90) * M_PI / 180);
	}
	obs.ori = -1;
	obs = next_square2(eq, p->perso->x, p->perso->y, tab);
	dist = calcul_height(obs, p->perso->x, p->perso->y, eq);
	if (obs.ori == E)
		color_eastside(p, ray, dist, angle);
	else if (obs.ori == N)
		color_northside(p, ray, dist, angle);
}

void	fcase180(double angle, int **tab, t_all *p, int ray)
{
	double	dist;
	t_point	obs;
	t_eq	eq;

	if (angle == 225)
		eq = attribute(-1, -p->perso->y + p->perso->x);
	else
	{
		eq.a = 1 / tan((90 - (angle - 180)) * M_PI / 180);
		eq.b = -p->perso->y - p->perso->x
			/ tan((90 - (angle - 180)) * M_PI / Z);
	}
	obs = next_square2bis(eq, p->perso->x, p->perso->y, tab);
	dist = calcul_height5(obs, p->perso->x, p->perso->y, eq);
	if (obs.ori == E)
		color_eastside(p, ray, dist, angle);
	else if (obs.ori == S)
		color_southside(p, ray, dist, angle);
}

void	fcase270(double angle, int **tab, t_all *p, int ray)
{
	double	dist;
	t_point	obs;
	t_eq	eq;

	if (angle == 315)
		eq = attribute(-1, -p->perso->y + p->perso->x);
	else if (angle == 360)
		eq = attribute(0, -p->perso->y);
	else
	{
		eq.a = -1 / tan((angle - 180 - 90) * M_PI / 180);
		eq.b = -p->perso->y + p->perso->x
			/ tan((angle - 180 -90) * M_PI / Z);
	}
	obs.ori = -1;
	obs = next_square4(eq, p->perso->x, p->perso->y, tab);
	dist = calcul_height(obs, p->perso->x, p->perso->y, eq);
	if (obs.ori == O)
		color_westside(p, ray, dist, angle);
	else if (obs.ori == S)
		color_southside(p, ray, dist, angle);
}

void	fcase0(double angle, int **tab, t_all *p, int ray)
{
	double	dist;
	t_point	obs;
	t_eq	eq;

	if (angle == 45)
		eq = attribute(1, -p->perso->y - p->perso->x);
	else if (angle == 0)
		eq = attribute(0, -p->perso->y);
	else
	{
		eq.a = 1 / tan((90 - angle) * M_PI / 180);
		eq.b = -p->perso->y - p->perso->x
			/ tan((90 - angle) * M_PI / Z);
	}
	obs = next_square1bis(eq, p->perso->x, p->perso->y, tab);
	dist = calcul_height3(obs, p->perso->x, p->perso->y, eq);
	if (obs.ori == O)
		color_westside(p, ray, dist, angle);
	else if (obs.ori == N)
		color_northside(p, ray, dist, angle);
}
