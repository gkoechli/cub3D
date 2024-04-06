/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduhau <gduhau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:04:22 by gduhau            #+#    #+#             */
/*   Updated: 2023/02/16 12:47:42 by gduhau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	destroy_img(t_all *p)
{
	mlx_destroy_image(p->mlx->ptr, p->picture->img);
}

int	hit_check(t_all *p, double x, double y)
{
	if (p->data->wall[(int)floor(p->perso->y + y)]
		[(int)floor(p->perso->x + x)] != 1)
	{
		if (floor(p->perso->x) != floor(p->perso->x + x)
			|| floor(p->perso->y) != floor(p->perso->y + y))
		{
			if (p->data->wall[(int)floor(p->perso->y + y)]
				[(int)floor(p->perso->x)] == 1
				|| p->data->wall[(int)floor(p->perso->y)]
				[(int)floor(p->perso->x + x)] == 1)
				return (0);
		}
		return (1);
	}
	return (0);
}

void	moving(t_all *p, double x, double y)
{
	destroy_img(p);
	free(p->picture);
	p->picture = init_image(p->mlx);
	if (!p->picture || p->picture == NULL)
		closing_inter(p, 4, 1, 0);
	p->perso->x = x;
	p->perso->y = y;
}

int	special_incr(int nb)
{
	if (nb > 0)
		return (--nb);
	return (nb);
}

void	arrow_right(t_all *p)
{
	destroy_img(p);
	free(p->picture);
	p->picture = init_image(p->mlx);
	if (!p->picture || p->picture == NULL)
		closing_inter(p, 4, 1, 0);
	p->perso->ori -= CM;
	image_generator(p->perso->ori, p->data->wall, p);
}
