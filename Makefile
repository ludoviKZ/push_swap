FILES = push_swap.c stackuse.c stackuseutils.c smartmoves.c validateutils.c validate.c rotate.c rrotate.c sorting.c sortingutils.c swap.c  push.c
OBJ = $(FILES:.c=.o)
NAME = push_swap
LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a
CFLAGS = -Wall -Wextra -Werror -g
CC = cc
RM = rm -f

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c -o $@ $<

all: addlibs $(NAME)

addlibs:
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)
	
clean:
	make -C $(LIBFT_PATH) clean
	${RM} $(OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re
