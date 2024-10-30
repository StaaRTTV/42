/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:26:12 by gpochon           #+#    #+#             */
/*   Updated: 2024/10/01 21:24:28 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	while (len--)
		((unsigned char *)ptr)[len] = (unsigned char)value;
	return (ptr);
}
/*
int    main(void)
{
    char str[50] = "nique ta mère simon";

    printf("output: %s\n",str);
    ft_memset(str, 'E', 10);
    printf("output: %s\n",str);
    return (0);
}
*/
