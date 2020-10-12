/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:20:38 by Julian            #+#    #+#             */
/*   Updated: 2020/03/05 17:20:39 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int			i;
	char		cpy[len];
	char		*pt_src;
	char		*pt_dst;

	i = 0;
	pt_src = (char *)src;
	pt_dst = (char *)dst;
	while (i < (int)len)
		cpy[i++] = *pt_src++;
	i = 0;
	while (i < (int)len)
		*pt_dst++ = cpy[i++];
	return (dst);
}
