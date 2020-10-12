/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:21:32 by Julian            #+#    #+#             */
/*   Updated: 2020/06/30 08:31:43 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_hexa(int size, int n, char str[9], int flags[7])
{
	int i;
	int ret;

	ret = 0;
	i = 1;
	if (flags && !flags[2] && (!flags[3] || flags[4]))
		while (i++ <= (int)(flags[1] - ((flags[6] > size) ? flags[6] : size)))
			ret += ft_putchar_fd(' ', flags[5], NULL);
	i = 1;
	if (flags[6])
		while (i++ <= (int)((flags[6] - (size))))
			ret += ft_putchar_fd('0', flags[5], NULL);
	if (flags[1] && flags[3] && !flags[4])
		while (i++ <= (int)((flags[1] - (size))))
			ret += ft_putchar_fd('0', flags[5], NULL);
	if (!(i *= 0) && (flags[6] != -1 || n != 0) && !(size *= 0))
		while (str[size])
			ret += ft_putchar_fd(str[size++], flags[5], NULL);
	if (flags)
		flags[6] = ret;
	i = 0;
	if (flags && flags[2])
		while (++i <= (int)(flags[1] - flags[6]))
			ret += ft_putchar_fd(' ', flags[5], NULL);
	return (ret);
}

int		ft_puthexa_fd(unsigned int n, int fd, int flags[7])
{
	int				i;
	char			str[9];
	unsigned int	nnbr;
	int				size;

	size = 0;
	nnbr = n;
	while (n)
		n /= 16 + 0 * size++;
	if (!size)
		str[size++] = '0';
	str[size] = '\0';
	i = size;
	n = nnbr;
	while (i--)
	{
		if (nnbr % 16 < 10)
			str[i] = (nnbr % 16) + 48;
		else
			str[i] = (nnbr % 16) + (97 - 10);
		nnbr /= 16;
	}
	flags[5] = fd;
	size = (flags[6] < 0 && n == 0) ? 0 : size;
	return (print_hexa(size, n, str, flags));
}
