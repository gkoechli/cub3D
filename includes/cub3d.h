/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatsby <gatsby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:11:03 by gduhau            #+#    #+#             */
/*   Updated: 2023/02/11 00:35:47 by gatsby           ###   ########.fr       */
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
#include <math.h>

typedef struct s_point {
	double	x;
	double	y;
	double orientation;
}	t_point;

# include "../parsing/cube.h"

#define BUFFER_SIZE 42
# define ONDESTROY 17
# define FOV 60 //forcement inf a 90 pour l'instant
# define LARGEUR 1920
# define HAUTEUR 1920

# define NO "./textures/greystone.xpm"
# define SO "./textures/redbrick.xpm"
# define EA "./textures/wood.xpm"
# define WE "./textures/mossy.xpm"

//utile ?
# define DISTANCE_SCREEN (double)((double)LARGEUR * cos(FOV/2/M_PI) / (2 * sin(FOV/2/M_PI)))

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

# define UP 0x87EDF8
# define DOWN 0xCC7000

# define WALL_SOUTH 0xF6E40B

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
	//struct s_img *next;
	//struct s_img *prev;
}				t_img;

typedef struct s_all
{
	t_point *perso;
	t_win	*mlx;
	t_img *picture;
	t_img *text_north;
	t_img *text_south;
	t_img *text_east;
	t_img *text_west;
	
	t_data *data;
}	t_all;


t_point	*cube(t_data *data);

char	*gen_answer(char *new_reserve);
char	*error_case(char *buf, char *reserve, int p);
int	return_exist(char *s);
char	*ft_strcatspe(char *s1, char *s2);
char	*maj_reserve(int fd, char *reserve);
char	*clean_reserve(int i, char *reserve);
//char	*get_next_line(int fd);
char	**ft_split(char *s, char c);
//int	ft_strlen(const char *s);
void	close_program(t_all *p, int mode);
int	close_hook(t_all *vars);
void	free_tab(char **tab);

//init.c
t_img	*init_image(t_win *mlx);
t_all *init_textures(t_all *p);

#endif