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
	char	*line;
	int		**bin_arr;
	char	***arr;

	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		exit(1);
	}
	line = NULL;
	bin_arr = (int **)malloc(sizeof(int *) * 26);
	arr = (char ***)malloc(sizeof(char **) * 26);
	if (arr == NULL || bin_arr == NULL)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error();
	piece_count = read_input(fd, arr, line);
	if (piece_count == -1)
		print_error();
	solve_map(bin_arr, convert_to_binary(arr, bin_arr, piece_count));
	return (0);
}
