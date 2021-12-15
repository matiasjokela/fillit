/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:07:01 by mjokela           #+#    #+#             */
/*   Updated: 2021/11/15 11:07:08 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	size_t	i;
	size_t	j;

	if (hay == NULL || nee == NULL)
		return (NULL);
	i = 0;
	j = (size_t)ft_strlen(nee);
	if (nee[0] == '\0')
		return ((char *)hay);
	while (hay[i] != '\0' && i < len)
	{
		if (hay[i] == nee[0])
		{
			if ((i + j) > len)
				return (NULL);
			else if (ft_strncmp((char *)&(hay[i]), nee, j) == 0)
				return ((char *)&(hay[i]));
		}
		i++;
	}
	return (NULL);
}
