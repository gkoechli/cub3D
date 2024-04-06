/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduhau <gduhau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:21:34 by gduhau            #+#    #+#             */
/*   Updated: 2023/02/16 11:09:21 by gduhau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	md(double angle, double ret)
{
	if (angle > 0 && angle < 90 && ret < 360 && ret > 270)
		return (md(angle + 360, ret));
	else if (ret > 0 && ret < 90 && angle > 270 && angle < 360)
	{
		return (md(angle, ret + 360));
	}
	else
	{
		if (angle > ret)
			return (mod(angle - ret));
		else
			return (mod(ret - angle));
	}
	return (0);
}

double	mod(double nb)
{
	if (nb < 0)
		return (mod(nb + 360));
	else if (nb >= 360)
		return (mod(nb - 360));
	return (nb);
}

int	create_trgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [3]){b, g, r});
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
