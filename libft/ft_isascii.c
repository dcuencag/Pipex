/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:18:13 by dancuenc          #+#    #+#             */
/*   Updated: 2025/02/04 12:31:58 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Detects if c is an ascii character
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
