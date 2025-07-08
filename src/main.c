/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:03:11 by dancuenc          #+#    #+#             */
/*   Updated: 2025/07/08 15:17:35 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 5)
	{
		ft_printf("hello world");
	}
	else if (ac != 5)
	{
		ft_printf("bye world");		
	}
	return (0);
}