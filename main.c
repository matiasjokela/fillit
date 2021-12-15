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
	char	***arr;

	arr = (char ***)malloc(sizeof(char **) * 26);
	if (argc != 2 || arr == NULL)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || read_input(fd, arr) == -1)
		return (-1);
	

	printf("%p\n", arr);
	printf("%p\n", *arr);
	printf("%p\n", **arr);


}
