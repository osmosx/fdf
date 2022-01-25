NAME	= fdf
#
SRCS	=	main.c \
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c
#
HEADER	= fdf.h
#
FLAGS	= -Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit
#
.PHONY : all clean fclean re
#
all: $(NAME)
#
$(NAME) : $(SRCS) $(HEADER)
	@$(CC) $(FLAGS) $(SRCS) -o $(NAME)
	@echo "\033[32m\033[40m\033[1m[fdf compiled]"
#
clean:
		@$(RM) $(NAME)
		@echo "\033[31m\033[40m\033[1m[all clean]"
#
fclean: clean
#
re: fclean all