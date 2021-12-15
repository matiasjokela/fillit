/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:44:16 by mjokela           #+#    #+#             */
/*   Updated: 2021/11/18 12:44:19 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*cont;

	new = (t_list *)malloc(sizeof(t_list));
	cont = (void *)malloc(content_size);
	if (new == NULL || cont == NULL)
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
	}
	else
	{
		ft_memcpy(cont, content, content_size);
		new->content = cont;
		new->content_size = content_size;
		new->next = NULL;
	}
	return (new);
}
