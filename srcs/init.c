/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:11:09 by gatsby            #+#    #+#             */
/*   Updated: 2023/02/16 14:05:09 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_img	*init_image(t_win *mlx)
{
	t_img	*picture;

	picture = malloc(sizeof(t_img));
	if (!picture)
		return (NULL);
	picture->img = mlx_new_image(mlx->ptr, LARGEUR, HAUTEUR);
	if (!picture->img || picture->img == NULL)
		return (free(picture), NULL);
	picture->addr = mlx_get_data_addr(picture->img, &picture->bits_per_pixel,
			&picture->line_length, &picture->endian);
	return (picture);
}

t_img	*init_onetext(char *path, t_win *mlx)
{
	int		widgth;
	t_img	*texture;

	widgth = 64;
	texture = malloc(sizeof(t_img));
	if (!texture)
		return (NULL);
	texture->img = mlx_xpm_file_to_image(mlx->ptr, path, &widgth, &widgth);
	if (!texture->img || texture->img == NULL)
		return (printf("Error\nInvalid path to texture\n"), free(texture), NULL);
	texture->addr = mlx_get_data_addr(texture->img,
			&texture->bits_per_pixel, &texture->line_length,
			&texture->endian);
	return (texture);
}

t_all	*init_textures(t_all *p)
{
	p->text_north = init_onetext(p->data->custompathnorth, p->mlx);
	if (p->text_north == NULL)
		return (closing_inter(p, 1, 1, 1), NULL);
	p->text_south = init_onetext(p->data->custompathsouth, p->mlx);
	if (p->text_south == NULL)
		return (closing_inter(p, 2, 1, 1), NULL);
	p->text_east = init_onetext(p->data->custompatheast, p->mlx);
	if (p->text_east == NULL)
		return (closing_inter(p, 3, 1, 1), NULL);
	p->text_west = init_onetext(p->data->custompathwest, p->mlx);
	if (p->text_west == NULL)
		return (closing_inter(p, 4, 1, 1), NULL);
	return (p);
}
