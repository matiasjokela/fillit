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
				bin_arr[i][j] = bin_arr[i][j] >> 1; // This is why the print doesn't work
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
	char *colors[26] = {
		"\033[31m", // Red
		"\033[32m", // Green
		"\033[33m", // Yellow
		"\033[34m", // Blue
		"\033[35m", // Magenta
		"\033[36m", // Cyan
		"\033[1;31m", // Bold Red
		"\033[1;32m", // Bold Green
		"\033[1;33m", // Bold Yellow
		"\033[1;34m", // Bold Blue
		"\033[1;35m", // Bold Magenta
		"\033[1;36m", // Bold Cyan
		"\033[37m", // White
		"\033[30m", // Black
		"\033[90m", // Bright Black
		"\033[91m", // Bright Red
		"\033[92m", // Bright Green
		"\033[93m", // Bright Yellow
		"\033[94m", // Bright Blue
		"\033[95m", // Bright Magenta
		"\033[96m", // Bright Cyan
		"\033[97m", // Bright White
		"\033[1;37m", // Bold White
		"\033[1;30m",  // Bold Black
		"\033[31m", // Red
		"\033[32m" // Green
	};

	while (i < side_len)
	{
		j = 0;

		while (j < side_len)
		{
			if (solution[i][j] != '.')
				ft_putstr(colors[solution[i][j] - 'A']);
			ft_putchar(solution[i][j]);
			ft_putstr("\033[0m");
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
