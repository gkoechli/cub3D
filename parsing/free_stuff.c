/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:26:36 by gkoechli          #+#    #+#             */
/*   Updated: 2023/02/15 09:34:46 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	exit_hook(t_data *data, int flag)
{
	wall_kill(data);
	free_string_struct(data);
	if (flag == 1)
		exit(EXIT_FAILURE);
	return (0);
}

char	*ft_strdup_tweaked(t_data *data, int i)
{
	int		count;
	int		y;
	char	*ret;

	count = 0;
	y = 0;
	if (!data->map)
		return (NULL);
	while (data->map[i + count] && data->map[i + count] != ' '
		&& data->map[i + count] != '\t' && data->map[i + count] != '\n')
		count++;
	ret = malloc(sizeof(char) * (count + 1));
	if (ret == NULL)
		return (NULL);
	while (y < count)
	{
		ret[y] = data->map[i + y];
		y++;
	}
	ret[y] = '\0';
	return (ret);
}

void	free_tab_custom(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		free (tmp[i]);
		i++;
	}
	free (tmp);
}

void	free_string_struct(t_data *data)
{
	if (data->map != NULL)
		free(data->map);
	if (data->temp.tmp != NULL)
		free(data->temp.tmp);
	if (data->temp.buff != NULL)
		free(data->temp.buff);
	if (data->temp.end != NULL)
		free(data->temp.end);
	if (data->temp.solong != NULL)
		free(data->temp.solong);
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
