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
	plant_piece(bin_arr, map, 1, side_len);
	while (move_piece(bin_arr, map, 1, side_len))
	{
		plant_piece(bin_arr, map, 1, side_len);
		for (int i = 0; i < 15; i++)
			print_bits(map[i]);
		//sleep(1);
		printf("\n");
	}
	restore_piece(bin_arr, 1);
	pop_piece(map, bin_arr, 0);

	printf("\n");
	for (int i = 0; i < 26; i++)
		print_bits(map[i]);
	/*for (int i = 0; i < 15; i++)
		print_bits(map[i]);	
	for (int i = 0; i < 15; i++)
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
	int	j;
	int	b;

	j = 0;
	b = 1;
	/*while (j < side_len)
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
	j = 0;*/
	while (j < side_len)
	{
		if ((map[j] & bin_arr[i][j]) != 0)
			b = 0;
		j++;
	}
	if (b == 1)
	{
		j = 0;
		while (j < side_len)
		{
			map[j] += bin_arr[i][j];
			j++;
		}	
	}
	return (b);
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
			return (move_to_next_row(bin_arr, i, side_len));
		else
			bin_arr[i][j] = bin_arr[i][j] << 1;
		j++;
	}
	/*
	Still needs to check for out of bounds at the lower limit? Also needs to 
	move piece when it collides with another piece in the map
	*/
	return (1);
}

int	move_to_next_row(int **bin_arr, int i, int side_len)
{
	int	a;
	int b;

	a = 0;
	b = 0;

	
	while (a < 20)
	{
		if (bin_arr[i][a] != 0)
		{
			bin_arr[i][a] = 0;
			if (a + 1 < 20)
				bin_arr[i][a + 1] = bin_arr[i][20];
			if (a + 2 < 20)
				bin_arr[i][a + 2] = bin_arr[i][21];
			if (a + 3 < 20)
				bin_arr[i][a + 3] = bin_arr[i][22];
			if (a + 4 < 20)
				bin_arr[i][a + 4] = bin_arr[i][23];
			break ;
		}
		a++;
	}

	if (bin_arr[i][side_len] != 0)
		return (0);
	return (1);

}


void	restore_piece(int **bin_arr, int i)
{
	int	a;

	a = 0;
	while (a < 4)
	{
		bin_arr[i][a] = bin_arr[i][a + 20];
		a++;
	}
	while (a < 20)
	{
		bin_arr[i][a] = 0;
		a++;
	}	
}

void	pop_piece(int *map, int **bin_arr, int i)
{
	int a;

	a = 0;
	while (a < 20)
	{
		map[a] -= bin_arr[i][a];
		a++;
	}
}

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
