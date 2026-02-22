/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:34:48 by dancuenc          #+#    #+#             */
/*   Updated: 2025/03/17 18:21:49 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long nbr, char *base, int *count)
{
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16, base, count);
	ft_print_c(base[nbr % 16], count);
}
