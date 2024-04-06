/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:23:44 by gkoechli          #+#    #+#             */
/*   Updated: 2023/02/16 14:39:22 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_line(char *str)
{
	int	i;

	i = 1;
	if (!str)
		return (0);
	while (str && str[i - 1] != '\0')
	{
		if (str[i - 1] == '\n')
			return (i);
		i++;
	}
	if (i == (int)ft_strlen(str))
		return (i);
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

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
