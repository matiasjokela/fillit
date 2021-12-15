/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:43:22 by mjokela           #+#    #+#             */
/*   Updated: 2021/11/15 12:43:29 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trim;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	trim = (char *)malloc(ft_strlen(s) + 1);
	i = 0;
	j = 0;
	k = 0;
	while (s[i++] != '\0')
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t' && s[i] != '\0')
			k = i;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && k != 0)
		i++;
	trim = (char *)malloc(k - i + 1);
	if (trim == NULL)
		return (NULL);
	while (i <= k && k != 0)
		trim[j++] = s[i++];
	trim[j] = '\0';
	return (trim);
}
