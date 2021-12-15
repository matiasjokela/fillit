/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:11:46 by mjokela           #+#    #+#             */
/*   Updated: 2021/11/10 12:11:49 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*buf;

	if (dst == NULL || src == NULL)
		return (NULL);
	buf = (unsigned char *)(malloc(sizeof(char) * len + 1));
	if (buf == NULL)
		return (NULL);
	ft_memcpy((char *)buf, src, len);
	ft_memcpy((char *)dst, (char const *)buf, len);
	free(buf);
	return (dst);
}
