/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:09:05 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/18 17:30:11 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


t_chunk	*create_chunk(int *sort_tab, int nbchunk, int size)
{
	t_chunk	*chunk;
	int		i;
	int		chunk_size;

	i = 0;
	chunk = malloc(sizeof(t_chunk) * nbchunk);
	if (!chunk)
		return (NULL);
	chunk_size = size / nbchunk;
	while (i < chunk_size)
	{
		chunk[i].min = sort_tab[i * nbchunk];
		if (i == nbchunk - 1)
			chunk[i].max = sort_tab[size - 1];
		else
			chunk[i].max = sort_tab[(i + 1) * nbchunk - 1];
		i++;
	}
	return (chunk);
}
void push_all_chunks(t_stack *stacks, t_chunk *chunks, int nbchunk)
{
	int i;
	int count;

	i = 0;
	while (i < nbchunk)
	{
		count = stacks->size_a;
		while (count > 0)
		{
			if (stacks->stack_a[0] >= chunks[i].min && stacks->stack_a[0] <= chunks[i].max)
				push_b(stacks);
			else
				rot(stacks, STACK_A);
			count--;
		}
		i++;
	}
}
int getmax(int *tab, int size)
{
	int i;
	int max;

	i = 0;
	max = tab[0];
	while (i < size)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int	get_max_pos(t_stack *stacks)
{
	int i;
	int max;
	int pos;

	i = 0;
	max = getmax(&stacks->size_b, stacks->size_b);
	while (i < stacks->size_a)
	{
		if (stacks->stack_a[i] == max)
			pos = i;
		i++;
	}
	return (pos);
}
void	chunk_sort(t_stack *stacks)
{
	int *sortedtab;
	int chunknb;
	t_chunk *chunks;

	sortedtab = sort_int_tab(stacks->stack_a, stacks->size_a);
	chunknb = 10;
	chunks = create_chunk(sortedtab, chunknb, stacks->size_a);
	if (!chunks)
	{
		free (chunks);
		ft_error("✖ Chunk creation failed ✖\n");
	}
	push_all_chunks(stacks, chunks, chunknb);
	push_back_btoa(stacks);
	free (chunks);
	free (sortedtab);
}

void push_back_btoa(t_stack *stacks)
{
	int pos;

	while (stacks->stack_b)
	{
		pos = get_max_pos(stacks);
		if (pos <= stacks->size_b / 2)
		{
			while (pos > 0)
			{
				rot(stacks, STACK_B);
				pos--;
			}
		}
		else
		{
			while (pos < stacks->size_b)
			{
				rrot(stacks, STACK_B);
				pos++;
			}
		}
		push_a(stacks);
	}
}
