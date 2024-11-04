/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:30:11 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/04 11:34:18 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_nbr_rec(int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
	{
		len += ft_nbr_rec(nb / 10);
	}
	ft_printchar((nb % 10) + '0');
	len++;
	return (len);
}

int	ft_printnbr(va_list args)
{
	int	len;
	int	nb;

	nb = va_arg(args, int);
	len = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		len = 11;
		return (len);
	}
	if (nb < 0)
	{
		ft_printchar('-');
		nb = -nb;
		len++;
	}
	len += ft_nbr_rec(nb);
	return (len);
}
