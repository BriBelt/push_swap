/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:17:16 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/06 15:56:52 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* movetop will do as its name says so, will repeat n times the movement
 * indicated by where (1 for rotate, 2 for reverse rotate) in stack A and
 * finally will do push into stack B. */
void	move_top(t_list **stack, t_list *node, char c)
{
	int		proximity;

	proximity = lstsize(*stack) / 2;
	put_position(stack);
	if (*stack == node)
		return ;
	else if ((*stack)->next == node)
		swap(stack, c);
	while (*stack != node)
	{
		if (proximity > node->pos)
			rotate(stack, c);
		else if (proximity <= node->pos)
			reverse_rotate(stack, c);
	}
}

/* This function assigns an index to each node, depending if the node
 * content is greater or smaller than the last one. It compares each 
 * number inside the node one by one and adds one to the index of the
 * greatest number.*/
void	index_list(t_list **stack)
{
	t_list	*curr;
	t_list	*compare;

	compare = *stack;
	while (compare != NULL)
	{
		curr = *stack;
		while (curr != NULL)
		{
			if (compare->data > curr->data)
				compare->index += 1;
			curr = curr->next;
		}
		compare = compare->next;
	}
}

/* This function assigns each node of the stack a position number. */
void	put_position(t_list **stack)
{
	int		position;
	t_list	*curr;

	position = 1;
	curr = *stack;
	while (curr != NULL)
	{
		curr->pos = position;
		position++;
		curr = curr->next;
	}
}

/* This function will find the position of the node with the indicated
 * index. */
int	find_position(t_list **stack, int index)
{
	t_list	*curr;
	int		position;

	position = 0;
	curr = *stack;
	while (curr != NULL)
	{
		if (index == curr->index)
		{
			position = curr->pos;
			break ;
		}
		curr = curr->next;
	}
	return (position);
}
