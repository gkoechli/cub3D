/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduhau <gduhau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:47:12 by gatsby            #+#    #+#             */
/*   Updated: 2023/02/16 12:50:20 by gduhau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	color_westside(t_all *p, int ray, double dist, double angle)
{
	int			j;
	t_packaging	pack;

	j = 0;
	pack.taille = ceil(HAUTEUR
			/ (dist * cos((md(angle, p->perso->ori)) * M_PI / Z)));
	pack.renew = (p->perso->y - dist * sin((angle) * M_PI / 180)
			- floor(p->perso->y - dist * sin((angle) * M_PI / 180))) * 64;
	pack.rayp = ray;
	if (pack.taille >= HAUTEUR)
	{
		big_wallwest(pack.taille, p, ray, pack.renew);
		return ;
	}
	j = print_sky(pack.taille, p, j, ray);
	j = print_wall(pack, p, j, p->text_west);
	print_floor(p, j, ray);
}

void	color_eastside(t_all *p, int ray, double dist, double angle)
{
	int			j;
	t_packaging	pack;

	j = 0;
	pack.taille = ceil(HAUTEUR
			/ (dist * cos((md(angle, p->perso->ori)) * M_PI / Z)));
	pack.rayp = ray;
	if (angle > 180)
		pack.renew = 64 - (p->perso->y + dist * sin((angle - Z) * M_PI / Z)
				- floor(p->perso->y + dist * sin((angle - Z) * M_PI / Z)))
			* 64;
	else
		pack.renew = 64 - (p->perso->y - dist * sin((180 - angle) * M_PI / Z)
				- floor(p->perso->y - dist * sin((180 - angle) * M_PI / Z)))
			* 64;
	if (pack.taille >= HAUTEUR)
	{
		big_walleast(pack.taille, p, ray, pack.renew);
		return ;
	}
	j = print_sky(pack.taille, p, j, ray);
	j = print_wall(pack, p, j, p->text_east);
	print_floor(p, j, ray);
}

void	color_northside(t_all *p, int ray, double dist, double angle)
{
	int			j;
	t_packaging	pack;

	j = 0;
	pack.taille = ceil(HAUTEUR
			/ (dist * cos((md(angle, p->perso->ori)) * M_PI / Z)));
	pack.rayp = ray;
	if (angle > 90)
		pack.renew = (p->perso->x - dist * sin((angle - 90) * M_PI / Z)
				- floor(p->perso->x - dist * sin((angle - 90) * M_PI / Z)))
			* 64;
	else if (angle < 90)
		pack.renew = (p->perso->x + dist * sin((90 - angle) * M_PI / Z)
				- floor(p->perso->x + dist * sin((90 - angle) * M_PI / Z)))
			* 64;
	if (pack.taille >= HAUTEUR)
	{
		big_wallnorth(pack.taille, p, ray, pack.renew);
		return ;
	}
	j = print_sky(pack.taille, p, j, ray);
	j = print_wall(pack, p, j, p->text_north);
	print_floor(p, j, ray);
}

void	color_southside(t_all *p, int ray, double dist, double angle)
{
	int			j;
	t_packaging	pack;

	j = 0;
	pack.taille = ceil(HAUTEUR
			/ (dist * cos((md(angle, p->perso->ori)) * M_PI / 180)));
	pack.rayp = ray;
	if (angle < 270)
		pack.renew = 64 - (p->perso->x - dist * sin((270 - angle) * M_PI / Z)
				- floor(p->perso->x - dist * sin((270 - angle) * M_PI / Z)))
			* 64;
	else
		pack.renew = 64 - (p->perso->x + dist * sin((angle - 270) * M_PI / Z)
				- floor(p->perso->x + dist * sin((angle - 270) * M_PI / Z)))
			* 64;
	if (pack.taille >= HAUTEUR)
	{
		big_wallsouth(pack.taille, p, ray, pack.renew);
		return ;
	}
	j = print_sky(pack.taille, p, j, ray);
	j = print_wall(pack, p, j, p->text_south);
	print_floor(p, j, ray);
}
