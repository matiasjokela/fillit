/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:42:03 by mjokela           #+#    #+#             */
/*   Updated: 2021/12/15 17:42:07 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		piece_count;
	char	***arr;
	int		**bin_arr;

	arr = (char ***)malloc(sizeof(char **) * 26);
	bin_arr = (int **)malloc(sizeof(int *) * 26);
	if (argc != 2 || arr == NULL || bin_arr == NULL)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	piece_count = read_input(fd, arr);
	if (fd < 0 || piece_count == -1)
		return (-1);
	//convert_to_binary(arr, bin_arr, piece_count);
	solve_map(bin_arr, convert_to_binary(arr, bin_arr, piece_count));
/*
	for (int i = 0; i <= 'C' - 'A'; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%s\n", arr[i][j]);
	}

	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 24; j++)
			//printf("%d\n", bin_arr[i][j]);
			print_bits(bin_arr[i][j]);
		printf("\n");
	}
*/

	
	return (0);

}
