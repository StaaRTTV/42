/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:59:11 by gpochon           #+#    #+#             */
/*   Updated: 2024/10/09 16:27:10 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int i)
{
	const char	*c;

	c = NULL;
	while (*str != '\0')
	{
		if (*str == (char)i)
			c = str;
		str++;
	}
	if (i == '\0')
		return ((char *)str);
	return ((char *)c);
}
