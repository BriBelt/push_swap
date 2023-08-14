/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:05:12 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/07 17:59:57 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list **lst)
{
	t_list	*aux;

	while (*lst)
	{
		aux = *lst;
		*lst = (*lst)->next;
		free(aux);
	}
	free(lst);
}

void	free_array(char **array)
{
	int		i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		if (array[i][0] != '\0')
			free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

t_list	*create_node(long number)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->data = number;
	new->next = NULL;
	new->index = 0;
	new->pos = 0;
	return (new);
}

void	insert_node(t_list **head, long number)
{
	t_list	*ptr;
	t_list	*node;

	node = create_node(number);
	if (*head == NULL)
		*head = node;
	else
	{
		ptr = *head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = node;
	}
}

t_list	**create_stack(char **argv, int argc)
{
	t_list	**stack;
	int		i;
	int		j;
	char	**new;

	stack = malloc(sizeof(t_list *));
	if (!stack)
		return (0);
	*stack = NULL;
	i = 1;
	while (i < argc)
	{
		new = ft_split(argv[i], ' ');
		if (new && check_argv(new) == 0)
			return (free_array(new), free_list(stack), NULL);
		j = 0;
		while (new && check_argv(new) == 1 && new[j])
		{
			insert_node(stack, ft_atoi(new[j]));
			j++;
		}
		free_array(new);
		i++;
	}
	return (stack);
}
