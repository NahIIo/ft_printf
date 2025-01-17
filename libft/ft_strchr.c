/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:22:02 by Julian            #+#    #+#             */
/*   Updated: 2020/03/05 17:22:03 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *p;

	p = (char *)s;
	while (*p != '\0')
	{
		if (*p == c)
			return (p);
		p++;
	}
	if (*p == c)
		return (p);
	return (0);
}
