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

#include <fillit.h>

int		align_pieces(char ***arr, int i)
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
	return (1);
}

int		check_row(char ***arr, int index)
{
	int k;

	k = 0;
	while (arr[index][0][k])
	{
		if (arr[index][0][k] != '.')
			return (0);
		k++;
	}
	return (1);
}

int		check_col(char ***arr, int index)
{
	int j;

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
	while (j < 3)
	{
		k = 0;
		while (arr[index][j][k])
		{
			arr[index][j][k] =  arr[index][j + 1][k];
			k++;
		}
	j++;
	}
	k = 0;

}

void	move_col(char ***arr, int index)
{
	
}
