NAME = BSQ

OBJ = main.o
SRC = main.c

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	gcc -o $(NAME) $(OBJ)

clean:
    rm -f $(OBJ)

fclean:
    rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re