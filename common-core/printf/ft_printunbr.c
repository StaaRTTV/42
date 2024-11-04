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

static int	ft_unbr_rec(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
	{
		len += ft_unbr_rec(nb / 10);
	}
	ft_printchar((nb % 10) + '0');
	len++;
	return (len);
}

int	ft_printunbr(va_list args)
{
	int	len;
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	len = 0;
	len += ft_unbr_rec(nb);
	return (len);
}
