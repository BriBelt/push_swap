/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:21:09 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/06 15:22:00 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function sorts stacks <= 3 */
void	sortalgo0(t_list **stack, char c)
{
	int		size;
	int		max_index;
	t_list	*big;

	size = lstsize(*stack);
	max_index = find_max(stack, size);
	if (size == 1)
		return ;
	else if (size == 2 && organized(stack) == 0)
		swap(stack, c);
	else if (size == 3)
	{
		big = find_node(stack, max_index);
		if (*stack == big)
			rotate(stack, c);
		else if ((*stack)->next == big)
			reverse_rotate(stack, c);
		if ((*stack)->index > (*stack)->next->index)
			swap(stack, c);
	}
}

void	sort_five(t_list **A, t_list **B)
{
	int		min_index;
	t_list	*small;

	while (*A && lstsize(*A) > 3 && !organized(A))
	{
		min_index = find_min(A, lstsize(*A));
		small = find_node(A, min_index);
		move_top(A, small, 'a');
		push(A, B, 'b');
	}
	if (!organized(A))
		sortalgo0(A, 'a');
	move_back(A, B);
}
