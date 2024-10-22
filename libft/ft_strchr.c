/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:36:00 by gpochon           #+#    #+#             */
/*   Updated: 2024/10/22 09:36:11 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int i)
{
	while (*str != '\0')
	{
		if (*str == (char)i)
			return ((char *)str);
		str++;
	}
	if (i == '\0')
		return ((char *)str);
	return (NULL);
}
