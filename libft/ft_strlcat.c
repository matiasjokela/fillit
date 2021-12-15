/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:04:57 by mjokela           #+#    #+#             */
/*   Updated: 2021/11/15 11:05:13 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t dstsize)
{
	long int	i;
	long int	j;
	long int	k;
	long int	n;

	i = ft_strlen(dst);
	j = 0;
	n = dstsize - i - 1;
	k = i + ft_strlen(src);
	if (n < 0)
		return (ft_strlen(src) + dstsize);
	while ((src[j] != 0) && j < n)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return ((size_t)(k));
}
