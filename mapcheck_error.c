/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:07:26 by gkoechli          #+#    #+#             */
/*   Updated: 2023/02/06 16:18:58 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_map(t_data *data)
{
	int	i;
	int	u;

	i = 0;
	u = data->win_width * data->win_height / data->col_size / data->row_size;
	while (i < u)
	{
		parse(data);
		if (data->pos.x < data->row_size - 1)
			data->pos.x += 1;
		else
		{
			if (data->pos.y < data->col_size - 1)
			{
				data->pos.y += 1;
				data->pos.x = 0;
			}
		}
		i++;
	}
	data->pos.x = 0;
	data->pos.y = 0;
	return (0);
}

int	check_borders(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (data->wall == NULL)
		kill_error(data, MAP_IS_INVALID);
	while (i < data->row_max)
	{
		while (j < data->col_size)
		{
			if (data->wall[i][j] == 0)
			{
				if (check_around_ground(data, i, j) == -1)
					kill_error(data, MAP_IS_INVALID);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	fill_grid(t_data *data, int elem)
{
	data->wall[data->pos.x][data->pos.y] = elem;
	if (elem > 3 && elem < 8)
	{
		data->player.x = data->pos.x;
		data->player.y = data->pos.y;
		data->player.orientation =  (elem -4) * 90;
		printf("player pos : [%d][%d] orientation [%d]\n", data->player.x, data->player.y, data->player.orientation);
		data->player_number += 1;
		data->wall[data->pos.x][data->pos.y] = 0;
	}
	if (data->player_number > 1)
		kill_error(data, DUPLICATE_PLAYER);
	return (0);
}

int	grid_gen(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (data->map[i] == '\n')
		{
			data->pos.x = 0;
			data->pos.y++;
			i++;
		}
		if (data->map[i] == '1')
			fill_grid(data, 1);
		if (data->map[i] == '0')
			fill_grid(data, 0);
		if (data->map[i] == 'N')
			fill_grid(data, 4);
		if (data->map[i] == 'W')
			fill_grid(data, 5);
		if (data->map[i] == 'S')
			fill_grid(data, 6);
		if (data->map[i] == 'E')
			fill_grid(data, 7);
		if (data->map[i] == ' ')
			fill_grid(data, 2);
		data->pos.x++;
		i++;
	}
	return (0);
}

int	parse(t_data *data)
{
	if (data->rend.image != NULL)
		free(data->rend.image);
	if (data->rend.path != NULL)
		free(data->rend.path);
	if (data->wall[data->pos.x][data->pos.y] == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->walls.image, data->pos.x * 64, data->pos.y * 64);
	if (data->wall[data->pos.x][data->pos.y] == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->ground.image, data->pos.x * 64, data->pos.y * 64);
	return (0);
}
