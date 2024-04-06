/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduhau <gduhau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:07:26 by gkoechli          #+#    #+#             */
/*   Updated: 2023/02/16 12:20:26 by gduhau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_read(t_data *data, struct s_all *p)
{
	int	i;

	i = 0;
	check_first_part(data, p);
	i += data->inc;
	while (data->map[i] && (data->map[i] == ' '
			|| data->map[i] == '\t' || data->map[i] == '\n'))
	{
		data->inc++;
		i++;
	}
	while (data->temp.solong[i])
	{
		if (data->temp.solong[i] != '1' && data->temp.solong[i] != '0'
			&& data->temp.solong[i] != 'N' && data->temp.solong[i] != ' '
			&& data->temp.solong[i] != 'S' && data->temp.solong[i] != 'W'
			&& data->temp.solong[i] != 'E' && data->temp.solong[i] != '\n')
			kill_error(data, MAP_IS_INVALID, p);
		i++;
	}
	if (i < 9)
		kill_error(data, MAP_IS_INVALID, p);
	return (0);
}

int	check_borders(t_data *data, struct s_all *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (data->wall == NULL)
		kill_error(data, MAP_IS_INVALID, p);
	while (j < data->col_size)
	{
		while (i < data->row_max)
		{
			if (data->wall[j][i] == 0)
			{
				if (check_around_ground(data, i, j) == -1)
					kill_error(data, MAP_IS_INVALID, p);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	check_correct_parsing_line(t_data *data, int i, struct s_all *p)
{
	if (data->map[i] && data->stop > 0)
	{
		i += ft_skip_blanks(data, i);
		if (data->map[i] && data->map[i] == 'N'
			&& data->map[i + 1] == 'O' && data->north == 0)
			return (texture_parse(data, i, N, p));
		else if (data->map[i] && data->map[i] == 'S'
			&& data->map[i + 1] == 'O' && data->south == 0)
			return (texture_parse(data, i, S, p));
		else if (data->map[i] && data->map[i] == 'W'
			&& data->map[i + 1] == 'E' && data->west == 0)
			return (texture_parse(data, i, O, p));
		else if (data->map[i] && data->map[i] == 'E'
			&& data->map[i + 1] == 'A' && data->east == 0)
			return (texture_parse(data, i, E, p));
		else if (data->map[i] && data->map[i] == 'C'
			&& data->map[i + 1] == ' ' && data->c == 0)
			return (color_parse('C', data, i, p));
		else if (data->map[i] && data->map[i] == 'F'
			&& data->map[i + 1] == ' ' && data->f == 0)
			return (color_parse('F', data, i, p));
		else
			return (1);
	}
	return (0);
}

int	check_first_part(t_data *data, struct s_all *p)
{
	int	i;

	i = 0;
	data->stop = 6;
	while (data->map[i] && data->stop > 0)
	{
		data->inc = 0;
		if (check_correct_parsing_line(data, i, p) == 1)
			kill_error(data, MAP_IS_INVALID, p);
		i += data->inc;
	}
	if (data->stop > 0)
		kill_error(data, MAP_IS_INVALID, p);
	data->inc = i;
	return (0);
}

void	check_rgb_string(t_data *data, char *str, struct s_all *p)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		if (str[i] == ',' && (i == 0 || (str[i + 1] < '0' || str[i + 1] > '9')))
		{
			free(str);
			kill_error(data, COLOR_NOT_FOUND, p);
		}
		i++;
	}
	if (count != 2)
	{
		free(str);
		kill_error(data, COLOR_NOT_FOUND, p);
	}
}
