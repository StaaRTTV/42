/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:18:44 by gpochon           #+#    #+#             */
/*   Updated: 2024/09/18 09:25:28 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	total;

	total = 1;
	while (nb != '\0')
	{
		total *= nb;
		nb--;
	}
	return (total);
}
/*
int	main(void)
{
	printf("%d", ft_iterative_factorial(7));
	return (0);
}
*/
