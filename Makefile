SRC = aux_handle_s.c \
	  aux_handle_u.c \
	  ft_printf.c \

NAME = libftprintf.a

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR =  ar
ARFLAGS = rcs

all:$(NAME)
$(NAME):$(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: clean fclean all re
