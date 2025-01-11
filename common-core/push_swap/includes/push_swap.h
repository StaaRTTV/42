/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:59:14 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/11 15:26:50 by gpochon          ###   ########.fr       */
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
int		*tabatoi(char **table, int which, int *size_a);
int		*init_stack_b(int size_a, int *stack_a);
int		*init_stack_a(int ac, char **av, int size_a);
char	**single_arg(char *av);
void	check_mlt_args(int ac, char **av);
void	free_tab(char **tab);
void	dup_check(char **tab, int which);
int		ft_strisdigit(char *str);

#endif
