NAME = libftprintf.a

SRC = ft_printf.c \
      ft_putchar.c \
      ft_putstr.c \
      ft_putnbr.c \
      ft_putnbr_uns.c \
      ft_putnbr_hex.c \
      ft_putptr.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus