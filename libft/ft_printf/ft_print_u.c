/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:30:46 by dancuenc          #+#    #+#             */
/*   Updated: 2025/03/13 13:33:12 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_u(unsigned int nbr, int *count)
{
	if (nbr > 9)
	{
		ft_print_u(nbr / 10, count);
	}
	ft_print_c(nbr % 10 + '0', count);
}
