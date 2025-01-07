/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:59:14 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/07 14:14:49 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct ps_list
{
	void			*data;
	struct ps_list	*prev;
	struct ps_list	*next;
}	tps_list;

void	ft_error(char *str);
void	single_arg(char *av);
void	multiple_args(int ac, char **av);
void	free_tab(char **tab);
int		ft_strisdigit(char *str);

#endif
