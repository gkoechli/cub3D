/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:21:10 by gkoechli          #+#    #+#             */
/*   Updated: 2023/02/15 18:28:52 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	pathlen(t_data *data, int i)
{
	int	c;

	c = 0;
	while (data->map[i] && data->map[i] != '\n'
		&& data->map[i] != ' ' && data->map[i] != '\t')
	{
		i++;
		c++;
	}
	return (c);
}

int	texture_parse(t_data *data, int i, int X, struct s_all *p)
{
	int	c;

	c = 0;
	if (X == N)
		return (parse_north_texture(data, i, c, p));
	if (X == S)
		return (parse_south_texture(data, i, c, p));
	if (X == O)
		return (parse_west_texture(data, i, c, p));
	if (X == E)
		return (parse_east_texture(data, i, c, p));
	return (1);
}

int	color_parse(char c, t_data *data, int i, struct s_all *p)
{
	char	*tmp;
	char	**atmp;

	if (c == 'C')
		data->c = 1;
	if (c == 'F')
		data->f = 1;
	i += 1;
	data->inc += 1;
	while (data->map[i] && (data->map[i] == ' ' || data->map[i] == '\t'))
	{
		i++;
		data->inc++;
	}
	tmp = ft_strdup_tweaked(data, i);
	check_rgb_string(data, tmp, p);
	data->inc += ft_strlen(tmp);
	atmp = ft_split(tmp, ',');
	free (tmp);
	fill_rgb(data, atmp, c);
	free_tab_custom(atmp);
	ft_color_valid(data, p);
	return (0);
}

int	wall_gen(t_data *data)
{
	int	y;

	y = 0;
	data->wall = (int **)malloc(sizeof(int *) * data->col_size);
	if (data->wall == NULL)
		return (1);
	while (y < data->col_size)
	{
		data->wall[y] = NULL;
		data->wall[y] = malloc(sizeof(int *) * data->row_max);
		if (data->wall[y] == NULL)
			return (1);
		y++;
	}
	fill_blanks(data);
	return (0);
}

int	wall_kill(t_data *data)
{
	int	i;

	i = 0;
	if (data->wall == NULL)
		return (1);
	while (i < data->col_size && data->wall[i] != NULL)
	{
		free(data->wall[i]);
		i++;
	}
	free(data->wall);
	return (0);
}
