/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:17:49 by Julian            #+#    #+#             */
/*   Updated: 2020/06/30 08:31:30 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	printf_choice(const char *str, va_list args, int n, int flags[7])
{
	if (str[n + flags[0] + 1] == 'c')
		return (ft_putchar_fd((char)va_arg(args, int), 1, flags));
	else if (str[n + flags[0] + 1] == 's')
		return (ft_putstr_fd((char *)va_arg(args, char *), 1, flags));
	else if (str[n + flags[0] + 1] == 'p')
	{
		if (!flags[2] && !flags[3] && !flags[4] && !flags[5] && flags[1])
			flags[1]--;
		return (ft_puthexa_pointer_fd((unsigned long)va_arg(args, void *)
, 1, flags));
	}
	else if (str[n + flags[0] + 1] == 'i' || str[n + flags[0] + 1] == 'd')
		return (ft_putint_fd((int)va_arg(args, int), 1, flags));
	else if (str[n + flags[0] + 1] == 'u')
		return (ft_putuint_fd((unsigned int)
					va_arg(args, unsigned int), 1, flags));
	else if (str[n + flags[0] + 1] == 'x')
		return (ft_puthexa_fd((unsigned int)va_arg(args, int), 1, flags));
	else if (str[n + flags[0] + 1] == 'X')
		return (ft_puthexa_cap_fd((unsigned int)va_arg(args, int), 1, flags));
	else
		return (ft_putchar_fd(str[n + flags[0] + 1], 1, flags));
	return (0);
}

int	while_part3(const char *str, int *n, int flags[7])
{
	if (str[*n + flags[0]] == '-' && ++flags[2])
		flags[3] = 0;
	if (str[*n + flags[0]] == '0' && ++flags[3]
				&& str[*n + flags[0] - 1] == '.')
		flags[6] = 0 + 0 * --flags[3];
	if ((str[*n + flags[0]] != '0' ||
	str[*n + flags[0] - 1] == '.') && ft_isdigit(str[*n + flags[0]]))
	{
		if (str[*n + flags[0] - 1] == '.')
			flags[6] = ft_atoi(&str[*n + flags[0]]);
		else
		{
			if (str[*n + flags[0] - 1] != '0')
				flags[3] = 0;
			flags[1] = ft_atoi(&str[*n + flags[0]]);
		}
		while (str[*n + flags[0]] && ft_isdigit(str[*n + flags[0]]))
			flags[0]++;
	}
	else
		flags[0]++;
	return (0);
}

int	while_part2(const char *str, va_list args, int *n, int flags[7])
{
	int				nega;

	nega = 0;
	if (str[*n + flags[0]] == '.' && ++flags[4])
		flags[6] = 0;
	if (str[*n + flags[0]] == '*' && ++flags[5])
	{
		if (str[*n + flags[0] - 1] == '.')
		{
			flags[6] = va_arg(args, int);
			if ((unsigned int)flags[6] > (unsigned int)flags[1] && flags[6] < 0)
				flags[4] = (flags[3]) ? 0 : flags[4];
			nega = (!flags[6]) ? 1 : 0;
		}
		else
		{
			flags[3] = (str[*n + flags[0] - 1] != '0') ? 0 : flags[3];
			flags[1] = va_arg(args, int);
		}
	}
	return (nega + while_part3(str, n, flags));
}

int	while_part1(const char *str, va_list args, int *n, int flags[7])
{
	int				nega;

	nega = 0;
	while (nega < 8)
		flags[nega++] = 0;
	if (str[*n] != '%')
		return (ft_putchar_fd(str[*n], 1, NULL));
	nega = 0;
	flags[0] = 1;
	while (str[*n + flags[0]] && (str[*n + flags[0]] == '-' ||
str[*n + flags[0]] == '0' || str[*n + flags[0]] == '.' ||
str[*n + flags[0]] == '*' || ft_isdigit(str[*n + flags[0]])))
		nega = while_part2(str, args, n, flags);
	flags[0]--;
	nega = (!flags[6] && flags[4]) ? 1 : nega;
	flags[6] = (flags[1] < 0 && ++flags[2] && flags[6] < 0) ? 0 : flags[6];
	flags[6] = (flags[6] < 0) ? -flags[6] : flags[6];
	flags[1] = (flags[1] < 0) ? -flags[1] : flags[1];
	flags[6] = (nega) ? -1 : flags[6];
	if (str[*n + flags[0]] && str[*n + flags[0] + 1])
		nega = printf_choice(str, args, *n, flags);
	*n = *n + flags[0] + 1;
	return (nega);
}

int	ft_printf(const char *str, ...)
{
	int				n;
	int				ret;
	int				size;
	int				flags[7];
	va_list			args;

	n = -1;
	ret = 0;
	va_start(args, str);
	size = ft_strlen(str);
	while (++n < size)
		ret += while_part1(str, args, &n, flags);
	va_end(args);
	return (ret);
}
