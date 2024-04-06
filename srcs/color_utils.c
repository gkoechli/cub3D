/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduhau <gduhau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:50:21 by gduhau            #+#    #+#             */
/*   Updated: 2023/02/15 20:29:24 by gduhau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	print_sky(double taille, t_all *p, int j, int ray)
{
	while ((taille < HAUTEUR && j < (HAUTEUR - taille) / 2))
		my_mlx_pixel_put(p->picture, ray, j++, create_trgb(p->data->c_tab[0],
				p->data->c_tab[1], p->data->c_tab[2]));
	return (j);
}

void	print_floor(t_all *p, int j, int ray)
{
	while (j < HAUTEUR)
		my_mlx_pixel_put(p->picture, ray, j++, create_trgb(p->data->f_tab[0],
				p->data->f_tab[1], p->data->f_tab[2]));
}

int	print_wall(t_packaging pack, t_all *p, int j, t_img *texture)
{
	double	y;

	y = 0;
	while ((pack.taille < HAUTEUR && j < (pack.taille
				+ (HAUTEUR - pack.taille) / 2))
		|| (pack.taille > HAUTEUR && j < HAUTEUR))
	{
		my_mlx_pixel_put(p->picture, pack.rayp, j++,
			*(unsigned int *)(texture->addr
				+ ((int)floor(y) * texture->line_length
					+ pack.renew * (texture->bits_per_pixel / 8))));
		y += 64 / pack.taille;
	}
	return (j);
}
