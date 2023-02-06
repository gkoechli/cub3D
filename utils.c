/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:04:48 by gkoechli          #+#    #+#             */
/*   Updated: 2023/02/06 15:20:12 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_cpyber(const char *str, t_data *data)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	data->map = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (data->map == NULL)
		return ;
	while (str[i])
	{
		data->map[i] = str[i];
		i++;
	}
	data->map[i] = '\0';
	is_map_valid(data);
}

void	kill_error(t_data *data, int error_type)
{
	if (data->map != NULL)
		free(data->map);
	if (data->wall != NULL)
		wall_kill(data);
	if (error_type == NOT_WALLED)
		printf("Error\nMAP ISNT SURROUNDED BY WALLS\n");
	if (error_type == MAP_IS_INVALID)
		printf("Error\nMAP IS INVALID\n");
	if (error_type == DUPLICATE_PLAYER)
		printf("Error\nMORE THAN ONE PLAYER\n");
	if (error_type == NO_COLLECTIBLE)
		printf("Error\nTHERE IS NO COLLECTIBLE\n");
	if (error_type == NO_EXIT)
		printf("Error\nTHERE IS NO EXIT\n");
	if (error_type == NO_PLAYER)
		printf("Error\nTHERE IS NO PLAYER\n");
	free_string_struct(data);
	exit(EXIT_FAILURE);
}

int	is_map_valid(t_data *data)
{
	int	j;
	int	i;
	int col;

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
			data->row_max= j;
		i++;
		j = 0;
		col++;
	}
	data->col_size = col;
	printf("row max = %d\ncol max = %d\n", data->row_max, data->col_size);
	return (0);
}

void	check_params(t_data *data)
{
	if (data->player_number == 0)
		kill_error(data, NO_PLAYER);
	data->pos.x = 0;
	data->pos.y = 0;
}

void	str_glue(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	data->index = ft_strlen(data->temp.end);
	if (data->temp.solong != NULL)
		data->index += ft_strlen(data->temp.solong);
	str = malloc(sizeof(char) * data->index + 1);
	if (str == NULL)
		return ;
	if (data->temp.solong != NULL)
	{
		while (data->temp.solong[i])
		{
			str[i] = data->temp.solong[i];
			i++;
		}
		free(data->temp.solong);
	}
	data->index = -1;
	while (data->temp.end && data->temp.end[++data->index])
		str[i++] = data->temp.end[data->index];
	str[i] = '\0';
	data->temp.solong = ft_strdup(str);
	free(str);
}
