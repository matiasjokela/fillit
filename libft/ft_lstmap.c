/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:15:45 by mjokela           #+#    #+#             */
/*   Updated: 2021/11/22 13:15:56 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*tmp;

	tmp = f(lst);
	if (tmp == NULL || f == NULL)
		return (NULL);
	fresh = tmp;
	while (lst->next != NULL)
	{
		tmp->next = f(lst->next);
		if (tmp->next == NULL)
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (fresh);
}
