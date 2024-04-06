/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:26:15 by gkoechli          #+#    #+#             */
/*   Updated: 2023/02/16 13:54:35 by gkoechli         ###   ########.fr       */
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
# define COLOR_NOT_FOUND 16

# include "../includes/cub3d.h"

typedef struct s_point {
	double	x;
	double	y;
	double	ori;
}	t_point;

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

struct	s_point;
struct	s_all;

typedef struct s_data
{
	struct s_point	player;
	t_pos			pos;
	t_string		temp;
	void			*ptrtofreeofp;
	void			*ptrtofreeofpperso;
	char			*custompathnorth;
	char			*custompathsouth;
	char			*custompathwest;
	char			*custompatheast;
	char			*map;
	int				f_tab[3];
	int				c_tab[3];
	int				north;
	int				south;
	int				west;
	int				east;
	int				c;
	int				f;
	int				stop;
	int				inc;
	int				index;
	int				success;
	int				check;
	int				**wall;
	int				row_size;
	int				row_max;
	int				col_size;
	int				color;
	int				player_number;
	int				steps;
}	t_data;

/*		cube.c		*/

void	replace_gap_after_parse(t_data *data);
void	fill_blanks(t_data *data);

/*		gnl.c		*/

char	*ft_strdup(const char *s1);
void	ft_strjoinpar(t_data *data);
void	ft_substr_end(t_data *data, int start, int len);
void	ft_substr_tmp(t_data *data, int start, int len);
int		get_next_line(int fd, t_data *data);

/*		gnl_utils.c		*/

int		check_line(char *str);
int		ft_strlen(const char *str);
void	str_glue(t_data *data);
void	str_add(t_data *data, char c);
void	ft_cpyber(const char *str, t_data *data);

/*		mapcheck_error.c		*/

int		map_read(t_data *data, struct s_all *p);
int		check_borders(t_data *data, struct s_all *p);
int		check_correct_parsing_line(t_data *data, int i, struct s_all *p);
int		check_first_part(t_data *data, struct s_all *p);
void	check_rgb_string(t_data *data, char *str, struct s_all *p);

/*		utils.c		*/

void	kill_error(t_data *data, int error_type, struct s_all *p);
int		is_map_valid(t_data *data);
int		fill_grid(t_data *data, int elem, struct s_all *p);
int		grid_gen(t_data *data, struct s_all *p);
void	parse_letters(t_data *data, int i, struct s_all *p);

/*		utils_2.c		*/
int		wall_gen(t_data *data);
int		wall_kill(t_data *data);
int		texture_parse(t_data *data, int i, int X, struct s_all *p);
int		color_parse(char c, t_data *data, int i, struct s_all *p);
int		pathlen(t_data *data, int i);

/*		utils_3.c		*/

int		check_around_ground(t_data *data, int i, int j);
int		parse_north_texture(t_data *data, int i, int c, struct s_all *p);
int		parse_south_texture(t_data *data, int i, int c, struct s_all *p);
int		parse_west_texture(t_data *data, int i, int c, struct s_all *p);
int		parse_east_texture(t_data *data, int i, int c, struct s_all *p);

/*		utils_4.c		*/

int		check_extension(const char *str);
void	ft_color_valid(t_data *data, struct s_all *p);
void	fill_rgb(t_data *data, char **atmp, char c);
int		ft_skip_blanks(t_data *data, int i);

/*		free_stuff.c		*/

int		exit_hook(t_data *data, int flag);
char	*ft_strdup_tweaked(t_data *data, int i);
void	free_tab_custom(char **tmp);
void	free_string_struct_2(t_data *data);
void	free_string_struct(t_data *data);

#endif
