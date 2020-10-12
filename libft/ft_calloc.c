/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:18:53 by Julian            #+#    #+#             */
/*   Updated: 2020/03/05 17:18:54 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int			total;
	char		*c;
	void		*pt;
	void		*start;

	total = count * size;
	if (!(pt = malloc(total)))
		return (0);
	start = pt;
	while (total--)
	{
		c = (char *)pt;
		*c = 0;
		pt++;
	}
	return (start);
}
