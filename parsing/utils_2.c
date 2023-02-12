/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:21:10 by gkoechli          #+#    #+#             */
/*   Updated: 2023/02/12 17:06:44 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	str_add(t_data *data, char c)
{
	int		i;
	char	*s;

	s = NULL;
	i = 0;
	s = malloc(sizeof(char) * ft_strlen(data->temp.solong) + 2);
	if (s == NULL)
		return ;
	while (data->temp.solong[i])
	{
		s[i] = data->temp.solong[i];
		i++;
	}
	s[i] = c;
	s[i + 1] = '\0';
	free(data->temp.solong);
	data->temp.solong = ft_strdup(s);
	free(s);
}

int pathlen(t_data *data, int i)
{
	int c;

	c = 0;
	while (data->map[i] && data->map[i] != '\n' &&  data->map[i] != ' ' &&  data->map[i] != '\t')
	{
		i++;
		c++;
	}
	return (c);
}

int	texture_parse(char **str, t_data *data, int i, int X)
{
			if (X == NO)
				data->NO = 1;
			if (X == SO)
				data->SO = 1;
			if (X == WE)
				data->WE = 1;
			if (X == EA)
				data->EA = 1;
			i += 2;
			while (data->map[i] &&  (data->map[i] == ' ' ||  data->map[i] == '\t'))
				i++;
			*str = malloc(sizeof(char) * (pathlen(data, i) + 1));
			if (str == NULL)
				kill_error(ALLOC_ISSUE);
			while (data->map[i] && data->map[i] != '\n' &&  data->map[i] != ' ' &&  data->map[i] != '\t')
			{
				*str[c] = data->map[i];
				i++;
				c++;
			}
			data->stop--;
			*str[c] = '\0';
			data->inc += i;
			return (0)
}


int check_correct_parsing_line(t_data *data, int i)
{
	while (data->map[i] && data->stop > 0)
	{
		while (data->map[i] && (data->map[i] == '\n' ||  data->map[i] != ' ' ||  data->map[i] != '\t'))
		{
				data->inc ++;
				i++;
		}
		if (data->map[i] && data[i] == 'N' && data[i + 1] == 'O' && data->NO == 0)
			return (texture_parse(&data->custompathnorth, data, i, NO));
		else if (data->map[i] && data[i] == 'S' && data[i + 1] == 'O' && data->SO == 0)
			return (texture_parse(&data->custompathsouth, data, i, SO));
		else if (data->map[i] && data[i] == 'W' && data[i + 1] == 'E' && data->WE == 0)
			return (texture_parse(&data->custompathwest, data, i, WE));
		else if (data->map[i] && data[i] == 'E' && data[i + 1] == 'A' && data->EA == 0)
			return (texture_parse(&data->custompatheast, data, i, EA));
		else if (data->map[i] && data[i] == 'C' && data[i + 1] != ' ' && data->C == 0)
			return (color_parse('C', data, C, i));
		else if (data->map[i] && data[i] == 'F' && data[i + 1] != ' ' && data->F == 0)
			return (color_parse('F', data, F, i));
		else 
			return (1)
	}
}

int	check_first_part(t_data *data)
{
	int i;

	i = 0;
	data->stop = 6;
	while (data->map[i] && data->stop > 0)
	{
			data->inc = 0;
			if (!check_correct_parsing_line(data, i))
				kill_error(MAP_IS_INVALID);
			i += data->inc;
	}
	if (data->stop > 0)
		kill_error(MAP_IS_INVALID);
	data->inc = i;
	return (0);
}

int	colorgen(char c, t_data *data, int X,  int i)
	{
		data->inc = 0;
		i++;
		while (data->map[i] && (data->map[i] == ' ' || data->map[i] == '\t'))
			i++;
			
		data->inc += i;
		data->stop--;
		return (0);
	}


int	map_read(t_data *data)
{
	int	i;

	i = 0;
	check_first_part(data);
	i += data->inc;
	while (data->temp.solong[i])
	{
		if (data->temp.solong[i] != '1' && data->temp.solong[i] != '0'
			&& data->temp.solong[i] != 'N' && data->temp.solong[i] != ' '
			&& data->temp.solong[i] != 'S' && data->temp.solong[i] != 'W'
			&& data->temp.solong[i] != 'E' && data->temp.solong[i] != '\n')
			kill_error(data, MAP_IS_INVALID);
		i++;
	}
	if (i < 9)
		kill_error(data, MAP_IS_INVALID);
	return (0);
}

void	free_string_struct(t_data *data)
{
	if (data->temp.tmp != NULL)
		free(data->temp.tmp);
	if (data->temp.buff != NULL)
		free(data->temp.buff);
	if (data->temp.end != NULL)
		free(data->temp.end);
	if (data->temp.solong != NULL)
		free(data->temp.solong);
	if (data->custompathnorth != NULL)
		free(data->custompathnorth);
	if (data->custompathsouth != NULL)
		free(data->custompathsouth);
	if (data->custompathwest != NULL)
		free(data->custompathwest);
	if (data->custompatheast != NULL)
		free(data->custompatheast);
	free_string_struct_2(data);
}

void	free_string_struct_2(t_data *data)
{
	if (data->custompathnorth != NULL)
		free(data->custompathnorth);
	if (data->custompathsouth != NULL)
		free(data->custompathsouth);
	if (data->custompathwest != NULL)
		free(data->custompathwest);
	if (data->custompatheast != NULL)
		free(data->custompatheast);
}

int	wall_gen(t_data *data)
{
	int	i;
	int y;

	i = 0;
	y = 0;
	data->wall = (int **)malloc(sizeof(int *) * data->col_size);
	while (y < data->col_size)
	{
		data->wall[y] = malloc(sizeof(int *) * data->row_max);
		y++;
	}
	y= 0;
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
	return (0);
}

int	wall_kill(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->row_max)
	{
		free(data->wall[i]);
		i++;
	}
	free(data->wall);
	return (0);
}
