/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:30:43 by mjokela           #+#    #+#             */
/*   Updated: 2021/12/21 15:30:46 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	convert_to_binary(char ***arr, int **bin_arr, int piece_count)
{

	int		i;
	int		j;
	int		bin;

	i = 0;
	while (i < piece_count)
	{
		j = 0;
		bin_arr[i] = (int *)malloc(sizeof(int *) * 24);
		if (bin_arr[i] == NULL)
			exit(-1); // free all
		while (j < 4)
		{
			bin = 0;
			if (arr[i][j][0] != '.')
				bin += 1;
			if (arr[i][j][1] != '.')
				bin += 2;
			if (arr[i][j][2] != '.')
				bin += 4;
			if (arr[i][j][3] != '.')
				bin += 8;
			bin_arr[i][j] = bin;
			bin_arr[i][j + 20] = bin;
			j++;
		}			
		i++;
	}
	bin_arr[0][24] = piece_count;
	return (i);
}
