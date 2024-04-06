/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:11:03 by gduhau            #+#    #+#             */
/*   Updated: 2023/02/16 13:52:41 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "../parsing/cube.h"

typedef struct s_eq {
	double	a;
	double	b;
}	t_eq;

typedef struct s_packaging {
	double	taille;
	int		renew;
	int		rayp;
}	t_packaging;

typedef struct s_bis {
	int	x;
	int	y;
}	t_bis;

typedef struct s_norm{
	int	ray;
	int	reg;
}	t_norm;

# define BUFFER_SIZE 42
# define ONDESTROY 17
# define FOV 60
# define LARGEUR 1500
# define HAUTEUR 1000

# define DM 0.3
# define CM 10

# define N 90
# define O 180
# define E 0
# define S 270

# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define W 119
# define A 97
# define SK 115
# define D 100
# define ESC 65307

# define Z 180

typedef struct s_vars {
	void	*ptr;
	void	*win;
}				t_win;

typedef struct s_img {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				pos;
}				t_img;

typedef struct s_all
{
	t_point	*perso;
	t_win	*mlx;
	t_img	*picture;
	t_img	*text_north;
	t_img	*text_south;
	t_img	*text_east;
	t_img	*text_west;
	t_data	*data;
	int		i;
}	t_all;

t_point	*cube(t_data *data, t_all *p);
char	**ft_split(char *s, char c);
void	close_program(t_all *p, int mode);
int		close_hook(t_all *vars);
void	free_tab(char **tab);

//closing.c
void	closing_inter(t_all *p, int opt, int mode, int flag);

//init.c
t_img	*init_image(t_win *mlx);
t_all	*init_textures(t_all *p);

//move.c
int		key_hook(int keycode, t_all *p);

//move_utils.c
void	moving(t_all *p, double x, double y);
int		hit_check(t_all *p, double x, double y);
void	destroy_img(t_all *p);
void	arrow_right(t_all *p);

//main.c
void	image_generator(int reg, int **tab, t_all *p);
void	second_part(t_norm no, int **tab, t_all *p, double angle);

//square.c
t_point	next_square2(t_eq eq, double px, double py, int **tab);
t_point	next_square2bis(t_eq eq, double px, double py, int **tab);
t_point	next_square2bisbis(t_eq eq, double px, double py, int **tab);
t_point	next_square1bis(t_eq eq, double px, double py, int **tab);

//square2.c
t_point	next_square4(t_eq eq, double px, double py, int **tab);
t_point	next_square4bis(t_eq eq, double px, double py, int **tab);
t_point	next_square3(t_eq eq, double px, double py, int **tab);
t_point	next_square1(t_eq eq, double px, double py, int **tab);

//color.c
void	color_westside(t_all *p, int ray, double dist, double angle);
void	color_eastside(t_all *p, int ray, double dist, double angle);
void	color_northside(t_all *p, int ray, double dist, double angle);
void	color_southside(t_all *p, int ray, double dist, double angle);

//color_spe.c
double	vert_90(t_all *p, int mode, int **tab);
void	color_spe90(t_all *p, int **tab, int ray, t_img *texture);
void	color_spe180(t_all *p, int **tab, int ray, t_img *texture);
void	color_spe270(t_all *p, int **tab, int ray, t_img *texture);

//color_utils.c
int		print_sky(double taille, t_all *p, int j, int ray);
void	print_floor(t_all *p, int j, int ray);
int		print_wall(t_packaging pack, t_all *p, int j, t_img *texture);

//heigths.c
double	calcul_height(t_point obs, double px, double py, t_eq eq);
double	calcul_height5(t_point obs, double px, double py, t_eq eq);
double	calcul_height3(t_point obs, double px, double py, t_eq eq);

//mlx_utils.c
double	md(double angle, double ret);
double	mod(double nb);
int		create_trgb(unsigned char r, unsigned char g, unsigned char b);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		special_incr(int nb);

//algo_1.c
void	fcase90(double angle, int **tab, t_all *p, int ray);
void	fcase180(double angle, int **tab, t_all *p, int ray);
void	fcase270(double angle, int **tab, t_all *p, int ray);
void	fcase0(double angle, int **tab, t_all *p, int ray);

//algo_2.c
void	scase0(double angle, int **tab, t_all *p, int ray);
void	scase90(double angle, int **tab, t_all *p, int ray);
void	scase270(double angle, int **tab, t_all *p, int ray);
void	scase180(double angle, int **tab, t_all *p, int ray);

//algo_3.c
void	big_wallwest(double taille, t_all *p, int ray, int renew);
void	big_walleast(double taille, t_all *p, int ray, int renew);
void	big_wallnorth(double taille, t_all *p, int ray, int renew);
void	big_wallsouth(double taille, t_all *p, int ray, int renew);

//algo_utils.c
t_eq	attribute(double a, double b);
double	iter_ang(int ray, int reg, double angle);
int		check_param(int argc);
void	first_part(double angle, int **tab, t_all *p, t_norm no);

#endif