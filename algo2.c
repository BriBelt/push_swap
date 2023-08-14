/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:15:42 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/06 15:45:27 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function performs an algorithm that only works for stacks
 * that are greater than 10 and smaller or equal than 100. */
void	sortalgo2(t_list **A, t_list **B)
{
	t_list	*small;
	int		key;
	int		newkey;

	key = lstsize(*A) / 4;
	if (key * 4 > lstsize(*A))
		key++;
	newkey = 0;
	while (lstsize(*A) > key && !organized(A))
	{
		newkey += key;
		while (check_small(A, newkey) > 0 && lstsize(*A) > key)
		{
			small = *A;
			while (small && small->index > newkey)
				small = small->next;
			move_top(A, small, 'a');
			push(A, B, 'b');
		}
	}
	if (!organized(A))
		sortchunks(A, B);
	move_back(A, B);
}

void	sortchunks(t_list **A, t_list **B)
{
	t_list	*small;

	while ((*A && !organized(A)) && lstsize(*A) > 3)
	{
		put_position(A);
		small = find_node(A, find_min(A, lstsize(*A)));
		move_top(A, small, 'a');
		push(A, B, 'b');
	}
	if (lstsize(*A) <= 3)
		sortalgo0(A, 'a');
}

/* This function will iterate the stack until it finds the first 
 * node with a smaller index than the key_num, it will return 
 * the number of times it found a smaller node, if it doesn't find
 * a smaller node, returns 0. */
int	check_small(t_list **stack, int key_num)
{
	t_list	*curr;
	int		i;

	i = 0;
	curr = *stack;
	while (curr)
	{
		if (curr->index <= key_num)
			i++;
		curr = curr->next;
	}
	return (i);
}

/* This will push nodes from the stack src to the stack dest from smallest 
 * to greatest, uses the proximity method. */
void	move_back(t_list **A, t_list **B)
{
	t_list	*big;

	while (*B)
	{
		big = find_node(B, find_max(B, lstsize(*B)));
		move_top(B, big, 'b');
		push(B, A, 'a');
	}
}
