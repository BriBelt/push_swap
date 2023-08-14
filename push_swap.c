/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:15:44 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/06 16:01:33 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sort(t_list **A, t_list **B)
{
	index_list(A);
	put_position(A);
	if (check_repeat(A) == 0)
		return ;
	if (organized(A) == 1)
		return ;
	if (*A && organized(A) == 0)
	{
		if (lstsize(*A) <= 3)
			sortalgo0(A, 'a');
		else if (lstsize(*A) <= 5)
			sort_five(A, B);
		else if (lstsize(*A) > 5 && lstsize(*A) <= 10)
			sortalgo1(A, B);
		else if (lstsize(*A) > 10 && lstsize(*A) <= 100)
			sortalgo2(A, B);
		else if (lstsize(*A) > 100)
			sortalgo3(A, B);
	}
}

/* This will just find the index of the node in the indicated position. */
int	find_index(t_list **stack_a, int position)
{
	t_list	*curr;
	int		index;

	curr = *stack_a;
	index = 0;
	while (curr != NULL)
	{
		if (position == curr->pos)
			index = curr->index;
		curr = curr->next;
	}
	return (index);
}
