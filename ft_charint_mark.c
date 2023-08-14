/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charint_mark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:12:49 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/06 16:14:46 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_charint_mark(int c, int *i, int *printed, char ioc)
{
	if (ioc == 'c')
		pft_putchar_fd(c, 1, printed);
	else if (ioc == 'n')
		pft_putnbr_fd(c, 1, printed);
	else if (ioc == 'u')
		pft_putun_nbr_fd((unsigned int)c, 1, printed);
	(*i) += 2;
}
