/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:26:15 by gkoechli          #+#    #+#             */
/*   Updated: 2023/02/12 16:55:31 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <string.h>
# include <errno.h>

# define ALLOC_ISSUE 17
# define MAP_IS_INVALID 15
# define DUPLICATE_PLAYER 14
# define NO_PLAYER 13

# include "../includes/cub3d.h"

typedef struct s_pos
{
	int	x;
	int	y;
	int	player_x;
	int	player_y;
	int	height;
	int	width;
}	t_pos;

typedef struct s_string
{
	char	*tmp;
	char	*buff;
	char	*end;
	char	*solong;
}	t_string;

struct s_point;

typedef struct s_data
{

	struct s_point	player;
	t_pos		pos;
	t_string	temp;
	char		*custompathnorth;
	char		*custompathsouth;
	char		*custompathwest;
	char		*custompatheast;
	char		*map;
	int			F_tab[3];
	int			C_tab[3];
	int			NO;
	int			SO;
	int			WE;
	int 		EA;
	int			C;
	int			F;
	int 		inc;
	int			index;
	int			success;
	int			check;
	int			**wall;
	int			row_size;
	int			row_max;
	int			col_size;
	int			color;
	int			player_number;
	int			steps;
	int			win_width;
	int			win_height;
}	t_data;

/*		cube.c		*/

int		exit_hook(t_data *data, int flag);

/*		gnl.c		*/

char	*ft_strdup(const char *s1);
void	ft_strjoinpar(t_data *data);
void	ft_substr_end(t_data *data, int start, int len);
void	ft_substr_tmp(t_data *data, int start, int len);
int		get_next_line(int fd, t_data *data);

/*		gnl_utils.c		*/

int		check_line(char *str);
int		ft_strlen(const char *str);

/*		mapcheck_error.c		*/

int		check_map(t_data *data);
int		check_borders(t_data *data);
int		fill_grid(t_data *data, int elem);
int		grid_gen(t_data *data);

/*		utils.c		*/

void	ft_cpyber(const char *str, t_data *data);
void	kill_error(t_data *data, int error_type);
int		is_map_valid(t_data *data);
void	check_params(t_data *data);
void	str_glue(t_data *data);

/*		utils_2.c		*/
int		map_read(t_data *data);
void	str_add(t_data *data, char c);
void	free_string_struct(t_data *data);
int		wall_gen(t_data *data);
int		wall_kill(t_data *data);

/*		utils_3.c		*/

int		check_around_ground(t_data *data, int i, int j);

/*		ft_bzero.c		*/

void	ft_bzero(void *s, size_t n);
char	*ft_strstr(const char *haystack, const char *needle);
int 	check_extension(const char *str);

/*		ft_calloc.c		*/

void	*ft_calloc(size_t count, size_t size);

#endif

