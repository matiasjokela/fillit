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
	restart_piece(bin_arr, map, i, side_len);
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
		pop_piece(map, bin_arr, i, side_len);
		if (move_piece(bin_arr, map, i, side_len) == 0)
		{
			restore_piece(bin_arr, i);
			return (0);
		}
	
	}
	return (1);
}

void	skip_row(int **bin_arr, int *map, int i, int side_len)
{
	int	a;
	int	tmp;
	int temp;

	a = 0;
	tmp = ~map[a] << (sizeof(int) * 8 - side_len);
	temp = ~map[a + 1] << (sizeof(int) * 8 - side_len);

	
	while ((tmp & temp) == 0 && (a + 3) <= side_len)
	{
		if (move_to_next_row(bin_arr, i, side_len, map) == 0)
			return ;
		a++;
		tmp = ~map[a] << (sizeof(int) * 8 - side_len);
		temp = ~map[a + 1] << (sizeof(int) * 8 - side_len);
		/*printf("map:\n");
		for (int p = 0; p < 19; p++)
		{
			print_bits(map[p]);
		}
		printf("piece:\n");
		for (int p = 0; p < 19; p++)
		{
			
			print_bits(bin_arr[i][p]);
			
		}
		sleep(1);*/
	}
		


	// print_bits(tmp);
	// print_bits(temp);
	// printf("\n");
	// sleep(1);
	
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

	j = 0;
	if ((map[0] & bin_arr[i][0]) != 0 || (map[1] & bin_arr[i][1]) != 0 || \
		(map[2] & bin_arr[i][2]) != 0 || (map[3] & bin_arr[i][3]) != 0 || \
		(map[4] & bin_arr[i][4]) != 0 || (map[5] & bin_arr[i][5]) != 0 || \
		(map[6] & bin_arr[i][6]) != 0 || (map[7] & bin_arr[i][7]) != 0 || \
		(map[8] & bin_arr[i][8]) != 0 || \
		(map[9] & bin_arr[i][9]) != 0 || (map[10] & bin_arr[i][10]) != 0 || \
		(map[11] & bin_arr[i][11]) != 0 || (map[12] & bin_arr[i][12]) != 0 || \
		(map[13] & bin_arr[i][13]) != 0 || (map[14] & bin_arr[i][14]) != 0)
	{
		return (0);
	}
	/*while (j < side_len)
	{
		if ((map[j] & bin_arr[i][j]) != 0)
			return (0);
		j++;
	}
	j = 0;*/
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
	int	m;
	(void)map;

	j = 0;
	m = 1 << side_len;

	if ((bin_arr[i][0] << 1 & m) != 0 || (bin_arr[i][1] << 1 & m) != 0 || \
		(bin_arr[i][2] << 1 & m) != 0 || (bin_arr[i][3] << 1 & m) != 0 || \
		(bin_arr[i][4] << 1 & m) != 0 || (bin_arr[i][5] << 1 & m) != 0 || \
		(bin_arr[i][6] << 1 & m) != 0 || (bin_arr[i][7] << 1 & m) != 0 || \
		(bin_arr[i][8] << 1 & m) != 0 || (bin_arr[i][9] << 1 & m) != 0 || \
		(bin_arr[i][10] << 1 & m) != 0 || (bin_arr[i][11] << 1 & m) != 0 || \
		(bin_arr[i][12] << 1 & m) != 0 || (bin_arr[i][13] << 1 & m) != 0)
		{
			return (move_to_next_row(bin_arr, i, side_len, map));
		}
	bin_arr[i][0] = bin_arr[i][0] << 1;
	bin_arr[i][1] = bin_arr[i][1] << 1;
	bin_arr[i][2] = bin_arr[i][2] << 1;
	bin_arr[i][3] = bin_arr[i][3] << 1;
	bin_arr[i][4] = bin_arr[i][4] << 1;
	bin_arr[i][5] = bin_arr[i][5] << 1;
	bin_arr[i][6] = bin_arr[i][6] << 1;
	bin_arr[i][7] = bin_arr[i][7] << 1;
	bin_arr[i][8] = bin_arr[i][8] << 1;
	bin_arr[i][9] = bin_arr[i][9] << 1;
	bin_arr[i][10] = bin_arr[i][10] << 1;
	bin_arr[i][11] = bin_arr[i][11] << 1;
	bin_arr[i][12] = bin_arr[i][12] << 1;
	bin_arr[i][13] = bin_arr[i][13] << 1;

	// while (j < side_len)
	// {
	// 	// Check if piece is out of bounds without moving it yet
	// 	/*if ((bin_arr[i][j] << 1 & m) != 0)
	// 		return (move_to_next_row(bin_arr, i, side_len, map));
	// 	else*/
	// 		bin_arr[i][j] = bin_arr[i][j] << 1;
	// 	j++;
	// }

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
			break ;
		}
		a++;
	}
	if (bin_arr[i][side_len] != 0)
		return (0);
	while ((map[a + 1] ^ MAX << (side_len + 1)) == -1)
	{
		while (a < 13)
		{
			if (bin_arr[i][a] != 0)
			{
				bin_arr[i][a] = 0;
				bin_arr[i][a + 1] = bin_arr[i][20];
				bin_arr[i][a + 2] = bin_arr[i][21];
				bin_arr[i][a + 3] = bin_arr[i][22];
				bin_arr[i][a + 4] = bin_arr[i][23];
				a++;
				break ;
			}
			a++;
		}
		if (bin_arr[i][side_len] != 0)
			return (0);
	}
	return (1);
}


void	restore_piece(int **bin_arr, int i)
{
	bin_arr[i][0] = bin_arr[i][20];
	bin_arr[i][1] = bin_arr[i][21];
	bin_arr[i][2] = bin_arr[i][22];
	bin_arr[i][3] = bin_arr[i][23];
	bin_arr[i][4] = 0;
	bin_arr[i][5] = 0;
	bin_arr[i][6] = 0;
	bin_arr[i][7] = 0;
	bin_arr[i][8] = 0;
	bin_arr[i][9] = 0;
	bin_arr[i][10] = 0;
	bin_arr[i][11] = 0;
	bin_arr[i][12] = 0;
}

void	pop_piece(int *map, int **bin_arr, int i, int side_len)
{
	int a;

	a = 0;
	while (a < side_len)
	{
		map[a] -= bin_arr[i][a];
		a++;
	}
}

void	restart_piece(int **bin_arr, int *map, int i, int side_len)
{
	int	a;
	int	b;
	(void)map;
	(void)side_len;

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
