/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:28:39 by gpochon           #+#    #+#             */
/*   Updated: 2024/10/21 11:05:50 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_bzero(void *ptr, size_t len)
{
	ft_memset(ptr, 0, len);
	return (ptr);
}
/*
int	main(void)
{
	char str[50] = "nique ta mère simon";

	printf("output: %s\n",str);
	ft_bzero(str, 10);
	printf("output: %s\n",str);
	return (0);
}
*/
