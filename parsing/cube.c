/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:24:34 by gkoechli          #+#    #+#             */
/*   Updated: 2023/02/16 13:55:43 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	replace_gap_after_parse(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < data->col_size)
	{
		while (i < data->row_max)
		{
			if (data->wall[j][i] == 2 || data->wall[j][i] == 3)
				data->wall[j][i] = 1;
			i++;
		}
		i = 0;
		j++;
	}
}

t_point	*cube(t_data *data, struct s_all *p)
{
	ft_cpyber(data->temp.solong, data);
	if (data->map == NULL)
		kill_error(data, ALLOC_ISSUE, p);
	map_read(data, p);
	if (wall_gen(data) == 1)
		kill_error(data, ALLOC_ISSUE, p);
	grid_gen(data, p);
	check_borders(data, p);
	replace_gap_after_parse(data);
	if (data->player_number == 0)
		kill_error(data, NO_PLAYER, p);
	return (&data->player);
}

void	fill_blanks(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (y < data->col_size)
	{
		while (i < data->row_max)
		{
			data->wall[y][i] = 2;
			i++;
		}
		i = 0;
		y++;
	}
	return ;
}
