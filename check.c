/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:10:39 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/07 17:45:21 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (check_str(argv[i]) == 0)
			return (ft_putstr_fd("Error\n", 2), 0);
		i++;
	}
	return (1);
}

/* This function will check the string or argument passed, will return
 * 1 if the string is only formed by digits, if it finds a non-digit it
 * will return 0. */
int	check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/*This function checks if the numbers inside the stack are organized 
 * from smallest to greatest. Returns a 1 if they are organized or a 
 * 0 if they are NOT organized.*/
int	organized(t_list **stack)
{
	t_list	*curr;
	t_list	*next;

	curr = *stack;
	if (!curr || (curr && !(curr->next)))
		return (0);
	next = curr->next;
	while (curr && next)
	{
		if (curr->index > next->index)
			return (0);
		curr = next;
		next = next->next;
	}
	return (1);
}

/* This function will check the content of each node, it will return
 * a 0 if there's repeated numbers. */
int	check_repeat(t_list	**stack)
{
	t_list	*curr;
	t_list	*repeat;

	curr = *stack;
	if (!check_limits(stack))
		return (0);
	repeat = (*stack)->next;
	while (curr && repeat)
	{
		while (repeat != NULL)
		{
			if (curr->data == repeat->data)
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			repeat = repeat->next;
		}
		curr = curr->next;
		repeat = curr->next;
	}
	return (1);
}

/* This function checks the whole stack and returns a 0 if the data inside
 * the node surpasses the INT_MAX or INT_MIN limits. */
int	check_limits(t_list **stack)
{
	t_list	*curr;

	curr = *stack;
	while (curr)
	{
		if (curr->data > 2147483647 || curr->data < -2147483648)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		curr = curr->next;
	}
	return (1);
}
