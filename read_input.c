/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:31:39 by mjokela           #+#    #+#             */
/*   Updated: 2021/12/15 17:31:42 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_block_sides(char ***arr, int i, int j, int k)
{
	int	x;

	x = 0;
	if (j - 1 >= 0 && arr[i][j - 1][k] != '.')
        x++;
    if (j + 1 <= 3 && arr[i][j + 1][k] != '.')
        x++;
    if (k - 1 >= 0 && arr[i][j][k - 1] != '.')
        x++;
    if (k + 1 <= 3 && arr[i][j][k + 1] != '.')
        x++;
    return (x);
}

int	check_input(char ***arr, int i)
{
	int	j;
	int	k;
	int	empties;
	int	blocks;
	int	x;

	j = 0;
	empties = 0;
	blocks = 0;
	x = 0;
	while (j < 4)
		if (ft_strlen(arr[i][j++]) != 4)
			return (-1);
	j = 0;
	while (j < 4)
	{
		k = 0;
		while (k < 4)
		{
			if (arr[i][j][k] == '.')
				empties++;
			else if (arr[i][j][k] == '#')
			{
				blocks++;
				x += check_block_sides(arr, i, j, k);
				arr[i][j][k] = i + 'A';
			}
			k++;
		}
		j++;
	}
	if (x < 6 || empties != 12 || blocks != 4 || ft_strcmp(arr[i][4], "") != 0)
		return (-1);
	return (0);
}

int read_input(int fd, char ***arr)
{
	int		i;
	int		j;
	char	*line;
	int		get;

	i = 0;
	get = 1;
	
	while (i < 26 && get > 0)
	{
		arr[i] = (char **)malloc(sizeof(char *) * 5);
		if (arr[i] == NULL)
			exit(-1);
		j = 0;
		while (j < 5)
		{			
			get = get_next_line(fd, &line);
			if (get == -1)
				exit(-1);
			arr[i][j] = line;
			j++;
		}
		if (check_input(arr, i) == -1)
			return (-1);
		i++;
	}
	return (1);
}
