/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:40:29 by dancuenc          #+#    #+#             */
/*   Updated: 2025/03/17 18:36:38 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_is(va_list args, char format, int *count)
{
	if (format == 'c')
		ft_print_c(va_arg(args, int), count);
	else if (format == 's')
		ft_print_s(va_arg(args, char *), count);
	else if (format == 'p')
		ft_print_p(va_arg(args, void *), count);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (format == 'u')
		ft_print_u(va_arg(args, unsigned int), count);
	else if (format == 'x')
		ft_print_x_minus(va_arg(args, unsigned int), count);
	else if (format == 'X')
		ft_print_x_mayus(va_arg(args, unsigned int), count);
	else if (format == '%')
		ft_print_c('%', count);
	return (*count);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str)
				format_is(args, *str++, &count);
		}
		else
		{
			write(1, str++, 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
