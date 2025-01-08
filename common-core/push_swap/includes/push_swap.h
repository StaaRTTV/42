/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:59:14 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/08 14:58:39 by gpochon          ###   ########.fr       */
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
char	**single_arg(char *av);
void	check_mlt_args(int ac, char **av);
void	free_tab(char **tab);
void	dup_check(char **tab, int which);
int		ft_strisdigit(char *str);

#endif
