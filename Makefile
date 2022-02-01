# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 13:25:52 by nenvoy            #+#    #+#              #
#    Updated: 2022/02/01 13:25:56 by nenvoy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
#
SRCS	=	main.c \
			./gnl/get_next_line.c \
			./gnl/get_next_line_utils.c \
			read_file.c \
			split.c \
			minilib.c \
			utils.c \
			hook.c \
			draw.c \
			init.c
#
HEADER	= fdf.h
#
FLAGS	= -Wall -Werror -Wextra -g -Lmlx -lmlx -framework OpenGL -framework AppKit
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
