NAME = push_swap
LIB = libpushswap.a
CFLAGS = -Wall -Wextra -Werror
LFLAG = -L. -lpushswap
SOURCE = ft_free.c \
		ft_check_arg.c \
		ft_split_space.c \
		ft_string.c \
		ft_heap_sort.c \
		ft_find_pop.c \
		ft_init.c \
		ft_under_five.c \
		ft_push_swap.c \
		ft_operation.c \
		ft_operate_s_p.c \
		ft_operate_r_rr.c
OBJECT = $(SOURCE:.c=.o)
MAIN = main.c

$(NAME): $(LIB) $(MAIN)
	gcc $(MAIN) $(CFLAGS) $(LFLAG) -o $(NAME)
$(LIB): $(OBJECT)
	ar rcs $(LIB) $(OBJECT)
$(OBJECT): $(SOURCE)
	gcc $(CFLAGS) -c $(SOURCE)

all : $(NAME)
clean:
	@rm -f $(OBJECT)
fclean: clean
	@rm -f $(LIB)
	@rm -f $(NAME)
re:	fclean all

.PHONY: all clean fclean re