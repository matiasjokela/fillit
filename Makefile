# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjokela <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 14:17:46 by mjokela           #+#    #+#              #
#    Updated: 2022/01/18 14:17:51 by mjokela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = align_pieces.c binary.c end_game.c main.c piece_manipulation.c \
plant_piece.c read_input.c solver.c
LIBFT = libft/libft.a
O_FILES = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(O_FILES) $(LIBFT)
	gcc -Wall -Wextra -Werror -o $@ $^

$(LIBFT):
	$(MAKE) -C libft

clean:
	$(MAKE) -C libft clean
	rm -f $(O_FILES)

fclean:	
	$(MAKE) -C libft fclean
	rm -f $(O_FILES) $(NAME)

re: fclean all
