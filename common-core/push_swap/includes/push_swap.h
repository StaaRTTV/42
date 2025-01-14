/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:59:14 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/14 15:57:56 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int *stack_a;
	int *stack_b;
	int size_a;
	int size_b;
	int pivot;
} t_stack;

typedef enum e_stack_id
{
	STACK_A,
	STACK_B
} t_stack_id;

void	push_a(t_stack *stacks);
void	push_b(t_stack *stacks);
void	quicksort(t_stack *stacks);
void	swap(t_stack *stacks, t_stack_id dest);
void	ss_swap(t_stack *stacks);
void	rot(t_stack *stacks, t_stack_id which);
void	rrot(t_stack *stacks, t_stack_id which);
void	rr(t_stack *stacks);
void    sort_3_elements(t_stack *stacks);
void	printstack(t_stack *stacks);
void	rrr(t_stack *stacks);
void	is_sorted(t_stack *stacks);
void	ft_error(char *str);
int		*tabatoi(char **table, int which, int *size_a);
int		*init_stack_b(int *stack_a, int size_a, t_stack *stacks);
int		*init_stack_a(int ac, char **av, int *size_a);
char	**single_arg(char **av);
void	check_mlt_args(int ac, char **av);
void	free_tab(char **tab);
void	dup_check(char **tab, int which);
int		ft_strisdigit(char *str);

#endif