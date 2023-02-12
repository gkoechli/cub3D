/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:15:20 by gatsby            #+#    #+#             */
/*   Updated: 2023/02/11 12:14:55 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"


double md(double angle, double ret)
{
	if (angle < 360 && ret < 360)
	{
		if (angle > ret)
			return (angle - ret);
		else
			return (ret - angle);
	}
	else if (angle > 0 && angle < 90 && ret < 360 && ret > 270)
		return (angle + 360 - ret);
	else if (ret > 0 && angle > 270 && angle < 360)
		return (ret + 360 - angle);
	return (0);
}

char	*ft_strcat2(char *s1, char *s2)
{
	int	index1;
	int	index2;

	index1 = 0;
	index2 = 0;
	if (!s1 && s2)
		return (s2);
	else if (s1 && !s2)
		return (s1);
	else if (!s1 && !s2)
		return (NULL);
	while (s1[index1] != '\0')
		index1++;
	while (s2[index2] != '\0')
		s1[index1++] = s2[index2++];
	s1[index1] = '\0';
	return (s1);
}

double mod(double nb)
{
	if (nb < 0)
		return (360 - ((int)(-1 * nb) % 360) - nb + floor(nb));
	return (((int)floor(nb)) % 360 + nb - floor(nb));
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	int		i;

	i = -1;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	str[i] = '\0';
	str = ft_strcat2(str, s2);
	return (free(s1), str);
}


void	print_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		printf("%s\n", str[i++]);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void color_westside(t_img *picture, int ray, double dist, double angle)
{
	//picture->img = mlx_new_image(mlx->ptr, 1, HAUTEUR);
	//picture->addr = mlx_get_data_addr(picture->img, &picture->bits_per_pixel, &picture->line_length,
								//&picture->endian);
	int j = 0;
	int taille;

	taille = HAUTEUR / (dist * cos(angle * M_PI / 180));
	while ((taille < HAUTEUR && j < (HAUTEUR - taille) / 2))
		my_mlx_pixel_put(picture, ray, j++, UP);
	//int i = 0;
	while ((taille < HAUTEUR && j < taille + (HAUTEUR - taille) / 2) || (taille > HAUTEUR && j < HAUTEUR))
		my_mlx_pixel_put(picture, ray, j++, 0x2021DE);
	while (j < HAUTEUR)
		my_mlx_pixel_put(picture, ray, j++, DOWN);
	//mlx_put_image_to_window(mlx->ptr, mlx->win, picture->img, ray, 0);
}

void color_eastside(t_img *picture, int ray, double dist, double angle)
{
	//picture->img = mlx_new_image(mlx->ptr, 1, HAUTEUR);
	//picture->addr = mlx_get_data_addr(picture->img, &picture->bits_per_pixel, &picture->line_length,
								//&picture->endian);
	int j = 0;
	int taille; //(dist * cos((angle) * M_PI/180));

	taille = HAUTEUR / (dist * cos(angle * M_PI / 180));
	while ((taille < HAUTEUR && j < (HAUTEUR - taille) / 2))
		my_mlx_pixel_put(picture, ray, j++, UP);
	while ((taille < HAUTEUR && j < taille + (HAUTEUR - taille) / 2) || (taille > HAUTEUR && j < HAUTEUR))
		my_mlx_pixel_put(picture, ray, j++, 0x1F9707);
	while (j < HAUTEUR)
		my_mlx_pixel_put(picture, ray, j++, DOWN);
	//mlx_put_image_to_window(mlx->ptr, mlx->win, picture->img, ray, 0);
}

void color_northside(int reg, t_img *picture, int ray, double dist, double angle, t_img *texture, t_point *perso)
{
	int j = 0;
	int y = 0;
	int ybis;
	int renew;
	double taille;
	int offset = 0;
	double dx;
	double dy;

	taille = HAUTEUR / (dist * cos((md(angle, reg)) * M_PI / 180));
	// if (perso->x + cos(angle * M_PI/180) * dist - floor(perso->x + cos(angle * M_PI/180) * dist) < 0.1)
	// 	offset = 0;
	// else
	// 	offset = 1;
	dx = perso->x + cos(angle * M_PI/180) * dist;
	dy = perso->y - sin(angle * M_PI /180) * dist; //OFFSET PAR RAPPORT A L'AXE DU JOUEUR
	// if (floor(dy) == dy)
	// 	offset = 0;
	// else
	// 	offset = 1;
	printf("imp x : %lf - imp y : %lf - offset : %d\n", dx, dy, offset);
	offset = 1;
	if (offset == 1)
	{
		if (angle > 90)
			renew = (perso->x - dist * sin((angle - 90) * M_PI/180) - floor(perso->x - dist * sin((angle - 90) * M_PI/180))) * 64;
		else if (angle == 90)
			renew = 0;
		//else if (angle < 45)
			//renew = (perso->y - dist * sin(angle * M_PI/180) - floor(perso->y - dist * sin(angle * M_PI/180)))*64;
		else
			renew = (perso->x + dist * sin((90 - angle) * M_PI/180) - floor(perso->x + dist * sin((90 - angle) * M_PI/180))) * 64;
	}
	else
	{
		if (angle < 90)
			renew = (perso->y - dist * sin(angle * M_PI/180) - floor(perso->y - dist * sin(angle * M_PI/180)))*64;
		else 
			renew = (perso->y - dist * sin((180 - angle) * M_PI/180) - floor(perso->y - dist * sin((180 -angle) * M_PI/180)))*64;
	}
	while ((taille < HAUTEUR && j < (HAUTEUR - taille) / 2))
		my_mlx_pixel_put(picture, ray, j++, UP);
	while ((taille < HAUTEUR && j < taille + (HAUTEUR - taille) / 2) || (taille > HAUTEUR && j < HAUTEUR))
	{
		//while (ybis++ < y + floor(HAUTEUR/taille * HAUTEUR/64))
		ybis = -1;
		//printf("taille wall : %lf -- taille rapport : %lf\n", taille , taille/64);
		while (++ybis <= floor(taille /64) && ((taille < HAUTEUR && j < taille + (HAUTEUR - taille) / 2) || (taille > HAUTEUR && j < HAUTEUR)))
			my_mlx_pixel_put(picture, ray, j++, *(unsigned int *)(texture->addr + (y * texture->line_length + renew * (texture->bits_per_pixel / 8))));
		y++;//y += floor(taille * HAUTEUR /64);
	}
	j = floor(taille + (HAUTEUR - taille) / 2);
	while (j < HAUTEUR)
		my_mlx_pixel_put(picture, ray, j++, DOWN);
	//mlx_put_image_to_window(mlx->ptr, mlx->win, picture->img, ray, 0);
}

void color_southside(t_img *picture, int ray, double dist, double angle)
{
	//picture->img = mlx_new_image(mlx->ptr, 1, HAUTEUR);
	//picture->addr = mlx_get_data_addr(picture->img, &picture->bits_per_pixel, &picture->line_length,
								//&picture->endian);
	int taille;
	int j = 0;
	taille = HAUTEUR / (dist * cos(angle * M_PI / 180));
	while ((taille < HAUTEUR && j < (HAUTEUR - taille) / 2))
		my_mlx_pixel_put(picture, ray, j++, UP);
	while ((taille < HAUTEUR && j < taille + (HAUTEUR - taille) / 2) || (taille > HAUTEUR && j < HAUTEUR))
		my_mlx_pixel_put(picture, ray, j++, WALL_SOUTH);
	while (j < HAUTEUR)
		my_mlx_pixel_put(picture, ray, j++, DOWN);
	//mlx_put_image_to_window(mlx->ptr, mlx->win, picture->img, ray, 0);
}

double calcul_height(t_point obs, double px, double py, double a, double b)
{
	double dist;
	//double coef;
	double trx;
	double try;

	trx = -1;
	try = -1;
	if (obs.orientation == N)
	{
		try = -(obs.y + 1);
		trx = (try - b) / a;
	}
	else if (obs.orientation == E)
	{
		trx = obs.x + 1;
		try = a * trx + b;
	}
	else if (obs.orientation == O)
	{
		trx = obs.x;
		try = a * (obs.x) + b;
	}
	else if (obs.orientation == S)
	{
		try = -obs.y;
		trx = (try - b) / a;
	}
	dist = sqrt(pow(trx - px, 2) + pow(try + py,2));// * cos((angle) * M_PI / 180);
	//coef = 1 / (dist);
	return (dist);
}

double calcul_height5(t_point obs, double px, double py, double a, double b)
{
	double dist;
	//double coef;
	double trx;
	double try;

	trx = -1;
	try = -1;
	if (obs.orientation == S)
	{
		try = -(obs.y);
		trx = (try - b) / a;
	}
	else if (obs.orientation == E)
	{
		trx = obs.x + 1;
		try = a * trx + b;
	}
	else if (obs.orientation == O)
	{
		trx = obs.x + 1;
		try = a * (trx) + b;
	}
	else if (obs.orientation == N)
	{
		try = -(obs.y + 1);
		trx = (try - b) / a;
	}
	dist = sqrt(pow(trx - px, 2) + pow(try + py,2));// * cos((angle) * M_PI / 180);
	//coef = 1 / (dist);
	//printf("color : %d , coeff = %lf || wal height = %lf\n", obs.orientation, coef, HAUTEUR * coef);
	return (dist);
}

double calcul_height3(t_point obs, double px, double py, double a, double b)
{
	double dist;
	//double coef;
	double trx;
	double try;

	trx = -1;
	try = -1;
	if (obs.orientation == N)
	{
		try = -(obs.y + 1);
		trx = (try - b) / a;
	}
	else if (obs.orientation == S)
	{
		try = -obs.y;
		trx = (try - b)/a;
	}
	else if (obs.orientation == E)
	{
		trx = obs.x;
		try = a * trx + b;
	}
	else if (obs.orientation == O)
	{
		trx = obs.x;
		try = a * (obs.x) + b;
	}
	dist = sqrt(pow(trx - px, 2) + pow(try + py,2));
	//coef = 1 / (dist);
	return (dist);
}


t_point next_square2(double a, double b, double px, double py, int **tab)
{
	t_point ret;
	int xbis;
	int ybis;

	// if (angle == 45)
	// 	return (ret.x = floor(px), ret.y = floor(py), ret); // cas a retravailler
	xbis = floor(px);
	ybis = floor(py);
	while(xbis >= 0 && ybis >= 0)
	{
		if (a * xbis + b < -ybis)
		{
			if (xbis > 0 && tab[ybis][xbis - 1] == 1) // ca tape sur le cote gauche
				return (ret.orientation = E, ret.x = xbis - 1, ret.y = ybis, ret); //ret.x = xbis, ret.y = a * xbis + b, ret);
			if (xbis == 0 && tab[ybis][xbis] == 1) // ca tape sur le cote gauche
				return (ret.orientation = E, ret.x = xbis, ret.y = ybis, ret);
			if (xbis > 0)
				xbis--;
		}
		else if (a * xbis + b > -ybis)
		{
			if (ybis > 0 && tab[ybis - 1][xbis] == 1)//ca tape en premier sur le carre d'haut dessus
				return (ret.orientation = N, ret.x = xbis, ret.y = ybis -1, ret); //ret.x = (ybis - b) / a, ret.y = ybis, ret);
			if (ybis == 0 && tab[ybis][xbis] == 1)//ca tape en premier sur le carre d'haut dessus
				return (ret.orientation = N, ret.x = xbis, ret.y = ybis, ret);
			if (ybis > 0)
				ybis--;
		}
	}
	return (ret.x = -1, ret.y = -1, ret);
}

t_point next_square2bis(double a, double b, double px, double py, int **tab)
{
	t_point ret;
	int xbis;
	int ybis;

	xbis = floor(px);
	ybis = floor(py) + 1;
	while(xbis >= -1 && ybis >= -1)
	{
		if (a * xbis + b < -ybis)
		{
			if (tab[ybis][xbis] == 1) // ca tape sur le cote gauche
				return (ret.orientation = S, ret.x = xbis, ret.y = ybis, ret); //ret.x = xbis, ret.y = a * xbis + b, ret);
			if (ybis > 0)
				ybis++;
		}
		else if (a * xbis + b > -ybis)
		{
			if (tab[ybis - 1][xbis - 1] == 1) //ca tape en premier sur le carre d'haut dessus
				return (ret.orientation = E, ret.x = xbis - 1, ret.y = ybis -1, ret); //ret.x = (ybis - b) / a, ret.y = ybis, ret);
			if (xbis > 0)
				xbis--;
		}
	}
	return (ret.x = -1, ret.y = -1, ret);
}

t_point next_square2bisbis(double a, double b, double px, double py, int **tab)
{
	t_point ret;
	int xbis;
	int ybis;

	xbis = floor(px);
	ybis = floor(py);
	while(xbis >= -1 && ybis >= -1)
	{
		if (a * xbis + b < -ybis)
		{
			if (tab[ybis][xbis - 1] == 1) // ca tape sur le cote gauche
				return (ret.orientation = E, ret.x = xbis - 1, ret.y = ybis, ret); //ret.x = xbis, ret.y = a * xbis + b, ret);
			if (xbis > 0)
				xbis--;
		}
		else if (a * xbis + b > -ybis)
		{
			if (tab[ybis - 1][xbis] == 1) //ca tape en premier sur le carre d'haut dessus
				return (ret.orientation = N, ret.x = xbis, ret.y = ybis - 1, ret); //ret.x = (ybis - b) / a, ret.y = ybis, ret);
			if (ybis > 0)
				ybis--;
		}
	}
	return (ret.x = -1, ret.y = -1, ret);
}


t_point next_square1bis(double a, double b, double px, double py, int **tab)
{
	t_point ret;
	int xbis;
	int ybis;

	xbis = floor(px) + 1;
	ybis = floor(py);
	while(xbis >= -1 && ybis >= -1)
	{
		if (a * xbis + b < -ybis)
		{
			if (tab[ybis][xbis] == 1) // ca tape sur le cote gauche
				return (ret.orientation = O, ret.x = xbis, ret.y = ybis, ret); //ret.x = xbis, ret.y = a * xbis + b, ret);
			xbis++;
		}
		else if (a * xbis + b > -ybis)
		{
			if (tab[ybis - 1][xbis - 1] == 1) //ca tape en premier sur le carre d'haut dessus
				return (ret.orientation = N, ret.x = xbis -1, ret.y = ybis -1, ret); //ret.x = (ybis - b) / a, ret.y = ybis, ret);
			if (ybis > 0)
				ybis--;
		}
	}
	return (ret.x = -1, ret.y = -1, ret);
}

t_point next_square1(double a, double b, double px, double py, int **tab)
{
	t_point ret;
	int xbis;
	int ybis;

	// if (angle == 45)
	// 	return (ret.x = floor(px), ret.y = floor((obs.x - 1)py), ret); // cas a retravailler
	xbis = floor(px) + 1;
	ybis = floor(py);
	while(xbis >= -1 && ybis >= -1)
	{
		if (a * xbis + b < -ybis)
		{
			if (tab[ybis][xbis] == 1) // ca tape sur le cote gauche
				return (ret.orientation = O, ret.x = xbis, ret.y = ybis, ret); //ret.x = xbis, ret.y = a * xbis + b, ret);
			xbis++;
		}
		else if (a * xbis + b > -ybis)
		{
			if (tab[ybis - 1][xbis - 1] == 1) //ca tape en premier sur le carre d'haut dessus
				return (ret.orientation = N, ret.x = xbis - 1, ret.y = ybis -1 , ret); //ret.x = (ybis - b) / a, ret.y = ybis, ret);
			if (ybis > 0)
				ybis--;
		}
	}
	return (ret.x = -1, ret.y = -1, ret);
}

t_point next_square4(double a, double b, double px, double py, int **tab)
{
	t_point ret;
	int xbis;
	int ybis;

	xbis = floor(px) + 1; //3
	ybis = floor(py) + 1; //3
	while(xbis >= 0 && ybis >= 0)
	{
		if (a * xbis + b > -ybis)
		{
			if (tab[ybis - 1][xbis] == 1) //ca tape en premier sur le carre d'haut dessus
				return (ret.orientation = O, ret.x = xbis, ret.y = ybis -1, ret); //ret.x = (ybis - b) / a, ret.y = ybis, ret);
			xbis++;
		}
		else if (a * xbis + b < -ybis)
		{
			if (tab[ybis][xbis -1] == 1) // ca tape sur le cote gauche
				return (ret.orientation = S, ret.x = xbis - 1, ret.y = ybis, ret); //ret.x = xbis, ret.y = a * xbis + b, ret);
			ybis++;
		}
	}
	return (ret.x = -1, ret.y = -1, ret);
}

t_point next_square4bis(double a, double b, double px, double py, int **tab)
{
	t_point ret;
	int xbis;
	int ybis;

	xbis = floor(px) + 1; //3
	ybis = floor(py) + 1; //3
	while(xbis >= 0 && ybis >= 0)
	{
		if (a * xbis + b > -ybis)
		{
			if (tab[ybis - 1][xbis] == 1) //ca tape en premier sur le carre d'haut dessus
				return (ret.orientation = O, ret.x = xbis, ret.y = ybis -1, ret); //ret.x = (ybis - b) / a, ret.y = ybis, ret);
			xbis++;
		}
		else if (a * xbis + b < -ybis)
		{
			if (tab[ybis][xbis -1] == 1) // ca tape sur le cote gauche
				return (printf("obstacle repere : TAB[%d][%d] SUD\n", ybis , xbis-1),ret.orientation = S, ret.x = xbis - 1, ret.y = ybis, ret); //ret.x = xbis, ret.y = a * xbis + b, ret);
			ybis++;
		}
	}
	return (ret.x = -1, ret.y = -1, ret);
}


t_point next_square3(double a, double b, double px, double py, int **tab)
{
	t_point ret;
	int xbis;
	int ybis;

	xbis = floor(px);
	ybis = floor(py) + 1;
	while(xbis >= 0 && ybis >= 0)
	{
		if (a * xbis + b < -ybis)
		{
			if (tab[ybis][xbis] == 1) // ca tape sur le cote gauche
				return (ret.orientation = S, ret.x = xbis, ret.y = ybis, ret); //ret.x = xbis, ret.y = a * xbis + b, ret);
			if (ybis < 8)
				ybis++;
		}
		else if (a * xbis + b > -ybis)
		{
			if (tab[ybis - 1][xbis-1] == 1) //ca tape en premier sur le carre d'haut dessus
				return (ret.orientation = E, ret.x = xbis-1, ret.y = ybis - 1, ret); //ret.x = (ybis - b) / a, ret.y = ybis, ret);
			if (xbis > 0)
				xbis--;
		}
	}
	return (ret.x = -1, ret.y = -1, ret);
}




void image_generator(t_win *mlx, t_point *perso, int reg, t_img *picture, int **tab, t_all *p)
{
	int	ray;
	double angle;
	double a;
	double b;
	t_point obs;
	double dist;
	//double cst;
	//int mid;
	int min;
	//int flag = -1;

	ray = 0;
	reg = mod(reg);
	angle = mod(reg + (double) FOV/2); //passer en float pt pour les variations de valeur
	//cst = 2 * tan(FOV/2 * M_PI/180)/LARGEUR;
	min = ((int)angle / 90) * 90;
	printf("Axe de base : %d Angle de debut : %lf min : %d\n", reg, angle, min);
	while(ray < LARGEUR && angle > min)
	{
		if (angle < 180 && angle > 90 && angle != 135)
		{
			a = -1/ tan((angle - 90) * M_PI/180);
			b = -perso->y + perso->x/tan((angle - 90) * M_PI/180);
			obs.orientation = -1;
			obs = next_square2(a, b, perso->x, perso->y, tab);
			dist = calcul_height(obs, perso->x, perso->y, a , b);// angle - 90);
			if (obs.orientation == E)
				color_eastside(picture, ray, dist, md(angle, reg));
			else if (obs.orientation == N)
				color_northside(reg, picture, ray, dist, angle, p->text_north, perso);
		}
		else if (angle > 180 && angle < 270 && angle != 225)
		{
			a = 1/ tan((90 - (angle - 180)) * M_PI/180);
			b = -perso->y - perso->x/tan((90 - (angle - 180)) * M_PI/180);
			obs = next_square2bis(a, b, perso->x, perso->y, tab);
			dist = calcul_height5(obs, perso->x, perso->y, a , b);
			if (obs.orientation ==  E)
				color_eastside(picture, ray, dist, md(angle, reg));
			else if (obs.orientation == S)
				color_southside(picture, ray, dist, md(angle, reg));
		}
		else if (angle > 0 && angle < 90 && angle != 45)
		{
			a = 1/ tan((90 - angle) * M_PI/180);
			b = -perso->y - perso->x/tan((90 - angle) * M_PI/180);
			obs = next_square1bis(a, b, perso->x, perso->y, tab);
			dist = calcul_height3(obs, perso->x, perso->y, a , b);
			if (obs.orientation ==  O)
				color_westside(picture, ray, dist, md(angle, reg));
			else if (obs.orientation == N)
				color_northside(reg, picture, ray, dist, angle, p->text_north, perso);
		}
		else if (angle < 360 && angle > 270 && angle != 315)
		{
			a = -1/ tan((angle - 180 - 90) * M_PI/180);
			b = -perso->y + perso->x/tan((angle - 180 -90) * M_PI/180);
			obs.orientation = -1;
			obs = next_square4(a, b, perso->x, perso->y, tab);
			dist = calcul_height(obs, perso->x, perso->y, a , b);
			if (obs.orientation ==  O)
				color_westside(picture, ray, dist, md(angle, reg));
			else if (obs.orientation == S)
				color_southside(picture, ray, dist, md(angle, reg));
		}
		ray++;
		angle -= (double)FOV/ (double)LARGEUR;
		// if (flag == -1 && angle > reg && tan((angle - reg) * M_PI/180) - cst < 0)
		// {
		// 	flag = 1; //angle -= //(double)FOV/ (double)LARGEUR;
		// 	angle = reg + mod(atan(tan((angle - reg) * M_PI /180) - cst) * 180 /M_PI);
		// }
		// if (angle > reg || (angle < 90 && angle > 0 && reg > 270 ))
		// 	angle = mod (reg + atan(tan(mod(angle - reg) * M_PI /180) + flag * cst) * 180 /M_PI);
		// else //if (angle < reg)
		// 	angle = mod (reg - atan(tan(mod(reg - angle) * M_PI/180) + flag *cst) * 180/M_PI);
		// printf("Angle : %lf\n", angle);

	}
	if (ray == LARGEUR)
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win, picture->img, 0, 0);
		return ;
	}
	if (min == 0)
		angle = 360 -  (double)FOV/ (double)LARGEUR;
	else
		angle = min - (double)FOV/ (double)LARGEUR;
	while (ray < LARGEUR)
	{
		if (angle < reg && angle > 0 && angle < 90 && angle != 45 && reg - angle != 0)
		{
			a = 1/ tan((90 - angle) * M_PI/180);
			b = -perso->y - perso->x/tan((90 - angle) * M_PI/180);
			obs.orientation = -1;
			obs = next_square1(a, b, perso->x, perso->y, tab);
			dist = calcul_height(obs, perso->x, perso->y, a , b); // 90 -angle);
			if (obs.orientation ==  O)
				color_westside(picture, ray, dist, md(angle, reg));
			else if (obs.orientation == N)
				color_northside(reg, picture, ray, dist, angle, p->text_north, perso);
		}
		else if (angle < reg && angle < 180 && angle > 90 && angle != 135 && 270 - 2 * reg + angle != 0)
		{
			a = -1/ tan((angle - 90) * M_PI/180);
			b = -perso->y + perso->x/tan((angle -90) * M_PI/180);
			obs = next_square2bisbis(a, b, perso->x, perso->y, tab);
			dist = calcul_height5(obs, perso->x, perso->y, a , b);
			if (obs.orientation ==  E)
				color_eastside(picture, ray, dist, md(angle, reg));
			else if (obs.orientation == N)
				color_northside(reg, picture, ray, dist, angle, p->text_north, perso);
		}
		else if (angle < reg && angle < 360 && angle > 270 && angle != 315 && 90 - (reg -angle) != 0)
		{
			a = -1/ tan((angle - 180 - 90) * M_PI/180); // a = -1/ tan((90 -(reg- angle - 180 - 90)) * M_PI/180);
			b = -perso->y + perso->x/tan((angle - 180 - 90) * M_PI/180);
			obs = next_square4bis(a, b, perso->x, perso->y, tab);
			dist = calcul_height3(obs, perso->x, perso->y, a , b);
			if (obs.orientation ==  O)
				color_westside(picture, ray, dist, md(angle, reg));
			else if (obs.orientation == S)
				color_southside(picture, ray, dist, md(angle, reg));
		}
		else if (angle < reg && angle < 270 && angle > 180 && angle != 225 && reg - angle != 0)
		{
			a = 1/ tan(((90 - angle + 180)) * M_PI/180);
			b = -perso->y - perso->x/tan(((90 - angle + 180)) * M_PI/180);
			obs.orientation = -1;
			obs = next_square3(a, b, perso->x, perso->y, tab);
			dist = calcul_height(obs, perso->x, perso->y, a , b);
			if (obs.orientation ==  E)
				color_eastside(picture, ray, dist, md(angle, reg));
			else if (obs.orientation == S)
				color_southside(picture, ray, dist, md(angle, reg));
		}
		else if (angle > reg && angle > 270 && angle < 360 && angle != 315)
		{
			a = -1/ tan((angle - 180 - 90) * M_PI/180);
			b = -perso->y + perso->x/tan((angle - 180 -90) * M_PI/180);
			obs.orientation = -1;
			obs = next_square4(a, b, perso->x, perso->y, tab);
			dist = calcul_height(obs, perso->x, perso->y, a , b);
			if (obs.orientation ==  O)
				color_westside(picture, ray, dist, md(angle, reg));
			else if (obs.orientation == S)
				color_southside(picture, ray, dist, md(angle, reg));
		}
		else if (angle > reg && angle > 0 && angle < 90 && angle != 45)
		{
			a = 1/ tan((90 - angle) * M_PI/180);
			b = -perso->y - perso->x/tan((90 - angle) * M_PI/180);
			obs = next_square1bis(a, b, perso->x, perso->y, tab);
			dist = calcul_height3(obs, perso->x, perso->y, a , b);
			if (obs.orientation ==  O)
				color_westside(picture, ray, dist, md(angle, reg));
			else if (obs.orientation == N)
				color_northside(reg, picture, ray, dist, angle, p->text_north, perso);
		}
		else if (angle > reg && angle > 180 && angle < 270 && angle != 225)
		{
			a = 1/ tan((90 - (angle - 180)) * M_PI/180);
			b = -perso->y - perso->x/tan((90 - (angle - 180)) * M_PI/180);
			obs = next_square2bis(a, b, perso->x, perso->y, tab);
			dist = calcul_height5(obs, perso->x, perso->y, a , b);
			if (obs.orientation ==  E)
				color_eastside(picture, ray, dist, md(angle, reg));
			else if (obs.orientation == S)
				color_southside(picture, ray, dist, md(angle, reg));
		}
		else if (angle > reg && angle > 90 && angle < 180 && angle != 135)
		{
			a = -1/ tan((angle - 90) * M_PI/180);
			b = -perso->y + perso->x/tan((angle - 90) * M_PI/180);
			obs.orientation = -1;
			obs = next_square2(a, b, perso->x, perso->y, tab);
			dist = calcul_height(obs, perso->x, perso->y, a , b);// angle - 90);
			if (obs.orientation == E)
				color_eastside(picture, ray, dist, md(angle, reg));
			else if (obs.orientation == N)
				color_northside(reg, picture, ray, dist, angle, p->text_north, perso);
		}
		ray++;
		angle -= (double)FOV/ (double)LARGEUR;
		// if (flag == -1 && angle > reg && tan((angle - reg) * M_PI/180) - cst < 0)
		// {
		// 	flag = 1; //angle -= //(double)FOV/ (double)LARGEUR;
		// 	angle = reg + mod(atan(tan((angle - reg) * M_PI /180) - cst) * 180 /M_PI);
		// }
		// if (angle > reg || (angle < 90 && angle > 0 && reg > 270 ))
		// 	angle = mod (reg + atan(tan(mod(angle - reg) * M_PI /180) + flag * cst) * 180 /M_PI);
		// else //if (angle < reg)
		// 	angle = mod (reg - atan(tan(mod(reg - angle) * M_PI/180) + flag *cst) * 180/M_PI);
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, picture->img, 0, 0);
}

void destroy_img(t_all *p)
{
	mlx_destroy_image(p->mlx->ptr, p->picture->img);
}

int	key_hook(int keycode, t_all *p)
{
	if (keycode == ARROW_LEFT)
	{
		destroy_img(p);
		free(p->picture);
		p->picture = init_image(p->mlx);
		p->perso->orientation += 10;
		image_generator(p->mlx, p->perso, p->perso->orientation, p->picture, p->data->wall, p);
	}
	else if (keycode == ARROW_RIGHT)
	{
		destroy_img(p);
		free(p->picture);
		p->picture = init_image(p->mlx);
		p->perso->orientation -= 10;
		image_generator(p->mlx, p->perso, p->perso->orientation, p->picture, p->data->wall, p);
	}
	else if (keycode == W)
	{
		destroy_img(p);
		free(p->picture);
		p->picture = init_image(p->mlx);
		p->perso->orientation = mod(p->perso->orientation);
		if (p->perso->orientation < 90 && p->perso->orientation > 0)
		{
			p->perso->x += 0.5 * cos(p->perso->orientation * M_PI / 180);
			p->perso->y -= 0.5 * sin(p->perso->orientation * M_PI / 180);
		}
		else if (p->perso->orientation > 90 && p->perso->orientation < 180)
		{
			p->perso->x -= 0.5 * cos((180 - p->perso->orientation) * M_PI / 180);
			p->perso->y -= 0.5 * sin((180 - p->perso->orientation) * M_PI / 180);
		}
		else if (p->perso->orientation > 180 && p->perso->orientation < 270)
		{
			p->perso->x -= 0.5 * cos((p->perso->orientation - 180) * M_PI/180);
			p->perso->y += 0.5 * sin((p->perso->orientation - 180) * M_PI/180);
		}
		else if (p->perso->orientation > 270 && p->perso->orientation < 360)
		{
			p->perso->x += 0.5 * cos(mod(360 - p->perso->orientation) * M_PI/180);
			p->perso->y += 0.5 * sin(mod(360 - p->perso->orientation) * M_PI/180);
		}
		image_generator(p->mlx, p->perso, p->perso->orientation, p->picture, p->data->wall, p);
	}
	else if (keycode == SK)
	{
		destroy_img(p);
		free(p->picture);
		p->picture = init_image(p->mlx);
		p->perso->orientation = mod(p->perso->orientation);
		if (p->perso->orientation < 90 && p->perso->orientation > 0)
		{
			p->perso->x -= 0.5 * cos(p->perso->orientation * M_PI / 180);
			p->perso->y += 0.5 * sin(p->perso->orientation * M_PI / 180);
		}
		else if (p->perso->orientation > 90 && p->perso->orientation < 180)
		{
			p->perso->x += 0.5 * cos((180 - p->perso->orientation) * M_PI / 180);
			p->perso->y += 0.5 * sin((180 - p->perso->orientation) * M_PI / 180);
		}
		else if (p->perso->orientation > 180 && p->perso->orientation < 270)
		{
			p->perso->x += 0.5 * cos((p->perso->orientation - 180) * M_PI/180);
			p->perso->y -= 0.5 * sin((p->perso->orientation - 180) * M_PI/180);
		}
		else if (p->perso->orientation > 270 && p->perso->orientation < 360)
		{
			p->perso->x -= 0.5 * cos(mod(360 - p->perso->orientation) * M_PI/180);
			p->perso->y -= 0.5 * sin(mod(360 - p->perso->orientation) * M_PI/180);
		}
		image_generator(p->mlx, p->perso, p->perso->orientation, p->picture, p->data->wall, p);
	}
	else if (keycode == A) // a revoir pour les deplacements 
	{
	destroy_img(p);
	free(p->picture);
	p->picture = init_image(p->mlx);
	p->perso->orientation = mod(p->perso->orientation);
	if (p->perso->orientation < 90 && p->perso->orientation > 0)
	{
		p->perso->x -= 0.5 * cos(p->perso->orientation * M_PI / 180);
		p->perso->y -= 0.5 * sin(p->perso->orientation * M_PI / 180);
	}
	else if (p->perso->orientation > 90 && p->perso->orientation < 180)
	{
		p->perso->x -= 0.5 * cos((180 - p->perso->orientation) * M_PI / 180);
		p->perso->y += 0.5 * sin((180 - p->perso->orientation) * M_PI / 180);
	}
	else if (p->perso->orientation > 180 && p->perso->orientation < 270)
	{
		p->perso->x += 0.5 * cos((p->perso->orientation - 180) * M_PI/180);
		p->perso->y += 0.5 * sin((p->perso->orientation - 180) * M_PI/180);
	}
	else if (p->perso->orientation > 270 && p->perso->orientation < 360)
	{
		p->perso->x += 0.5 * cos(mod(360 - p->perso->orientation) * M_PI/180);
		p->perso->y -= 0.5 * sin(mod(360 - p->perso->orientation) * M_PI/180);
	}
	image_generator(p->mlx, p->perso, p->perso->orientation, p->picture, p->data->wall, p);
	}
	return 1;
}

int main(int argc, char *argv[])
{
	t_all *p;
	int		fd;
	int		i;
	t_data	data;


	p = malloc(sizeof(t_all));
	if (!p)
		return (0);
	p->perso = malloc(sizeof(t_point));
	if (!p->perso)
		return (0);
	i = 1;
	if (argc != 2)
		return (printf("Wrong number of arguments\n"));
	if (check_extension(argv[1]))
		return (printf("Wrong file type\n"));
	ft_bzero(&data, sizeof(data));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (printf("%s\n", strerror(errno)));
	while (i > 0)
	{
		if (data.temp.buff)
			free(data.temp.buff);
		i = get_next_line(fd, &data);
		str_glue(&data);
		str_add(&data, '\n');
	}
	close(fd);
	if (i == -1)
		kill_error(&data, MAP_IS_INVALID);
	p->perso = cube(&data);
	printf("px : %lf - py : %lf - or : %lf\n", p->perso->x, p->perso->y, p->perso->orientation);
	p->data = &data;
	p->perso->x += 0.5;
	p->perso->y += 0.5;
	if (argc == 2 && data.success == 10)
		printf("PARSED. RETURNING STRUCT WITH PLAYER POS AND GRID\n");

	p->mlx = malloc(sizeof(t_win));
	if (!p->mlx)
		return (perror("Error\n"), 0);
	p->mlx->ptr = mlx_init();
	if (!p->mlx->ptr)
		return (free(p->mlx), perror("Error\n"), 0);
	p->mlx->win = mlx_new_window(p->mlx->ptr, LARGEUR, HAUTEUR, "cube3d");
	p->picture = init_image(p->mlx);
	// if (init_textures(p) == -1)
	// 	return (1);
	p = init_textures(p);	
	//printf("%s\nlinelength:%d\n", p->text_north->addr, p->text_north->line_length);
	image_generator(p->mlx, p->perso, p->perso->orientation, p->picture, p->data->wall, p);
	if (!p->mlx->win)
		return (free(p->mlx->ptr), free(p->mlx), perror("Error\n"), 0);
	mlx_key_hook(p->mlx->win, key_hook, p);
	mlx_hook(p->mlx->win, ONDESTROY, 1L << 19, close_hook, p);
	mlx_loop(p->mlx->ptr);
}