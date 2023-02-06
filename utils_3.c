/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:43:02 by gkoechli          #+#    #+#             */
/*   Updated: 2023/02/06 18:13:17 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	assets_gen(t_data *data)
{
	data->walls.path = ft_strdup("./assets/Blue.xpm");
	// data->collec.path = ft_strdup("./assets/Bomb.xpm");
	data->ground.path = ft_strdup("./assets/Pink.xpm");
	// data->character.path = ft_strdup("./assets/Bandit.xpm");
	// data->exit.path = ft_strdup("./assets/Green.xpm");
	data->walls.image = mlx_xpm_file_to_image(data->mlx_ptr,
			data->walls.path, &data->walls.image_w, &data->walls.image_h);
	data->ground.image = mlx_xpm_file_to_image(data->mlx_ptr,
			data->ground.path, &data->ground.image_w, &data->ground.image_h);
	// data->collec.image = mlx_xpm_file_to_image(data->mlx_ptr,
	// 		data->collec.path, &data->collec.image_w, &data->collec.image_h);
	// data->character.image = mlx_xpm_file_to_image(data->mlx_ptr,
	// 		data->character.path, &data->character.image_w, &data->character.image_h);
	// data->exit.image = mlx_xpm_file_to_image(data->mlx_ptr,
	// 		data->exit.path, &data->exit.image_w, &data->exit.image_h);
}

int	move_player(t_data *data, char c, int i)
{	
	if (c == 'x')
		data->pos.player_x += i;
	if (c == 'y')
		data->pos.player_y += i;
	data->steps += 1;
	printf("%d step(s)\n", data->steps);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		exit_hook(data);
	if (keysym == XK_d)
		if (data->wall[data->pos.player_x + 1][data->pos.player_y] != 1)
			move_player(data, 'x', 1);
	if (keysym == XK_s)
		if (data->wall[data->pos.player_x][data->pos.player_y + 1] != 1)
			move_player(data, 'y', 1);
	if (keysym == XK_a)
		if (data->wall[data->pos.player_x - 1][data->pos.player_y] != 1)
			move_player(data, 'x', -1);
	if (keysym == XK_w)
		if (data->wall[data->pos.player_x][data->pos.player_y - 1] != 1)
			move_player(data, 'y', -1);
	return (0);
}

int	new_coor(t_data *data)
{
	(void)data;
	// if (data->wall[data->pos.player_x][data->pos.player_y] == 2)
	// {
	// 	// data->wall[data->pos.player_x][data->pos.player_y] = 0;
	// 	// data->collectible -= 1;
	// }
	// if (data->wall[data->pos.player_x][data->pos.player_y] == 3
	// 	&& data->collectible == 0)
	// {
	// 	exit_hook(data);
	// }
	return (0);
}

int check_around_ground(t_data  *data, int i, int j)
{
	if (i == 0 || j == 0 || i == data->row_max - 1 || j == data->col_size - 1)
			return -1;
	if(data->wall[i + 1][j] != 1 && data->wall[i + 1][j] != 0)
			return -1;
	if(data->wall[i][j + 1] != 1 && data->wall[i][j + 1] != 0)
			return -1;
	if(data->wall[i][j - 1] != 1 && data->wall[i][j - 1] != 0)
			return -1;
	if(data->wall[i - 1][j] != 1 && data->wall[i - 1][j] != 0)
			return -1;
	return(0);
}
