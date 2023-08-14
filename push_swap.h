/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:31:31 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/07 18:03:49 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_list
{
	long			data;
	int				index;
	int				pos;
	struct s_list	*next;
}					t_list;

/* push_swap */
void	start_sort(t_list **A, t_list **B);
int		find_index(t_list **stack_a, int position);
/* push_swap_utils */
t_list	*lstlast(t_list	*lst);
int		lstsize(t_list	*lst);
int		find_max(t_list	**stack, int size);
int		find_min(t_list	**stack, int size);
t_list	*find_node(t_list **stack, int node_index);
/* check */
int		check_argv(char **argv);
int		check_str(char *str);
int		organized(t_list **stack);
int		check_repeat(t_list	**stack);
int		check_limits(t_list **stack);
/* create */
void	free_list(t_list **lst);
void	free_array(char **array);
t_list	*create_node(long number);
void	insert_node(t_list **head, long number);
t_list	**create_stack(char **argv, int argc);
/* sort */
void	move_top(t_list **stack, t_list *node, char c);
void	check_chunk(t_list **A, t_list **B, int key);
void	index_list(t_list **stack);
void	put_position(t_list **stack);
int		find_position(t_list **stack, int index);
/* push_swap_movements */
void	swap(t_list	**lst, char c);
void	push(t_list	**src, t_list **dest, char c);
void	rotate(t_list **lst, char c);
void	rotate_forreverse(t_list **lst);
void	reverse_rotate(t_list **lst, char c);
/* push_swap_movements2 */
void	swapforboth(t_list **lst);
void	ss(t_list **A, t_list **B);
void	rr(t_list **A, t_list **B);
void	rrr(t_list **A, t_list **B);
/* algo0, Stack  sort (stack <= 3) */
void	sortalgo0(t_list **stack, char c);
void	sort_five(t_list **A, t_list **B);
/* algo1, Stack sort (stack <= 10) */
void	sortalgo1(t_list **A, t_list **B);
/* algo2, Stack sort (stack > 10 && stack <= 100) */
void	sortalgo2(t_list **A, t_list **B);
void	sortchunks(t_list **A, t_list **B);
void	move_back(t_list **A, t_list **B);
int		check_small(t_list **stack, int key_num);
/* algo3, Stack sort (stack > 100) */
void	sortalgo3(t_list **A, t_list **B);
void	look_for_less(t_list **A, t_list **B, int key);
/* libft_utils.c && libft_utils2.c */
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_putstr_fd(char *s, int fd);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int c);
/* Ft_printf */
int		ft_printf(char const *format, ...);
void	pft_putchar_fd(char c, int fd, int *printed);
void	pft_putstr_fd(char *s, int fd, int *printed);
void	pft_putnbr_fd(long n, int fd, int *printed);
void	pft_putun_nbr_fd(long n, int fd, int *printed);
void	pft_putnbr_hex_fd(unsigned long n, int fd, char c, int *printed);
void	ft_charint_mark(int c, int *i, int *printed, char ioc);

#endif
