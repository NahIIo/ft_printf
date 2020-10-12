/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:20:25 by Julian            #+#    #+#             */
/*   Updated: 2020/03/05 17:20:26 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *pt;

	pt = (unsigned char *)s;
	while (n--)
		if (*pt == (unsigned char)c)
			return (pt);
		else
			pt++;
	return (0);
}
