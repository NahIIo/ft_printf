/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:22:18 by Julian            #+#    #+#             */
/*   Updated: 2020/03/05 17:22:19 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		l;

	k = 0;
	while (src[k])
		k++;
	if (dstsize == 0)
		return (k);
	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	l = i;
	j = 0;
	if (i < dstsize)
	{
		while (i < (dstsize - 1) && src[j])
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	if (dstsize - 1 < l)
		return (dstsize + k);
	return (k + l);
}
