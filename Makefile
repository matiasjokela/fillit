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
SRCS = 

HEADER = fillit.h
O_FILES = 

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRSC) -L. -lft $(HEADER) $(SRCS);
	ar rc $(NAME) $(O_FILES);
	ranlib $(NAME);

clean:
	rm -f $(O_FILES)  libft.h.gch;

fclean:	
	rm -f $(O_FILES) $(NAME) libft.h.gch;

re: fclean all

