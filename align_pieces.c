/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:49:12 by mjokela           #+#    #+#             */
/*   Updated: 2021/12/17 13:49:17 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	align_pieces(char ***arr, int i)
{
	int	arr_index;

	arr_index = 0;
	while (arr_index < i)
	{
		while (check_row(arr, arr_index) == 1)
			move_row(arr, arr_index);
		while (check_col(arr, arr_index) == 1)
			move_col(arr, arr_index);
		arr_index++;
	}
	return (arr_index);
}

int	check_row(char ***arr, int index)
{
	int	k;

	k = 0;
	while (arr[index][0][k])
	{
		if (arr[index][0][k] != '.')
			return (0);
		k++;
	}
	return (1);
}

int	check_col(char ***arr, int index)
{
	int	j;

	j = 0;
	while (arr[index][j][0])
	{
		if (arr[index][j][0] != '.')
			return (0);
		j++;
	}
	return (1);
}

void	move_row(char ***arr, int index)
{
	int	j;
	int	k;

	j = 0;
	while (j < 4)
	{
		k = 0;
		while (arr[index][j][k])
		{
			arr[index][j][k] = arr[index][j + 1][k];
			k++;
		}
	j++;
	}
	k = 0;
	while (k < 4)
		arr[index][3][k++] = '.';
}

void	move_col(char ***arr, int index)
{
	int	j;
	int	k;

	k = 0;
	while (k < 4)
	{
		j = 0;
		while (j < 4)
		{
			arr[index][j][k] = arr[index][j][k + 1];
			j++;
		}
	k++;
	}
	j = 0;
	while (j < 4)
		arr[index][j++][3] = '.';
}
