NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror 

RM = rm -f

SRC = helper.c \
      sort_A.c\
      push_B_to_A.c\
      push_swap.c \
      push.c \
      reverse_rotate.c \
      rotate.c \
      split.c \
      swap.c \
      valide_args.c \
      sort.c\
      big_sort.c\
      lst_func.c

OBJ = $(SRC:.c=.o)

BONUS = checker

BONUS_SRC = bonus/checker.c\
            bonus/get_next_line_utils.c \
            bonus/get_next_line.c \
            bonus/helper_bonus.c \
            bonus/lst_helper.c \
            bonus/push_bonus.c \
            bonus/reverse_rotate_bonus.c \
            bonus/rotate_bonus.c \
            bonus/split_bonus.c \
            bonus/swap_bonus.c \
            bonus/helper2_bonus.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(BONUS)

$(BONUS) : $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS)

clean : 
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean : clean
	$(RM) $(NAME) $(BONUS)

re : fclean all

.PHONY : all clean fclean re bonus