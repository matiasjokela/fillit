/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:06:33 by mjokela           #+#    #+#             */
/*   Updated: 2021/11/15 11:06:43 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			j = i + 1;
			k = 1;
			while (1)
			{
				if (needle[k] == '\0')
					return ((char *)&(haystack[i]));
				if (haystack[j++] != needle[k++])
					break ;
			}
		}
		i++;
	}
	return (NULL);
}
