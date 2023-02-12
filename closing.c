/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatsby <gatsby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:52:55 by gduhau            #+#    #+#             */
/*   Updated: 2023/02/10 20:33:39 by gatsby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	close_program(t_all *p, int mode)
{
	//free_tab(vars->p->tab);
	//free(vars->p);
	//ft_lstclear(vars->field, vars->mlx);
	//free(p->perso);
	//free_tab(p->tab);
	//int i = 0;
	// while (i < LARGEUR)
	// {
	// 	printf("%d\n", i);
	// 	if (p->picture[i]->img != NULL)
	// 	{
	// 		mlx_destroy_image(p->mlx->ptr, p->picture[i]->img);
	// 		//free(p->picture[i]->addr);
	// 	}
	// 	// free(p->picture[i]->addr);
	// 	// free(p->picture[i]->img);
	// 	free(p->picture[i]);
	// 	i++;
	// }
	mlx_destroy_image(p->mlx->ptr, p->picture->img);
	free(p->picture);
	mlx_destroy_image(p->mlx->ptr, p->text_east->img); //proteger ?
	free(p->text_east);
	mlx_destroy_image(p->mlx->ptr, p->text_south->img);
	free(p->text_south);
	mlx_destroy_image(p->mlx->ptr, p->text_north->img);
	free(p->text_north);
	mlx_destroy_image(p->mlx->ptr, p->text_west->img);
	free(p->text_west);
	//mlx_destroy_image(p->mlx->ptr, p->background);
	//free(p->background);
	mlx_destroy_window(p->mlx->ptr, p->mlx->win);
	mlx_destroy_display(p->mlx->ptr);
	free(p->mlx->ptr);
	free(p->mlx);
	exit_hook(p->data, 0);
	free(p);
	exit(mode);
}

int	close_hook(t_all *vars)
{
	close_program(vars, 0);
	return (0);
}