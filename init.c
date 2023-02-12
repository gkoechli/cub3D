/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatsby <gatsby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:11:09 by gatsby            #+#    #+#             */
/*   Updated: 2023/02/10 20:30:03 by gatsby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

t_img	*init_image(t_win *mlx)
{
	t_img	*picture;

	picture = malloc(sizeof(t_img));
	if (!picture)
		return (NULL);
	picture->img = mlx_new_image(mlx->ptr, LARGEUR, HAUTEUR);
	picture->addr = mlx_get_data_addr(picture->img, &picture->bits_per_pixel, &picture->line_length,
								&picture->endian);
	return (picture);
}

t_all *init_textures(t_all *p)
{
    int widgth;
    int widgth2;
    int widgth3;
    int widgth4;

    widgth = 64;
    widgth2 = 64;
    widgth3 = 64;
    widgth4 = 64;
    p->text_north = malloc(sizeof(t_img));
	if (!p->text_north)
        return (NULL);
    p->text_north->img = mlx_xpm_file_to_image(p->mlx->ptr, NO, &widgth, &widgth);
	p->text_north->addr = mlx_get_data_addr(p->text_north->img, &p->text_north->bits_per_pixel, &p->text_north->line_length, &p->text_north->endian);
    p->text_south = malloc(sizeof(t_img));
    if (!p->text_south)
        return (NULL); //destroy other textures
    p->text_south->img = mlx_xpm_file_to_image(p->mlx->ptr, SO, &widgth2, &widgth2);
    p->text_south->addr = mlx_get_data_addr(p->text_south->img, &p->text_south->bits_per_pixel, &p->text_south->line_length, &p->text_south->endian);
    p->text_east = malloc(sizeof(t_img));
    if (!p->text_east)
        return (NULL);
    p->text_east->img = mlx_xpm_file_to_image(p->mlx->ptr, EA, &widgth3, &widgth3);
    p->text_east->addr = mlx_get_data_addr(p->text_east->img, &p->text_east->bits_per_pixel, &p->text_east->line_length, &p->text_east->endian);
    p->text_west = malloc(sizeof(t_img));
    if (!p->text_west)
        return (NULL);
    p->text_west->img = mlx_xpm_file_to_image(p->mlx->ptr, WE, &widgth4, &widgth4);
    p->text_west->addr = mlx_get_data_addr(p->text_west->img, &p->text_west->bits_per_pixel, &p->text_west->line_length, &p->text_west->endian);
    return (p);
}