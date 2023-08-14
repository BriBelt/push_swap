NAME = push_swap

SRCS = push_swap.c \
	   main.c \
	   create.c \
	   check.c \
	   push_swap_movements.c \
	   push_swap_movements2.c \
	   sort.c \
	   algo0.c \
	   algo1.c \
	   algo2.c \
	   algo3.c \
	   push_swap_utils.c \
	   ft_atoi.c \
	   ft_split.c \
	   libft_utils.c \
	   libft_utils2.c \
	   ft_charint_mark.c \
	   ft_printf.c \
	   ft_printf_utils.c

OBJECTS = $(SRCS:.c=.o)

CC = gcc

CFLAGS += -Wall -Wextra -Werror

LEAKFLAGS += -Wall -Wextra -Werror -g3 -fsanitize=address

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	gcc  $(CFLAGS) $(OBJECTS) -o $(NAME) 

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
