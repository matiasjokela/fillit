/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:49:50 by mjokela           #+#    #+#             */
/*   Updated: 2021/11/18 10:49:55 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		size;

	size = ft_count_delimited_words(s, c);
	arr = (char **)malloc(sizeof(char *) * size + 1);
	if (arr == NULL || s == NULL)
		return (NULL);
	arr[size] = NULL;
	if (ft_fill_array(arr, s, c, size) == -1)
		return (NULL);
	return (arr);
}
