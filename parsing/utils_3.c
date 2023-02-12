/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduhau <gduhau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:43:02 by gkoechli          #+#    #+#             */
/*   Updated: 2023/02/09 15:40:31 by gduhau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_around_ground(t_data  *data, int i, int j)
{
	if (i == 0 || j == 0 || i == data->row_max - 1 || j == data->col_size - 1)
			return -1;
	if(data->wall[j][i + 1] != 1 && data->wall[j][i + 1] != 0)
			return -1;
	if(data->wall[j + 1][i] != 1 && data->wall[j + 1][i] != 0)
			return -1;
	if(data->wall[j - 1][i] != 1 && data->wall[j - 1][i] != 0)
			return -1;
	if(data->wall[j][i - 1] != 1 && data->wall[j][i - 1] != 0)
			return -1;
	return(0);
}
