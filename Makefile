NAME = fdf

SRC = fdf.c draws.c rotation.c adjust.c tools.c key_fun.c helper.c coords.c \
		color_parse.c

INCLUDE = fdf.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):  $(OBJ)
	make -C ./libft/
	gcc -Wextra -Wall $(OBJ) -lmlx -framework OpenGL -framework AppKit ./libft/libft.a -o $(NAME)
	
%.o: %.c
	gcc -c -Wextra -Wall -o $@ $<

clean:
	rm -f $(OBJ)
	
fclean : clean
	rm -f $(NAME)
	
re: fclean all
