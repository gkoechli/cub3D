/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:43:02 by gkoechli          #+#    #+#             */
/*   Updated: 2023/02/15 12:11:39 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_around_ground(t_data *data, int i, int j)
{
	if (i == 0 || j == 0 || i == data->row_max - 1 || j == data->col_size - 1)
		return (-1);
	if (data->wall[j][i + 1] != 1 && data->wall[j][i + 1] != 0)
		return (-1);
	if (data->wall[j + 1][i] != 1 && data->wall[j + 1][i] != 0)
		return (-1);
	if (data->wall[j - 1][i] != 1 && data->wall[j - 1][i] != 0)
		return (-1);
	if (data->wall[j][i - 1] != 1 && data->wall[j][i - 1] != 0)
		return (-1);
	return (0);
}

int	parse_north_texture(t_data *data, int i, int c, struct s_all *p)
{
	int	len;

	data->north = 1;
	i += 2;
	data->inc += 2;
	while (data->map[i] && (data->map[i] == ' ' || data->map[i] == '\t'))
	{
		i++;
		data->inc ++;
	}
	len = pathlen(data, i);
	data->custompathnorth = malloc(sizeof(char) * (pathlen(data, i) + 1));
	if (data->custompathnorth == NULL)
		kill_error(data, ALLOC_ISSUE, p);
	while (data->map[i] && c < len)
	{
		data->custompathnorth[c] = data->map[i];
		i++;
		c++;
		data->inc++;
	}
	data->stop--;
	data->custompathnorth[c] = '\0';
	return (0);
}

int	parse_south_texture(t_data *data, int i, int c, struct s_all *p)
{
	int	len;

	data->south = 1;
	i += 2;
	data->inc += 2;
	while (data->map[i] && (data->map[i] == ' ' || data->map[i] == '\t'))
	{
		i++;
		data->inc ++;
	}
	len = pathlen(data, i);
	data->custompathsouth = malloc(sizeof(char) * (pathlen(data, i) + 1));
	if (data->custompathsouth == NULL)
		kill_error(data, ALLOC_ISSUE, p);
	while (data->map[i] && c < len)
	{
		data->custompathsouth[c] = data->map[i];
		i++;
		c++;
		data->inc++;
	}
	data->stop--;
	data->custompathsouth[c] = '\0';
	return (0);
}

int	parse_west_texture(t_data *data, int i, int c, struct s_all *p)
{
	int	len;

	data->west = 1;
	i += 2;
	data->inc += 2;
	while (data->map[i] && (data->map[i] == ' ' || data->map[i] == '\t'))
	{
		i++;
		data->inc ++;
	}
	len = pathlen(data, i);
	data->custompathwest = malloc(sizeof(char) * (pathlen(data, i) + 1));
	if (data->custompathwest == NULL)
		kill_error(data, ALLOC_ISSUE, p);
	while (data->map[i] && c < len)
	{
		data->custompathwest[c] = data->map[i];
		i++;
		c++;
		data->inc++;
	}
	data->stop--;
	data->custompathwest[c] = '\0';
	return (0);
}

int	parse_east_texture(t_data *data, int i, int c, struct s_all *p)
{
	int	len;

	data->east = 1;
	i += 2;
	data->inc += 2;
	while (data->map[i] && (data->map[i] == ' ' || data->map[i] == '\t'))
	{
		i++;
		data->inc ++;
	}
	len = pathlen(data, i);
	data->custompatheast = malloc(sizeof(char) * (pathlen(data, i) + 1));
	if (data->custompatheast == NULL)
		kill_error(data, ALLOC_ISSUE, p);
	while (data->map[i] && c < len)
	{
		data->custompatheast[c] = data->map[i];
		i++;
		c++;
		data->inc++;
	}
	data->stop--;
	data->custompatheast[c] = '\0';
	return (0);
}
