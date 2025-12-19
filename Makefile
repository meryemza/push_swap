NAME = push_swap

SRC = helper.c \
      A_to_B.c\
      B_to_A.c\
      push_swap.c \
      push.c \
      reverse_rotate.c \
      rotate.c \
      split.c \
      swap.c \
      valide_args.c \
      sort.c\
      helper_B_to_A.c\
      big_sort.c\

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