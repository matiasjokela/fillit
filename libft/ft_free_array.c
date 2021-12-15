/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:17:29 by mjokela           #+#    #+#             */
/*   Updated: 2021/11/23 11:18:41 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char **arr, int size)
{
	int	index;

	index = size - 1;
	while (index >= 0)
	{
		free(arr[index]);
		index--;
	}
	free(arr);
}	
