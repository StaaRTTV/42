/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:48:57 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/06 14:41:34 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_comp;
	t_list	*temp;
	void	*new_cont;

	new_list = NULL;
	while (lst != NULL)
	{
		new_cont = f(lst->content);
		new_comp = ft_lstnew(new_cont);
		if (!new_comp)
		{
			while (new_list != NULL)
			{
				temp = new_list->next;
				ft_lstdelone(new_list, del);
				new_list = temp;
			}
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_comp);
		lst = lst->next;
	}
	return (new_list);
}
