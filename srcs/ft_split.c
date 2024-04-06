/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduhau <gduhau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:14:22 by gduhau            #+#    #+#             */
/*   Updated: 2023/02/16 11:05:41 by gduhau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	count_words(char const *str, char c)
{
	int	i;
	int	compteur;

	i = 0;
	compteur = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != c && str[i] != '\0')
			compteur++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (compteur);
}

static int	words_length(char const *str, int i, char c)
{
	int	compteur;

	compteur = 0;
	while (str[i] == c && str[i] != '\0')
		i++;
	while (str[i] != c && str[i++] != '\0')
		compteur++;
	return (compteur);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	int		a;
	int		i;
	int		d;

	i = 0;
	a = 0;
	tab = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!(tab))
		return (0);
	while (a < count_words(s, c) && s[i] != '\0')
	{
		tab[a] = malloc((words_length(s, i, c) + 1) * sizeof(char));
		if (!(tab[a]))
			return (free_tab(tab), (char **)0);
		d = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			tab[a][d++] = s[i++];
		tab[a][d] = '\0';
		a++;
	}
	tab[a] = 0;
	return (tab);
}
