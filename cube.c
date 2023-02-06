/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:24:34 by gkoechli          #+#    #+#             */
/*   Updated: 2023/02/06 18:06:25 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	exit_hook(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->walls.image);
	mlx_destroy_image(data->mlx_ptr, data->ground.image);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	data->win_ptr = NULL;
	free(data->mlx_ptr);
	wall_kill(data);
	free(data->map);
	free(data->walls.path);
	free(data->ground.path);
	free(data->ground.addr);
	free(data->walls.addr);
	free_string_struct(data);
	exit(EXIT_FAILURE);
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	check_map(data);
	return (0);
}

int	cube(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	map_read(data);
	printf("NEVER\n");
	ft_cpyber(data->temp.solong, data);
	data->win_width = data->row_max * 64;
	data->win_height = data->col_size * 64;
	wall_gen(data);
	grid_gen(data);
	while (j < data->col_size)
	{
		while (i < data->row_max)
		{
			printf("%d", data->wall[i][j]);
			i++;
		}
		printf("\n");
		i = 0;
		j++;
	}
	check_borders(data);
	check_params(data);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->win_width, data->win_height, "SO LONG");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (1);
	}
	assets_gen(data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0, &exit_hook, data);
	mlx_loop(data->mlx_ptr);
	exit_hook(data);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	t_data	data;

	i = 1;
	if (argc != 2)
		return (printf("Wrong number of arguments\n"));
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
	if (argc == 2 && data.success == 10)
		cube(&data);
	return (0);
}
