/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:22:38 by Julian            #+#    #+#             */
/*   Updated: 2020/03/05 17:22:39 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (i < (int)len && haystack[i] != '\0')
	{
		temp = i;
		while (needle[j] == haystack[i] &&
			needle[j] != '\0' && haystack[i] != '\0' && i < (int)len)
		{
			j++;
			i++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[temp]);
		i = temp + 1;
		j = 0;
	}
	return (0);
}
