NAME = push_swap
AR_NAME = push_swap.a
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a
SRCS = src/push_swap.c src/sort_stack.c src/init_a_to_b.c src/init_b_to_a.c \
src/utils/check.c src/utils/find_node.c src/utils/free_and_error.c \
src/utils/utils.c src/utils/stack_utils.c src/moves/push.c src/moves/swap.c \
src/moves/rotate.c src/moves/rev_rotate.c src/split.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	cc $(CFLAGS) -I $(LIBFT_PATH) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -s -C $(LIBFT_PATH)

$(AR_NAME): $(LIBFT) $(OBJS)
	$(AR) $(AR_NAME) $(OBJS)

clean:
	make -s -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)
	
fclean: clean
	make -s -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	$(RM) $(AR_NAME)

re: fclean all

.PHONY: all clean fclean re
