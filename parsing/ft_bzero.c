/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduhau <gduhau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:28:29 by gkoechli          #+#    #+#             */
/*   Updated: 2023/02/09 14:41:52 by gduhau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void	ft_bzero(void *s, size_t n)
// {
// 	char	*s2;

// 	s2 = s;
// 	while (n-- > 0)
// 		*s2++ = '\0';
// }

static char	*ft_strstr2(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j] && haystack[i + j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char*)&haystack[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}

int check_extension(const char *str)
{
	int i;

	i = ft_strlen(str);
	if (i == 0)
		return 1;
	if (!ft_strstr2(&str[i - 5], ".cub"))
		return 1;
	return 0;
}

