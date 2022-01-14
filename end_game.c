/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:48:22 by mjokela           #+#    #+#             */
/*   Updated: 2022/01/14 17:48:24 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	show_output(int **bin_arr, int side_len)
{
	char	solution[14][14];
	int		i;
	int		j;

	i = 0;
	while (i < 14)
	{
		j = 0;
		while (j < 14)
		{
			solution[i][j] = '.';
			j++;
		}
		i++;
	}
	fill_solved_map(bin_arr, side_len, solution);
}

void	fill_solved_map(int **bin_arr, int side_len, char solution[][14])
{
	int	i;
	int	j;
	int	k;

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
	print_map(side_len, solution);
	exit(0);
}

void	print_map(int side_len, char solution[][14])
{
	int	i;
	int	j;

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

void	print_error(void)
{
	ft_putstr("error\n");
	exit(-1);
}
