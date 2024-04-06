/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduhau <gduhau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:52:55 by gduhau            #+#    #+#             */
/*   Updated: 2023/02/16 11:16:33 by gduhau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	close_program(t_all *p, int mode)
{
	mlx_destroy_image(p->mlx->ptr, p->picture->img);
	free(p->picture);
	mlx_destroy_image(p->mlx->ptr, p->text_east->img);
	free(p->text_east);
	mlx_destroy_image(p->mlx->ptr, p->text_south->img);
	free(p->text_south);
	mlx_destroy_image(p->mlx->ptr, p->text_north->img);
	free(p->text_north);
	mlx_destroy_image(p->mlx->ptr, p->text_west->img);
	free(p->text_west);
	mlx_destroy_window(p->mlx->ptr, p->mlx->win);
	mlx_destroy_display(p->mlx->ptr);
	free(p->mlx->ptr);
	free(p->mlx);
	exit_hook(p->data, 0);
	free(p);
	exit(mode);
}

static void	destroying_img(t_win *mlx, t_img *picture)
{
	mlx_destroy_image(mlx->ptr, picture->img);
	free(picture);
}

void	closing_inter(t_all *p, int opt, int mode, int flag)
{
	if (flag == 1)
		destroying_img(p->mlx, p->picture);
	if (opt > 1)
		destroying_img(p->mlx, p->text_north);
	if (opt > 2)
		destroying_img(p->mlx, p->text_south);
	if (opt > 3)
		destroying_img(p->mlx, p->text_east);
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
