/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:29:12 by gkoechli          #+#    #+#             */
/*   Updated: 2023/02/16 13:57:51 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*ft_strstr2(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j] && haystack[i + j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_extension(const char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i == 0)
		return (printf("Error\nWrong file type\n"), 1);
	if (!ft_strstr2(&str[i - 5], ".cub"))
		return (printf("Error\nWrong file type\n"), 1);
	return (0);
}

void	ft_color_valid(t_data *data, struct s_all *p)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (data->f_tab[i] < 0 || data->f_tab[i] > 255)
			kill_error(data, COLOR_NOT_FOUND, p);
		if (data->c_tab[i] < 0 || data->c_tab[i] > 255)
			kill_error(data, COLOR_NOT_FOUND, p);
		i++;
	}
}

void	fill_rgb(t_data *data, char **atmp, char c)
{
	if (c == 'F')
	{	
		data->f_tab[0] = ft_atoi(atmp[0]);
		data->f_tab[1] = ft_atoi(atmp[1]);
		data->f_tab[2] = ft_atoi(atmp[2]);
		data->f = 1;
		data->stop--;
	}
	if (c == 'C')
	{	
		data->c_tab[0] = ft_atoi(atmp[0]);
		data->c_tab[1] = ft_atoi(atmp[1]);
		data->c_tab[2] = ft_atoi(atmp[2]);
		data->c = 1;
		data->stop--;
	}
}

int	ft_skip_blanks(t_data *data, int i)
{
	int	count;

	count = 0;
	while (data->map[i] && (data->map[i] == '\n'
			|| data->map[i] == ' ' || data->map[i] == '\t'))
	{
		data->inc++;
		i++;
		count++;
	}
	return (count);
}
