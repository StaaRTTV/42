/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:42:09 by gpochon           #+#    #+#             */
/*   Updated: 2024/10/22 09:51:53 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_memchr(const void* ptr, int ch, size_t count)
{
	const unsigned char	*str;
	size_t	i;
	
	str = (const unsigned char *)ptr;
	i = 0;
	while (i < count)
	{
		if (str[i] == (unsigned char)ch)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
