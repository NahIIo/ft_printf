/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:21:17 by Julian            #+#    #+#             */
/*   Updated: 2020/06/30 08:31:24 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putchar_fd(char c, int fd, int flags[7])
{
	int ret;
	int i;

	ret = 0;
	i = 1;
	if (flags && (flags[6] || flags[1]) && !flags[2])
	{
		if (flags[1] && !flags[3])
			while (i++ < (int)flags[1])
				ret += (int)write(fd, " ", 1);
		if (flags[1] && (flags[3]))
			while (i++ < (int)flags[1])
				ret += (int)write(fd, "0", 1);
	}
	ret += (int)write(fd, &c, 1);
	if (flags && flags[1] && flags[2])
		while (i++ < (int)flags[1])
			ret += (int)write(fd, " ", 1);
	return (ret);
}
