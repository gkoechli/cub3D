/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:23:44 by gkoechli          #+#    #+#             */
/*   Updated: 2022/07/25 16:33:29 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
