NAME = push_swap

SRC = ft_helper.c \
      ft_lst.c \
      push_swap.c \
      push.c \
      reverse_rotate.c \
      rotate.c \
      split.c \
      swap.c \
      valide_args.c \
      sort.c\

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean : 
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus