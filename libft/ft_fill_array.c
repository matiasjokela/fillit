/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:07:42 by mjokela           #+#    #+#             */
/*   Updated: 2021/11/23 11:17:10 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fill_array(char **arr, char const *s, char c, int size)
{
	int	i;
	int	j;
	int	r;

	i = -1;
	r = 0;
	while (s[++i] != '\0')
	{
		j = 0;
		if ((s[i] != c && i == 0) || (s[i] != c && s[i - 1] == c))
		{
			arr[r] = (char *)malloc(sizeof(char) * ft_dstrlen(&(s[i]), c) + 1);
			if (arr[r] == NULL)
			{
				ft_free_array(arr, size);
				return (-1);
			}		
			while (s[i] != c && s[i] != '\0')
				arr[r][j++] = s[i++];
			i--;
			arr[r++][j] = '\0';
		}
	}
	return (0);
}
