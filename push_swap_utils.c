/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:12:15 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/06 15:29:53 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lstlast(t_list	*lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	lstsize(t_list *lst)
{
	int		i;
	t_list	*curr;

	curr = lst;
	i = 0;
	if (!curr)
		return (0);
	while (curr)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

int	find_max(t_list	**stack, int size)
{
	t_list	*curr;
	int		max;
	int		i;

	curr = *stack;
	i = 0;
	max = curr->index;
	while (curr && i <= size)
	{
		if (curr->index > max)
			max = curr->index;
		curr = curr->next;
		i++;
	}
	return (max);
}

int	find_min(t_list	**stack, int size)
{
	t_list	*curr;
	int		min;
	int		i;

	min = find_max(stack, size);
	curr = *stack;
	i = 0;
	while (curr && i <= size)
	{
		if (curr->index < min)
			min = curr->index;
		curr = curr->next;
		i++;
	}
	return (min);
}

t_list	*find_node(t_list **stack, int node_index)
{
	t_list	*node;

	node = *stack;
	while (node && node->index != node_index)
		node = node->next;
	return (node);
}
