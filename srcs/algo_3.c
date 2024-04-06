/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduhau <gduhau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:21:42 by gduhau            #+#    #+#             */
/*   Updated: 2023/02/15 19:39:30 by gduhau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	big_wallwest(double taille, t_all *p, int ray, int renew)
{
	int		j;
	double	base;
	double	y;

	j = 0;
	y = 0;
	while (j < floor((taille - HAUTEUR) / 2))
		j++;
	base = j * 64 / taille;
	j = 0;
	while (j <= HAUTEUR)
	{
		my_mlx_pixel_put(p->picture, ray, j++,
			*(unsigned int *)(p->text_west->addr
				+ ((int)(floor(y + base)) *(p->text_west->line_length)
					+ renew * (p->text_west->bits_per_pixel / 8))));
		y += 64 / taille;
	}
	return ;
}

void	big_walleast(double taille, t_all *p, int ray, int renew)
{
	int		j;
	double	base;
	double	y;

	j = 0;
	y = 0;
	while (j < floor((taille - HAUTEUR) / 2))
		j++;
	base = j * 64 / taille;
	j = 0;
	while (j <= HAUTEUR)
	{
		my_mlx_pixel_put(p->picture, ray, j++,
			*(unsigned int *)(p->text_east->addr
				+ ((int)(floor(y + base)) *(p->text_east->line_length)
					+ renew * (p->text_east->bits_per_pixel / 8))));
		y += 64 / taille;
	}
	return ;
}

void	big_wallnorth(double taille, t_all *p, int ray, int renew)
{
	int		j;
	double	base;
	double	y;

	j = 0;
	y = 0;
	while (j < floor((taille - HAUTEUR) / 2))
		j++;
	base = j * 64 / taille;
	j = 0;
	while (j <= HAUTEUR)
	{
		my_mlx_pixel_put(p->picture, ray, j++,
			*(unsigned int *)(p->text_north->addr
				+ ((int)(floor(y + base)) *(p->text_north->line_length)
					+ renew * (p->text_north->bits_per_pixel / 8))));
		y += 64 / taille;
	}
	return ;
}

void	big_wallsouth(double taille, t_all *p, int ray, int renew)
{
	int		j;
	double	base;
	double	y;

	j = 0;
	y = 0;
	while (j < floor((taille - HAUTEUR) / 2))
		j++;
	base = j * 64 / taille;
	j = 0;
	while (j <= HAUTEUR)
	{
		my_mlx_pixel_put(p->picture, ray, j++,
			*(unsigned int *)(p->text_south->addr
				+ ((int)(floor(y + base)) *(p->text_south->line_length)
					+ renew * (p->text_south->bits_per_pixel / 8))));
		y += 64 / taille;
	}
	return ;
}
