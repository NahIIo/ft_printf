/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:21:44 by Julian            #+#    #+#             */
/*   Updated: 2020/06/30 08:31:36 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_int(int size, int n, char str[9], int flags[7])
{
	int i;
	int sign;
	int ret;

	sign = (n < 0) ? 1 : 0;
	ret = 0;
	i = 1;
	while (!flags[2] && (!flags[3] || flags[4]) && i++ <= (int)(flags[1] -
			(((flags[6] > size) ? flags[6] : size) + sign)))
		ret += ft_putchar_fd(' ', flags[5], NULL);
	ret += (sign) ? ft_putchar_fd('-', flags[5], NULL) : 0;
	if (!(i *= 0) && flags[1] && flags[3] && !flags[4] && !flags[2])
		while (++i <= (int)((flags[1] - (size + sign))))
			ret += ft_putchar_fd('0', flags[5], NULL);
	else if (flags[6])
		while (++i <= (int)((flags[6] - (size))))
			ret += ft_putchar_fd('0', flags[5], NULL);
	if (!(i *= 0) && (flags[6] != -1 || n != 0) && !(size *= 0))
		while (str[size])
			ret += ft_putchar_fd(str[size++], flags[5], NULL);
	flags[6] = ret;
	if (flags[2])
		while (++i <= (int)(flags[1] - flags[6]))
			ret += ft_putchar_fd(' ', flags[5], NULL);
	return (ret);
}

int		ft_putint_fd(int n, int fd, int flags[7])
{
	int				i;
	char			str[12];
	unsigned int	nnbr;
	int				size;

	size = 0;
	nnbr = n;
	nnbr = (n < 0) ? -nnbr : nnbr;
	while (nnbr)
		nnbr /= 10 + 0 * size++;
	nnbr = n;
	nnbr = (n < 0) ? -nnbr : nnbr;
	if (!size)
		str[size++] = '0';
	str[size] = '\0';
	i = size;
	while (i--)
	{
		str[i] = (nnbr % 10) + 48;
		nnbr /= 10;
	}
	flags[5] = fd;
	if (flags[6] < 0 && n == 0)
		size = 0;
	return (print_int(size, n, str, flags));
}
