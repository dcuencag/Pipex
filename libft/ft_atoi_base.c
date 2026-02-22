/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:53:46 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/21 15:26:29 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(const char *str, int base)
{
	int		result;
	int		i;
	char	c;

	result = 0;
	i = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		i = 2;
	while (str[i])
	{
		c = str[i];
		if (c >= '0' && c <= '9')
			result = result * base + (c - '0');
		else if (c >= 'a' && c <= 'f')
			result = result * base + (c - 'a' + 10);
		else if (c >= 'A' && c <= 'F')
			result = result * base + (c - 'A' + 10);
		else
			break ;
		i++;
	}
	return (result);
}
