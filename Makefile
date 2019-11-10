# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 00:44:58 by iuolo             #+#    #+#              #
#    Updated: 2019/11/07 00:48:41 by iuolo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = valid.c newmain.c brute_force.c solution.c

OFILES = SRC(.c=.o)

all: $(NAME)

$(NAME):
		gcc -o fillit $(SRC) -I fillit.h libft/libft.a

clean:
		rm -rf *.o

fclean:
		rm -rf fillit

re: fclean all
