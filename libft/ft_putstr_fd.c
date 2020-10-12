/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:21:48 by Julian            #+#    #+#             */
/*   Updated: 2020/06/30 08:31:41 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_str(int size, char *s, int flags[7])
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	size = (flags[6] < 0) ? 0 : size;
	if (!flags[2] && flags[1] && !flags[3])
		while (!flags[2] && i++ < flags[1] -
			((flags[6] > 0 && flags[6] < size) ? (flags[6]) : size))
			ret += (int)write(flags[5], " ", 1);
	if (!flags[2] && flags[1] && (flags[3]))
		while (i++ < (int)flags[1] -
		((flags[6] > 0 && flags[6] < size) ? (flags[6]) : size))
			ret += (int)write(flags[5], "0", 1);
	i = 0;
	while (s && *s && ((flags[6]) ? (i++ < flags[6]) : 1))
		ret += (int)write(flags[5], s++, 1);
	i = ret;
	while (flags[2] && i++ < flags[1])
		ret += (int)write(flags[5], " ", 1);
	return (ret);
}

int		ft_putstr_fd(char *s, int fd, int flags[7])
{
	int size;
	int ret;

	if (!s)
		s = "(null)\0";
	size = ft_strlen(s);
	ret = 0;
	if (flags)
	{
		flags[5] = fd;
		ret += print_str(size, s, flags);
	}
	else
		while (*s)
			if ((ret += (int)write(fd, s++, 1)) < 0)
				return (ret);
	return (ret);
}
