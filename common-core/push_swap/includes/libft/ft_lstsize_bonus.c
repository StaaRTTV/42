/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:54:00 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/06 14:48:11 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size_list;
	t_list	*actual;

	actual = lst;
	size_list = 0;
	while (actual != NULL)
	{
		size_list++;
		actual = actual->next;
	}
	return (size_list);
}
