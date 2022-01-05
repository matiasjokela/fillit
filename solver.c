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

char **solve_map(int **bin_arr, int piece_count)
{
	int	*map;
	int	side_len;

	side_len = 2;
	map = (int *)malloc(sizeof(int) * 19);
	if (map == NULL)
		exit(-1);
	while (side_len * side_len < piece_count * 4)
		side_len++;
	give_map(map, side_len);
	bin_arr[1][0] = bin_arr[1][0] << 5;
	move_piece(bin_arr, map, 1, side_len);
	plant_piece(bin_arr, map, 1, side_len);
	for (int i = 0; i < 15; i++)
		print_bits(map[i]);	
	/*for (int i = 0; i < 15; i++)
		print_bits(map[i]);
	bin_arr[1][0] = bin_arr[1][0] << 1;
	printf("plant piece returns: %d\n", plant_piece(bin_arr, map, 1, side_len));
	for (int i = 0; i < 15; i++)
		print_bits(map[i]);	*/

	//printf("%d\n", map[0] | bin_arr[0][0] | bin_arr[1][0] | bin_arr[2][0]);

	return (NULL);

}

/* Plants piece to next available space, 
returns 1 if piece can be planted and 0 if not*/
int	plant_piece(int **bin_arr, int *map, int i, int side_len)
{
	int j;

	j = 0;
	while (j < side_len)
	{
		if ((map[j] & bin_arr[i][j]) != 0)
		{
			if (move_piece(bin_arr, map, i, side_len) == 0)
				return (0);
			else
				break ;
		}
		j++;
	}
	j = 0;
	while (j < side_len)
	{
		map[j] += bin_arr[i][j];
		j++;
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
	map[i] = MAX;

}

/* Moves piece to next available space, 
returns 1 if space was found and 0 if not */
int	move_piece(int **bin_arr, int *map, int i, int side_len)
{
	// Function only called if piece needs to be moved
	int j;
	int	mask;
	(void)map;

	j = 0;
	mask = 1 << side_len;
	while (j < side_len)
	{
		// Check if piece is out of bounds without moving it yet
		if ((bin_arr[i][j] << 1 & mask) != 0)
			move_to_next_row(bin_arr, i);
		j++;
	}
	/*
	Still needs to check for out of bounds at the lower limit? Also needs to 
	move piece when it collides with another piece in the map
	*/
	return (1);
}

void	move_to_next_row(int **bin_arr, int i)
{
	int	a;
	int	b;

	b = 0;
	// Move piece to beginning of row
	while (b == 0)
	{
		a = 0;
		while (a < 19)
		{
			bin_arr[i][a] = bin_arr[i][a] >> 1;
			if ((bin_arr[i][a] & 1) == 1)
				b = 1;
			a++;
		}
	}
	// Move piece one row down
	while (a > 0)
	{
		bin_arr[i][a] = bin_arr[i][a - 1];
		a--;
	}
	bin_arr[i][a] = 0;
}

/*
void	restore_piece()
{

}*/

void	print_bits(int n)
{
	int i;
	int arr[32];

	i = 0;
	while (i < 32)
	{
		arr[i] = (n & 1);
		ft_putnbr(arr[i]);
		n = n >> 1;
		i++;
	}
	ft_putchar('\n');
}
