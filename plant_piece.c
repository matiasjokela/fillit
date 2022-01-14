/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_planting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:51:16 by mjokela           #+#    #+#             */
/*   Updated: 2022/01/14 15:51:19 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	plant_piece(int **bin_arr, int *map, int i, int side_len)
{
	if (bin_arr[i][18] == 2)
		return (plant_piece_2(bin_arr, map, i, side_len));
	if (bin_arr[i][18] == 3)
		return (plant_piece_3(bin_arr, map, i, side_len));
	if (bin_arr[i][18] == 1)
		return (plant_piece_1(bin_arr, map, i, side_len));
	return (plant_piece_4(bin_arr, map, i, side_len));
}

int	plant_piece_1(int **bin_arr, int *map, int i, int side_len)
{
	int	x;
	int	m;

	x = bin_arr[i][19];
	m = 1 << side_len;
	while ((map[x] & bin_arr[i][x]) != 0)
	{	
		if ((bin_arr[i][x] << 1 & m) != 0)
		{
			if (move_to_next_row(bin_arr, i, side_len, map) == 0)
				return (0);
		}
		else
		{
			bin_arr[i][x] = bin_arr[i][x] << 1;
		}
		x = bin_arr[i][19];
	}
	map[x] += bin_arr[i][x];
	return (1);
}

int	plant_piece_2(int **bin_arr, int *map, int i, int side_len)
{
	int	x;
	int	m;

	x = bin_arr[i][19];
	m = 1 << side_len;
	while ((map[x] & bin_arr[i][x]) != 0 || \
		(map[x + 1] & bin_arr[i][x + 1]) != 0)
	{	
		if ((bin_arr[i][x] << 1 & m) != 0 || (bin_arr[i][x + 1] << 1 & m) != 0)
		{
			if (move_to_next_row(bin_arr, i, side_len, map) == 0)
				return (0);
		}
		else
		{
			bin_arr[i][x] = bin_arr[i][x] << 1;
			bin_arr[i][x + 1] = bin_arr[i][x + 1] << 1;
		}
		x = bin_arr[i][19];
	}
	map[x] += bin_arr[i][x];
	map[x + 1] += bin_arr[i][x + 1];
	return (1);
}

int	plant_piece_3(int **ba, int *map, int i, int side_len)
{
	int	x;

	x = ba[i][19];
	while ((map[x] & ba[i][x]) != 0 || (map[x + 1] & ba[i][x + 1]) != 0 || \
			(map[x + 2] & ba[i][x + 2]) != 0)
	{	
		if ((ba[i][x] << 1 & (1 << side_len)) != 0 || \
			(ba[i][x + 1] << 1 & (1 << side_len)) != 0 || \
			(ba[i][x + 2] << 1 & (1 << side_len)) != 0)
		{
			if (move_to_next_row(ba, i, side_len, map) == 0)
				return (0);
		}
		else
		{
			ba[i][x] = ba[i][x] << 1;
			ba[i][x + 1] = ba[i][x + 1] << 1;
			ba[i][x + 2] = ba[i][x + 2] << 1;
		}
		x = ba[i][19];
	}
	map[x] += ba[i][x];
	map[x + 1] += ba[i][x + 1];
	map[x + 2] += ba[i][x + 2];
	return (1);
}

int	plant_piece_4(int **bin_arr, int *map, int i, int side_len)
{
	int	x;
	int	m;

	x = bin_arr[i][19];
	m = 1 << side_len;
	while ((map[x] & bin_arr[i][x]) != 0 || \
		(map[x + 1] & bin_arr[i][x + 1]) != 0 || \
		(map[x + 2] & bin_arr[i][x + 2]) != 0 || \
		(map[x + 3] & bin_arr[i][x + 3]) != 0)
	{	
		if (move_piece(bin_arr, map, i, side_len) == 0)
			return (0);
		x = bin_arr[i][19];
	}
	map[x] += bin_arr[i][x];
	map[x + 1] += bin_arr[i][x + 1];
	map[x + 2] += bin_arr[i][x + 2];
	map[x + 3] += bin_arr[i][x + 3];
	return (1);
}
