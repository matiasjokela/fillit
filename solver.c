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

char **solve_map(char **bin_arr, int piece_count)
{
	(void)piece_count;
	(void)bin_arr;

	int	*map;
	int	side_len;

	side_len = 2;
	map = (int *)malloc(sizeof(int) * 32);
	if (map == NULL)
		exit(-1);
	while (side_len * side_len < piece_count * 4)
		side_len++;
	give_map(map, side_len);
	for (int i = 0; i < 15; i++)
		print_bits(map[i]);

	//printf("%d\n", map[0] | bin_arr[0][0] | bin_arr[1][0] | bin_arr[2][0]);

	return (NULL);

}

void	give_map(int *map, int side_len)
{
	int	mask;
	int	i;

	mask = 1;
	i = 0;
	while (i < side_len)
	{
		mask *= 2;
		i++;
	}
	i = 0;
	while (i < side_len)
		map[i++] = mask;
	map[i] = MAX;

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
