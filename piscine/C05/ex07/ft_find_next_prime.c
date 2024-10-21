/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:02:41 by gpochon           #+#    #+#             */
/*   Updated: 2024/09/21 13:05:14 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_find_next_prime(int nb)
{
	int	div;
	int	prime;

	if (nb <= 1)
		return (2);
	while (1)
	{
		div = 2;
		prime = 1;
		while (div <= nb / div)
		{
			if (nb % div == 0)
			{
				prime = 0;
				break ;
			}
			div++;
		}
		if (prime == 1)
			return (nb);
		nb++;
	}
	return (0);
}
