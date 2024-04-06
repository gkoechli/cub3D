/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduhau <gduhau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:04:48 by gkoechli          #+#    #+#             */
/*   Updated: 2023/02/16 12:37:28 by gduhau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	kill_error(t_data *data, int error_type, struct s_all *p)
{
	if (data->wall != NULL)
		wall_kill(data);
	if (error_type == ALLOC_ISSUE)
		printf("Error\nALLOC ISSUE\n");
	if (error_type == MAP_IS_INVALID)
		printf("Error\nMAP IS INVALID\n");
	if (error_type == DUPLICATE_PLAYER)
		printf("Error\nMORE THAN ONE PLAYER\n");
	if (error_type == NO_PLAYER)
		printf("Error\nTHERE IS NO PLAYER\n");
	if (error_type == COLOR_NOT_FOUND)
		printf("Error\nRBG VALUE INCORRECT\n");
	free_string_struct(data);
	if (p)
		free(p);
	exit(EXIT_FAILURE);
}

int	is_map_valid(t_data *data)
{
	int	j;
	int	i;
	int	col;

	col = 0;
	i = 0;
	j = 0;
	data->col_size = 0;
	while (data->map[i])
	{
		while (data->map[i] != '\n' && data->map[i])
		{
			i++;
			j++;
		}
		if (data->row_size == 0)
			data->row_size = j;
		if (data->row_max < j)
			data->row_max = j;
		i++;
		j = 0;
		col++;
	}
	data->col_size = col;
	return (0);
}

int	fill_grid(t_data *data, int elem, struct s_all *p)
{
	data->wall[data->pos.y][data->pos.x] = elem;
	if (elem > 3 && elem < 8)
	{
		data->player.x = data->pos.x;
		data->player.y = data->pos.y;
		data->player.ori = (elem -4) * 90;
		data->player_number += 1;
		data->wall[data->pos.y][data->pos.x] = 0;
	}
	if (data->player_number > 1)
		kill_error(data, DUPLICATE_PLAYER, p);
	return (0);
}

int	grid_gen(t_data *data, struct s_all *p)
{
	int	i;

	i = data->inc;
	while (data->map[i])
	{
		if (data->map[i] == '\n')
		{
				data->pos.x = 0;
				data->pos.y++;
				i++;
		}
		else
		{
			parse_letters(data, i, p);
			data->pos.x++;
			i++;
		}
	}
	return (0);
}

void	parse_letters(t_data *data, int i, struct s_all *p)
{
	if (data->map[i] == '1')
		fill_grid(data, 1, p);
	if (data->map[i] == '0')
		fill_grid(data, 0, p);
	if (data->map[i] == 'E')
		fill_grid(data, 4, p);
	if (data->map[i] == 'N')
		fill_grid(data, 5, p);
	if (data->map[i] == 'W')
		fill_grid(data, 6, p);
	if (data->map[i] == 'S')
		fill_grid(data, 7, p);
	if (data->map[i] == ' ')
		fill_grid(data, 3, p);
}
