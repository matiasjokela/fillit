/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:26:54 by mjokela           #+#    #+#             */
/*   Updated: 2022/01/14 16:26:57 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	move_piece(int **bin_arr, int *map, int i, int side_len)
{
	int	j;
	int	m;
	int	x;

	j = 0;
	m = 1 << side_len;
	x = bin_arr[i][19];
	if ((bin_arr[i][x] << 1 & m) != 0 || (bin_arr[i][x + 1] << 1 & m) != 0 || \
		(bin_arr[i][x + 2] << 1 & m) != 0 || (bin_arr[i][x + 3] << 1 & m) != 0)
	{
		return (move_to_next_row(bin_arr, i, side_len, map));
	}
	bin_arr[i][x] = bin_arr[i][x] << 1;
	bin_arr[i][x + 1] = bin_arr[i][x + 1] << 1;
	bin_arr[i][x + 2] = bin_arr[i][x + 2] << 1;
	bin_arr[i][x + 3] = bin_arr[i][x + 3] << 1;
	return (1);
}

int	move_to_next_row(int **bin_arr, int i, int side_len, int *map)
{
	int	a;

	a = 0;
	while (a < 13)
	{
		if (bin_arr[i][a] != 0)
		{
			bin_arr[i][a] = 0;
			bin_arr[i][a + 1] = bin_arr[i][20];
			bin_arr[i][a + 2] = bin_arr[i][21];
			bin_arr[i][a + 3] = bin_arr[i][22];
			bin_arr[i][a + 4] = bin_arr[i][23];
			bin_arr[i][19]++;
			break ;
		}
		a++;
	}
	if (bin_arr[i][side_len] != 0)
		return (0);
	if ((map[a + 1] ^ MAX << (side_len + 1)) == -1)
		return (move_to_next_row(bin_arr, i, side_len, map));
	return (1);
}

void	restore_piece(int **bin_arr, int i)
{
	int	x;

	x = bin_arr[i][19];
	bin_arr[i][0] = bin_arr[i][20];
	bin_arr[i][1] = bin_arr[i][21];
	bin_arr[i][2] = bin_arr[i][22];
	bin_arr[i][3] = bin_arr[i][23];
	bin_arr[i][x] = 0;
	bin_arr[i][x + 1] = 0;
	bin_arr[i][x + 2] = 0;
	bin_arr[i][x + 3] = 0;
	bin_arr[i][19] = 0;
}

void	pop_piece(int *map, int **bin_arr, int i)
{
	int	a;

	a = bin_arr[i][19];
	map[a] -= bin_arr[i][a];
	map[a + 1] -= bin_arr[i][a + 1];
	map[a + 2] -= bin_arr[i][a + 2];
	map[a + 3] -= bin_arr[i][a + 3];
}

void	clone_piece(int **bin_arr, int i)
{
	int	a;
	int	b;

	a = i - 1;
	while (a >= 0)
	{
		if (bin_arr[i][20] == bin_arr[a][20] \
			&& bin_arr[i][21] == bin_arr[a][21] \
			&& bin_arr[i][22] == bin_arr[a][22] \
			&& bin_arr[i][23] == bin_arr[a][23])
		{
			b = 0;
			while (b < 20)
			{
				bin_arr[i][b] = bin_arr[a][b];
				b++;
			}
			return ;
		}
		a--;
	}
}
