/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:44:37 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/06 17:29:46 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortalgo3(t_list **A, t_list **B)
{
	t_list	*small;
	int		key;
	int		newkey;

	key = lstsize(*A) / 12 ;
	if (key * 12 > lstsize(*A))
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
