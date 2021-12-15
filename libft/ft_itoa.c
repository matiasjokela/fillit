/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:50:14 by mjokela           #+#    #+#             */
/*   Updated: 2021/11/18 10:50:20 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int			i;
	int			j;
	long int	k;
	char		*stri;

	i = ft_intlen(n);
	j = 0;
	k = n;
	stri = (char *)malloc(sizeof(char) * i + 1);
	if (stri == NULL)
		return (NULL);
	stri[i--] = '\0';
	if (k < 0)
	{
		stri[0] = '-';
		k *= -1;
	}
	while (k / 10 != 0)
	{
		stri[i] = k % 10 + '0';
		k = k / 10;
		i--;
	}
	stri[i--] = k % 10 + '0';
	return (stri);
}
