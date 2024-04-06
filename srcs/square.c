/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduhau <gduhau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:07:16 by gatsby            #+#    #+#             */
/*   Updated: 2023/02/16 12:37:06 by gduhau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_bis	init_spe(int x, int y)
{
	t_bis	bs;

	bs.x = x;
	bs.y = y;
	return (bs);
}

t_point	next_square2(t_eq eq, double px, double py, int **tab)
{
	t_point	r;
	t_bis	bs;

	bs = init_spe(floor(px), floor(py));
	while (bs.x >= 0 && bs.y >= 0)
	{
		if (eq.a * bs.x + eq.b < -bs.y)
		{
			if (bs.x > 0 && tab[bs.y][bs.x - 1] == 1)
				return (r.ori = E, r.x = bs.x - 1, r.y = bs.y, r);
			if (bs.x == 0 && tab[bs.y][bs.x] == 1)
				return (r.ori = E, r.x = bs.x, r.y = bs.y, r);
			bs.x = special_incr(bs.x);
		}
		else if (eq.a * bs.x + eq.b > -bs.y)
		{
			if (bs.y > 0 && tab[bs.y - 1][bs.x] == 1)
				return (r.ori = N, r.x = bs.x, r.y = bs.y -1, r);
			if (bs.y == 0 && tab[bs.y][bs.x] == 1)
				return (r.ori = N, r.x = bs.x, r.y = bs.y, r);
			bs.y = special_incr(bs.y);
		}
	}
	return (r.x = -1, r.y = -1, r);
}

t_point	next_square2bis(t_eq eq, double px, double py, int **tab)
{
	t_point	r;
	t_bis	bs;

	bs.x = floor(px);
	bs.y = floor(py) + 1;
	while (bs.x >= -1 && bs.y >= -1)
	{
		if (eq.a * bs.x + eq.b < -bs.y)
		{
			if (tab[bs.y][bs.x] == 1)
				return (r.ori = S, r.x = bs.x, r.y = bs.y, r);
			if (bs.y > 0)
				bs.y++;
		}
		else if (eq.a * bs.x + eq.b > -bs.y)
		{
			if (tab[bs.y - 1][bs.x - 1] == 1)
				return (r.ori = E, r.x = bs.x - 1, r.y = bs.y -1, r);
			if (bs.x > 0)
				bs.x--;
		}
	}
	return (r.x = -1, r.y = -1, r);
}

t_point	next_square2bisbis(t_eq eq, double px, double py, int **tab)
{
	t_point	r;
	t_bis	bs;

	bs.x = floor(px);
	bs.y = floor(py);
	while (bs.x >= -1 && bs.y >= -1)
	{
		if (eq.a * bs.x + eq.b < -bs.y)
		{
			if (tab[bs.y][bs.x - 1] == 1)
				return (r.ori = E, r.x = bs.x - 1, r.y = bs.y, r);
			if (bs.x > 0)
				bs.x--;
		}
		else if (eq.a * bs.x + eq.b > -bs.y)
		{
			if (tab[bs.y - 1][bs.x] == 1)
				return (r.ori = N, r.x = bs.x, r.y = bs.y - 1, r);
			if (bs.y > 0)
				bs.y--;
		}
	}
	return (r.x = -1, r.y = -1, r);
}

t_point	next_square1bis(t_eq eq, double px, double py, int **tab)
{
	t_point	r;
	t_bis	bs;

	bs.x = floor(px) + 1;
	bs.y = floor(py);
	while (bs.x >= -1 && bs.y >= -1)
	{
		if (eq.a * bs.x + eq.b < -bs.y)
		{
			if (tab[bs.y][bs.x] == 1)
				return (r.ori = O, r.x = bs.x, r.y = bs.y, r);
			bs.x++;
		}
		else if (eq.a * bs.x + eq.b > -bs.y)
		{
			if (tab[bs.y - 1][bs.x - 1] == 1)
				return (r.ori = N, r.x = bs.x -1, r.y = bs.y -1, r);
			if (bs.y > 0)
				bs.y--;
		}
	}
	return (r.x = -1, r.y = -1, r);
}
