/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:23:54 by dancuenc          #+#    #+#             */
/*   Updated: 2025/03/13 15:14:29 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *count)
{
	if (nb == INT_MIN)
	{
		ft_print_s("-2147483648", count);
		return ;
	}
	if (nb < 0)
	{
		ft_print_c('-', count);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, count);
	}
	ft_print_c((nb % 10) + '0', count);
	return ;
}
