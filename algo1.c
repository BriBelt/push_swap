/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:28:42 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/06 15:26:54 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function will work only for stacks with size of <= 10. 
 * It's purpose is to take the smallest number (already defined 
 * by their index) determine if it's better to move it up or down 
 * until it reaches the top of stack_a and next push it to the top
 * of stack_b. */
void	sortalgo1(t_list **A, t_list **B)
{
	int		size;
	t_list	*node;

	size = lstsize(*A);
	while (lstsize(*A) > 5 && organized(A) == 0)
	{
		put_position(A);
		node = find_node(A, find_min(A, size));
		move_top(A, node, 'a');
		push(A, B, 'b');
	}
	if (lstsize(*A) <= 5 && !organized(A))
		sort_five(A, B);
	move_back(A, B);
}
