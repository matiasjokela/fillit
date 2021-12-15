/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:08:15 by mjokela           #+#    #+#             */
/*   Updated: 2021/11/15 11:08:19 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	if (size == 0)
	{
		new = (char *)malloc(1);
		new[0] = '\0';
		return (new);
	}
	return ((char *)ft_memalloc(size + 1));
}
