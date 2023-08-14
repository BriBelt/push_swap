/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_movements2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:53:47 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/06 17:25:30 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapforboth(t_list **lst)
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
}

void	ss(t_list **A, t_list **B)
{
	swapforboth(A);
	swapforboth(B);
	ft_printf("ss\n");
}

void	rr(t_list **A, t_list **B)
{
	rotate_forreverse(A);
	rotate_forreverse(B);
	ft_printf("rr\n");
}

void	rrr(t_list **A, t_list **B)
{
	t_list	*last;
	t_list	*ptr;

	ptr = *A;
	last = lstlast(ptr);
	while (*A != last)
		rotate_forreverse(A);
	ptr = *B;
	last = lstlast(ptr);
	while (*B != last)
		rotate_forreverse(B);
	ft_printf("rrr\n");
}
