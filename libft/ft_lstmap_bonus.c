/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:20:08 by Julian            #+#    #+#             */
/*   Updated: 2020/03/05 17:20:09 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list *new;
	t_list *next;
	t_list *start;

	if (!lst)
		return (0);
	if (!(new = malloc(sizeof(t_list))))
		return (0);
	new->content = f(lst->content);
	start = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(next = malloc(sizeof(t_list))))
			return (0);
		next->content = f(lst->content);
		new->next = next;
		new = new->next;
	}
	new->next = 0;
	return (start);
}
