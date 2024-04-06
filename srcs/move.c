/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduhau <gduhau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:11:43 by gatsby            #+#    #+#             */
/*   Updated: 2023/02/16 12:36:50 by gduhau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	front_move(t_all *p)
{
	p->perso->ori = mod(p->perso->ori);
	if (p->perso->ori <= 90 && p->perso->ori >= 0
		&& hit_check(p, DM * cos(p->perso->ori * M_PI / 180),
			-DM * sin(p->perso->ori * M_PI / 180)) == 1)
		moving(p, p->perso->x + DM * cos(p->perso->ori * M_PI / 180),
			p->perso->y - DM * sin(p->perso->ori * M_PI / 180));
	else if (p->perso->ori >= 90 && p->perso->ori <= 180
		&& hit_check(p, -DM * cos((180 - p->perso->ori) * M_PI / 180),
			-DM * sin((180 - p->perso->ori) * M_PI / 180)) == 1)
		moving(p, p->perso->x - DM * cos((180 - p->perso->ori) * M_PI / Z),
			p->perso->y - DM * sin((180 - p->perso->ori) * M_PI / 180));
	else if (p->perso->ori >= 180 && p->perso->ori <= 270
		&& hit_check(p, -DM * cos((p->perso->ori - 180) * M_PI / 180),
			DM * sin((p->perso->ori - 180) * M_PI / 180)) == 1)
		moving(p, p->perso->x - DM * cos((p->perso->ori - 180) * M_PI / Z),
			p->perso->y + DM * sin((p->perso->ori - 180) * M_PI / 180));
	else if (p->perso->ori >= 270 && p->perso->ori <= 360
		&& hit_check(p, DM * cos(mod(360 - p->perso->ori) * M_PI / 180),
			DM * sin(mod(360 - p->perso->ori) * M_PI / 180)) == 1)
		moving(p, p->perso->x + DM * cos(mod(360 - p->perso->ori) * M_PI / Z),
			p->perso->y + DM * sin(mod(360 - p->perso->ori) * M_PI / Z));
	image_generator(p->perso->ori, p->data->wall, p);
}

void	back_move(t_all *p)
{
	p->perso->ori = mod(p->perso->ori);
	if (p->perso->ori <= 90 && p->perso->ori >= 0
		&& hit_check(p, -DM * cos(p->perso->ori * M_PI / 180),
			DM * sin(p->perso->ori * M_PI / 180)) == 1)
		moving(p, p->perso->x - DM * cos(p->perso->ori * M_PI / 180),
			p->perso->y + DM * sin(p->perso->ori * M_PI / 180));
	else if (p->perso->ori >= 90 && p->perso->ori <= 180
		&& hit_check(p, DM * cos((180 - p->perso->ori) * M_PI / 180),
			DM * sin((180 - p->perso->ori) * M_PI / 180)) == 1)
		moving(p, p->perso->x + DM * cos((180 - p->perso->ori) * M_PI / Z),
			p->perso->y + DM * sin((180 - p->perso->ori) * M_PI / Z));
	else if (p->perso->ori >= 180 && p->perso->ori <= 270
		&& hit_check(p, DM * cos((p->perso->ori - 180) * M_PI / 180),
			-DM * sin((p->perso->ori - 180) * M_PI / 180)) == 1)
		moving(p, p->perso->x + DM * cos((p->perso->ori - Z) * M_PI / Z),
			p->perso->y - DM * sin((p->perso->ori - Z) * M_PI / Z));
	else if (p->perso->ori >= 270 && p->perso->ori <= 360
		&& hit_check(p, -DM * cos(mod(360 - p->perso->ori) * M_PI / Z),
			-DM * sin(mod(360 - p->perso->ori) * M_PI / 180)) == 1)
		moving(p, p->perso->x - DM * cos(mod(360 - p->perso->ori) * M_PI / Z),
			p->perso->y - DM * sin(mod(360 - p->perso->ori) * M_PI / Z));
	image_generator(p->perso->ori, p->data->wall, p);
}

void	left_move(t_all *p)
{
	p->perso->ori = mod(p->perso->ori);
	if (p->perso->ori <= 90 && p->perso->ori >= 0
		&& hit_check(p, -DM * cos((90 - p->perso->ori) * M_PI / 180),
			-DM * sin((90 - p->perso->ori) * M_PI / 180)) == 1)
		moving(p, p->perso->x - DM * cos((90 - p->perso->ori) * M_PI / Z),
			p->perso->y - DM * sin((90 - p->perso->ori) * M_PI / 180));
	else if (p->perso->ori >= 90 && p->perso->ori <= 180
		&& hit_check(p, -DM * sin((180 - p->perso->ori) * M_PI / 180),
			DM * cos((180 - p->perso->ori) * M_PI / 180)) == 1)
		moving(p, p->perso->x - DM * sin((180 - p->perso->ori) * M_PI / Z),
			p->perso->y + DM * cos((180 - p->perso->ori) * M_PI / 180));
	else if (p->perso->ori >= 180 && p->perso->ori < 270
		&& hit_check(p, DM * cos((270 - p->perso->ori) * M_PI / 180),
			DM * sin((270 - p->perso->ori) * M_PI / 180)) == 1)
		moving(p, p->perso->x + DM * cos((270 - p->perso->ori) * M_PI / Z),
			p->perso->y + DM * sin((270 - p->perso->ori) * M_PI / 180));
	else if (p->perso->ori >= 270 && p->perso->ori <= 360
		&& hit_check(p, DM * sin(mod(360 - p->perso->ori) * M_PI / 180),
			-DM * cos(mod(360 - p->perso->ori) * M_PI / 180)) == 1)
		moving(p, p->perso->x + DM * sin(mod(360 - p->perso->ori) * M_PI / Z),
			p->perso->y - DM * cos(mod(360 - p->perso->ori) * M_PI / Z));
	image_generator(p->perso->ori, p->data->wall, p);
}

void	right_move(t_all *p)
{
	p->perso->ori = mod(p->perso->ori);
	if (p->perso->ori <= 90 && p->perso->ori >= 0
		&& hit_check(p, DM * cos((90 - p->perso->ori) * M_PI / 180),
			DM * sin((90 - p->perso->ori) * M_PI / 180)) == 1)
		moving(p, p->perso->x + DM * cos((90 - p->perso->ori) * M_PI / Z),
			p->perso->y + DM * sin((90 - p->perso->ori) * M_PI / 180));
	else if (p->perso->ori >= 90 && p->perso->ori <= 180
		&& hit_check(p, DM * sin((180 - p->perso->ori) * M_PI / 180),
			-DM * cos((180 - p->perso->ori) * M_PI / 180)) == 1)
		moving(p, p->perso->x + DM * sin((180 - p->perso->ori) * M_PI / Z),
			p->perso->y - DM * cos((180 - p->perso->ori) * M_PI / 180));
	else if (p->perso->ori >= 180 && p->perso->ori < 270
		&& hit_check(p, -DM * cos((270 - p->perso->ori) * M_PI / 180),
			-DM * sin((270 - p->perso->ori) * M_PI / 180)) == 1)
		moving(p, p->perso->x - DM * cos((270 - p->perso->ori) * M_PI / Z),
			p->perso->y - DM * sin((270 - p->perso->ori) * M_PI / 180));
	else if (p->perso->ori >= 270 && p->perso->ori <= 360
		&& hit_check(p, -DM * sin(mod(360 - p->perso->ori) * M_PI / Z),
			+DM * cos(mod(360 - p->perso->ori) * M_PI / 180)) == 1)
		moving(p, p->perso->x - DM * sin(mod(360 - p->perso->ori) * M_PI / Z),
			p->perso->y + DM * cos(mod(360 - p->perso->ori) * M_PI / Z));
	image_generator(p->perso->ori, p->data->wall, p);
}

int	key_hook(int keycode, t_all *p)
{
	if (keycode == ARROW_LEFT)
	{
		destroy_img(p);
		free(p->picture);
		p->picture = init_image(p->mlx);
		if (!p->picture || p->picture == NULL)
			return (closing_inter(p, 4, 1, 0), 1);
		p->perso->ori += CM;
		image_generator(p->perso->ori, p->data->wall, p);
	}
	else if (keycode == ARROW_RIGHT)
		arrow_right(p);
	else if (keycode == W)
		front_move(p);
	else if (keycode == SK)
		back_move(p);
	else if (keycode == A)
		left_move(p);
	else if (keycode == D)
		right_move(p);
	else if (keycode == ESC)
		close_program(p, 0);
	return (1);
}
