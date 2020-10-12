/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:19:52 by Julian            #+#    #+#             */
/*   Updated: 2020/03/05 17:19:52 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *next;
	t_list *curr;

	curr = *lst;
	if (curr)
	{
		while (curr->next)
		{
			curr = *lst;
			del(curr->content);
			next = curr->next;
			free(curr);
			*lst = NULL;
			*lst = next;
		}
	}
}
