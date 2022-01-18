/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:57:35 by mjokela           #+#    #+#             */
/*   Updated: 2021/12/21 16:57:37 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solve_map(int **bin_arr, int piece_count)
{
	int	*map;
	int	side_len;

	side_len = 2;
	map = (int *)malloc(sizeof(int) * 19);
	if (map == NULL)
		exit(-1);
	while (side_len * side_len < piece_count * 4)
		side_len++;
	while (side_len < 20)
	{
		give_map(map, side_len);
		if (solver(bin_arr, map, 0, side_len) == 1)
			break ;
		side_len++;
	}
	free(map);
	return (1);
}

int	solver(int **bin_arr, int *map, int i, int side_len)
{
	clone_piece(bin_arr, i);
	while (1)
	{
		if (plant_piece(bin_arr, map, i, side_len) == 0)
		{
			restore_piece(bin_arr, i);
			return (0);
		}
		if (bin_arr[0][24] == i + 1)
		{
			show_output(bin_arr, side_len);
			exit(1);
		}
		solver(bin_arr, map, i + 1, side_len);
		pop_piece(map, bin_arr, i);
		if (move_piece(bin_arr, map, i, side_len) == 0)
		{
			restore_piece(bin_arr, i);
			return (0);
		}
	}
	return (1);
}

void	give_map(int *map, int side_len)
{
	int	mask;
	int	i;

	mask = 1 << side_len;
	i = 0;
	while (i < side_len)
		map[i++] = mask;
	map[i] = 2147483647;
}
