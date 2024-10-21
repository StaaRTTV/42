/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:21:14 by gpochon           #+#    #+#             */
/*   Updated: 2024/10/06 21:41:34 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (len > i && s1[i] && s1[i] == s2[i])
		i++;
	if (i == len)
		return (0);
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
