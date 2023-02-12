/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:24:34 by gkoechli          #+#    #+#             */
/*   Updated: 2023/02/11 14:41:48 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	exit_hook(t_data *data, int flag)
{
	wall_kill(data);
	free_string_struct(data);
	if (flag == 1)
		exit(EXIT_FAILURE);
	return (0);
}

t_point	*cube(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	map_read(data);
	ft_cpyber(data->temp.solong, data);
	data->win_width = data->row_max * 64;
	data->win_height = data->col_size * 64;
	printf("NEVER\n");
	wall_gen(data);
	grid_gen(data);
	while (j < data->col_size)
	{
		while (i < data->row_max)
		{
			printf("%d", data->wall[j][i]);
			i++;
		}
		printf("\n");
		i = 0;
		j++;
	}
	check_borders(data);
	check_params(data);
	return (&data->player);
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	int		i;
// 	t_data	data;

// 	i = 1;
// 	if (argc != 2)
// 		return (printf("Wrong number of arguments\n"));
// 	if (check_extension(argv[1]))
// 		return (printf("Wrong file type\n"));
// 	ft_bzero(&data, sizeof(data));
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 		return (printf("%s\n", strerror(errno)));
// 	while (i > 0)
// 	{
// 		if (data.temp.buff)
// 			free(data.temp.buff);
// 		i = get_next_line(fd, &data);
// 		str_glue(&data);
// 		str_add(&data, '\n');
// 	}
// 	close(fd);
// 	if (i == -1)
// 		kill_error(&data, MAP_IS_INVALID);
// 	cube(&data);
// 	if (argc == 2 && data.success == 10)
// 		printf("PARSED. RETURNING STRUCT WITH PLAYER POS AND GRID\n");
// 	exit_hook(&data);
// 	return (0);
// }
