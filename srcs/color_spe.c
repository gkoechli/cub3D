/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_spe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduhau <gduhau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:44:45 by gduhau            #+#    #+#             */
/*   Updated: 2023/02/15 20:43:40 by gduhau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	vert_90(t_all *p, int mode, int **tab)
{
	int	i;

	if (mode == 1)
	{
		i = (int)floor(p->perso->y);
		while (tab[i][(int)floor(p->perso->x)] != 1)
			i--;
		return (p->perso->y - i - 1);
	}
	else if (mode == 2)
	{
		i = (int)floor(p->perso->y) + 1;
		while (tab[i][(int)floor(p->perso->x)] != 1)
			i++;
		return (i - p->perso->y);
	}
	else if (mode == 3)
	{
		i = floor(p->perso->x);
		while (tab[(int)floor(p->perso->y)][i] != 1)
			i--;
		return (p->perso->x - i - 1);
	}
	return (0);
}

void	color_spe90(t_all *p, int **tab, int ray, t_img *texture)
{
	t_packaging	pack;
	int			j;

	j = 0;
	pack.taille = ceil(HAUTEUR / vert_90(p, 1, tab));
	pack.renew = (p->perso->x - floor(p->perso->x)) * 64;
	pack.rayp = ray;
	if (pack.taille >= HAUTEUR)
	{
		big_wallnorth(pack.taille, p, ray, pack.renew);
		return ;
	}
	j = print_sky(pack.taille, p, j, ray);
	j = print_wall(pack, p, j, texture);
	print_floor(p, j, ray);
}

void	color_spe180(t_all *p, int **tab, int ray, t_img *texture)
{
	t_packaging	pack;
	int			j;

	j = 0;
	pack.taille = ceil(HAUTEUR / vert_90(p, 3, tab));
	pack.renew = 64 - (p->perso->y - floor(p->perso->y)) * 64;
	pack.rayp = ray;
	if (pack.taille >= HAUTEUR)
	{
		big_walleast(pack.taille, p, ray, pack.renew);
		return ;
	}
	j = print_sky(pack.taille, p, j, ray);
	j = print_wall(pack, p, j, texture);
	print_floor(p, j, ray);
}

void	color_spe270(t_all *p, int **tab, int ray, t_img *texture)
{
	t_packaging	pack;
	int			j;

	j = 0;
	pack.taille = ceil(HAUTEUR / vert_90(p, 2, tab));
	pack.renew = 64 - (p->perso->x - floor(p->perso->x)) * 64;
	pack.rayp = ray;
	if (pack.taille >= HAUTEUR)
	{
		big_wallsouth(pack.taille, p, ray, pack.renew);
		return ;
	}
	j = print_sky(pack.taille, p, j, ray);
	j = print_wall(pack, p, j, texture);
	print_floor(p, j, ray);
}
