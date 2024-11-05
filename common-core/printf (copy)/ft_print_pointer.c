/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:38:55 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/05 11:38:47 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_nbr_base(int nb, char *base)
{
	if (nb >= 16)
		put_nbr_base(nb / 16, base);
	ft_print_char(base[nb % 16]);
}

int	ft_print_pointer(void *ptr)
{
	int	i;

	i = 0;
	write (1, "0x", 2);
	if (!ptr)
		return (i + write(1, "0", 1));
	put_nbr_base((unsigned long)ptr, "0123456789abcdef");
	return (i);
}
