/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:08:19 by dancuenc          #+#    #+#             */
/*   Updated: 2025/03/17 18:28:45 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define BASE_UPPER "0123456789ABCDEF"
# define BASE_LOWER "0123456789abcdef"

int		ft_printf(char const *str, ...);

void	ft_print_c(char c, int *count);

void	ft_print_s(char *str, int *count);

void	ft_print_p(void *format, int *count);

void	ft_print_u(unsigned int nbr, int *count);

void	ft_print_x_minus(unsigned int nbr, int *count);

void	ft_print_x_mayus(unsigned int nbr, int *count);

void	ft_putnbr(int nb, int *count);

void	ft_putnbr_base(unsigned long nbr, char *base, int *count);

#endif
