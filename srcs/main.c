/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:15:20 by gatsby            #+#    #+#             */
/*   Updated: 2023/02/16 13:57:11 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	image_generator(int reg, int **tab, t_all *p)
{
	t_norm	no;
	double	angle;
	int		min;

	no.ray = 0;
	no.reg = mod(reg);
	angle = mod(no.reg + (double) FOV / 2);
	min = ((int)angle / 90) * 90;
	while (no.ray < LARGEUR && angle > min)
	{
		first_part(angle, tab, p, no);
		no.ray++;
		angle = iter_ang(no.ray, no.reg, angle);
	}
	if (no.ray == LARGEUR)
	{
		mlx_put_image_to_window(p->mlx->ptr, p->mlx->win,
			p->picture->img, 0, 0);
		return ;
	}
	second_part(no, tab, p, angle);
}

void	second_part2(t_norm no, int **tab, t_all *p, double angle)
{
	if (angle <= no.reg && angle >= 0 && angle < 90)
		scase0(angle, tab, p, no.ray);
	else if (angle <= no.reg && angle < 180 && angle > 90)
		scase90(angle, tab, p, no.ray);
	else if (angle <= no.reg && angle <= 360 && angle > 270)
		scase270(angle, tab, p, no.ray);
	else if (angle <= no.reg && angle < 270 && angle > 180)
		scase180(angle, tab, p, no.ray);
	else if (angle > no.reg && angle > 270 && angle < 360)
		fcase270(angle, tab, p, no.ray);
	else if (angle > no.reg && angle > 0 && angle < 90)
		fcase0(angle, tab, p, no.ray);
	else if (angle > no.reg && angle > 180 && angle < 270)
		fcase180(angle, tab, p, no.ray);
	else if (angle > no.reg && angle > 90 && angle < 180)
		fcase90(angle, tab, p, no.ray);
}

void	second_part(t_norm no, int **tab, t_all *p, double angle)
{
	while (no.ray < LARGEUR)
	{
		if (angle == no.reg && angle == 90)
			color_spe90(p, tab, no.ray, p->text_north);
		else if (angle == no.reg && angle == 270)
			color_spe270(p, tab, no.ray, p->text_south);
		else if (angle == no.reg && angle == 180)
			color_spe180(p, tab, no.ray, p->text_east);
		else
			second_part2(no, tab, p, angle);
		no.ray++;
		angle = iter_ang(no.ray, no.reg, angle);
	}
	mlx_put_image_to_window(p->mlx->ptr, p->mlx->win, p->picture->img, 0, 0);
}

int	suite_main(t_all *p)
{
	p->perso->x += 0.5;
	p->perso->y += 0.5;
	p->mlx = malloc(sizeof(t_win));
	if (!p->mlx)
		return (perror("Error\n"), 0);
	p->mlx->ptr = mlx_init();
	if (!p->mlx->ptr)
		return (free(p->mlx), perror("Error\n"), 1);
	p->mlx->win = mlx_new_window(p->mlx->ptr, LARGEUR, HAUTEUR, "cub3d");
	if (!p->mlx->win)
		return (mlx_destroy_display(p->mlx), free(p->mlx->ptr),
			free(p->mlx), exit_hook(p->data, 0), free(p), 1);
	p->picture = init_image(p->mlx);
	if (!p->picture || p->picture == NULL)
		return (closing_inter(p, 0, 1, 0), 1);
	p = init_textures(p);
	if (p == NULL)
		return (1);
	image_generator(p->perso->ori, p->data->wall, p);
	mlx_key_hook(p->mlx->win, key_hook, p);
	mlx_hook(p->mlx->win, ONDESTROY, 1L << 19, close_hook, p);
	return (mlx_loop(p->mlx->ptr), 0);
}

int	main(int argc, char *argv[])
{
	t_all	*p;
	int		fd;
	t_data	data;

	p = malloc(sizeof(t_all));
	if (!p)
		return (0);
	p->i = 1;
	if (check_param(argc) == 1 || check_extension(argv[1]))
		return (free (p), 1);
	ft_bzero(&data, sizeof(data));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (free(p), printf("Error\n%s\n", strerror(errno)));
	while (p->i > 0)
	{
		if (data.temp.buff)
			free(data.temp.buff);
		p->i = get_next_line(fd, &data);
		str_glue(&data);
		str_add(&data, '\n');
	}
	if (close(fd) == -1 || p->i == -1)
		kill_error(&data, MAP_IS_INVALID, p);
	return (p->perso = cube(&data, p), p->data = &data, suite_main(p));
}

//mlx_hook(p->mlx->win, 2, 1L<<0, key_hook, p);
