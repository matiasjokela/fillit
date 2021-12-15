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
			//printf("%s\n", line);
			j++;
			//sleep(1);
			arr[i][j] = line;

		}
		i++;
	}

	return (1);
}


