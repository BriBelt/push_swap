/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:54:21 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/07 17:59:38 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	a = NULL;
	b = NULL;
	if (argc <= 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	if (argc > 1)
	{
		a = create_stack(argv, argc);
		b = malloc(sizeof(t_list *));
		*b = NULL;
	}
	if (a && *a)
	{
		start_sort(a, b);
		free_list(a);
		free_list(b);
	}
	else
	{
		free(a);
		free(b);
	}
	return (0);
}
