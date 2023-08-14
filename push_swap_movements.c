/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:34:34 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/06 16:25:42 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list	**lst, char c)
{
	t_list	*aux;
	t_list	*first;
	t_list	*second;

	if (!lst)
		return ;
	first = *lst;
	if (first->next == NULL)
		return ;
	second = first->next;
	if (!second)
		return ;
	aux = second->next;
	first->next = aux;
	second->next = first;
	*lst = second;
	ft_printf("s%c\n", c);
}

void	push(t_list	**src, t_list **dest, char c)
{
	t_list	*node_push;
	t_list	*ptr;
	t_list	*second;

	if (!src || !(*src))
		return ;
	node_push = *src;
	second = (*src)->next;
	node_push->next = NULL;
	*src = second;
	if (*dest == NULL)
		*dest = node_push;
	else
	{
		ptr = *dest;
		node_push->next = ptr;
		*dest = node_push;
	}
	ft_printf("p%c\n", c);
}

void	rotate(t_list **lst, char c)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;
	t_list	*aux;

	if (!lst)
		return ;
	first = *lst;
	aux = *lst;
	second = first->next;
	if (!second)
		return ;
	last = lstlast(aux);
	last->next = first;
	first->next = NULL;
	*lst = second;
	ft_printf("r%c\n", c);
}

void	rotate_forreverse(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;
	t_list	*aux;

	if (!lst)
		return ;
	first = *lst;
	aux = *lst;
	second = first->next;
	if (!second)
		return ;
	last = lstlast(aux);
	last->next = first;
	first->next = NULL;
	*lst = second;
}

void	reverse_rotate(t_list **lst, char c)
{
	t_list	*last;
	t_list	*ptr;

	ptr = *lst;
	last = lstlast(ptr);
	while (*lst != last)
		rotate_forreverse(lst);
	ft_printf("rr%c\n", c);
}
