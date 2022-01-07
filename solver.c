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

	while (1)
	{
		while (plant_piece(bin_arr, map, i, side_len) == 0)
		{
			if (move_piece(bin_arr, map, i, side_len) == 0)
			{
				restore_piece(bin_arr, i);
				return (0);
			}
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

void	show_output(int **bin_arr, int side_len)
{
	char	solution[side_len][side_len];
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < side_len)
	{
		j = 0;
		while (j < side_len)
		{
			solution[i][j] = '.';
			j++;
		}
		i++;
	}
	i = 0;
	while (i < bin_arr[0][24])
	{
		j = 0;
		while (j < side_len)
		{
			k = 0;
			while (k < side_len)
			{
				if ((bin_arr[i][j] & 1) == 1)
					solution[j][k] = i + 'A';
				bin_arr[i][j] = bin_arr[i][j] >> 1;
				k++;
			}
			j++;
		}
		i++;
	}		
	i = 0;
	while (i < side_len)
	{
		j = 0;
		while (j < side_len)
		{
			ft_putchar(solution[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

/* Plants piece to next available space, 
returns 1 if piece can be planted and 0 if not*/
int	plant_piece(int **bin_arr, int *map, int i, int side_len)
{
	int	j;
	int	b;

	j = 0;
	b = 1;
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
