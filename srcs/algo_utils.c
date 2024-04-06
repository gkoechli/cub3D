/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:03:37 by gduhau            #+#    #+#             */
/*   Updated: 2023/02/16 14:01:04 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_eq	attribute(double a, double b)
{
	t_eq	eq;

	eq.a = a;
	eq.b = b;
	return (eq);
}

double	iter_ang(int ray, int reg, double angle)
{
	double	cst;

	cst = 2 * tan(FOV / 2 * M_PI / 180) / LARGEUR;
	if (ray == (int)(LARGEUR / 2))
		return (reg);
	else if (ray > (int)(LARGEUR / 2))
	{
		return (mod (reg - mod(atan(tan((mod(reg - angle))
							* M_PI / 180) + cst) * 180 / M_PI)));
	}
	else if (ray < (int)(LARGEUR / 2))
	{
		return (mod (reg + mod(atan(tan((mod(angle - reg))
							* M_PI / 180) - cst) * 180 / M_PI)));
	}
	return (0);
}

int	check_param(int argc)
{
	if (argc != 2)
		return (printf("Error\nInvalid parameters\n"), 1);
	if (FOV >= 90 || FOV < 30)
		return (1);
	if (LARGEUR < 500 || HAUTEUR < 500)
		return (printf("Error\nInvalid parameters\n"), 1);
	if (!(DM == 0.1 || DM == 0.3))
		return (printf("Error\nInvalid parameters\n"), 1);
	if (CM != 10)
		return (printf("Error\nInvalid parameters\n"), 1);
	return (0);
}

void	first_part(double angle, int **tab, t_all *p, t_norm no)
{
	if (angle <= 180 && angle >= 90)
		fcase90(angle, tab, p, no.ray);
	else if (angle > 180 && angle <= 270)
		fcase180(angle, tab, p, no.ray);
	else if (angle >= 0 && angle < 90)
		fcase0(angle, tab, p, no.ray);
	else if (angle <= 360 && angle > 270)
		fcase270(angle, tab, p, no.ray);
}
