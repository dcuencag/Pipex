/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:28:20 by dancuenc          #+#    #+#             */
/*   Updated: 2025/03/17 18:35:40 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_p(void *format, int *count)
{
	long int	address;

	if (!format)
	{
		ft_print_s("(nil)", count);
		return ;
	}
	address = (unsigned long)format;
	ft_print_s("0x", count);
	ft_putnbr_base(address, BASE_LOWER, count);
}
