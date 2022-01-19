# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 22:13:55 by sakllam           #+#    #+#              #
#    Updated: 2022/01/19 23:08:53 by sakllam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
bonus = checker
INCLUDE = ./inc/push_swap.h
INCLUDE_BONUS = ./inc_bonus/push_swap.h
SRC = ./src/ft_bestmove.c \
		./src/ft_moveit.c\
		./src/ft_sorting.c\
		./src/ft_sorting_utils_3.c\
		./src/ft_stackman.c\
		./src/ft_bestmoveofi.c\
		./src/ft_movetoa.c\
		./src/ft_sorting_utils_1.c\
		./src/ft_sorttree.c\
		./src/ft_stackman_2.c\
		./src/ft_indexrotating.c\
		./src/ft_parsing.c\
		./src/ft_sorting_utils_2.c\
		./src/ft_stackcmds.c\
		./src/ft_stackman_3.c\
		./src/main.c
SRC_BONUS = ./bns/ft_norm.c\
		./bns/ft_parsing.c\
		./bns/ft_stackcmds.c\
		./bns/ft_stackman.c\
		./bns/ft_stackman_2.c\
		./bns/ft_stackman_3.c\
		./bns/main.c\
		./bns/get_next_line/get_next_line.c\
		./bns/get_next_line/get_next_line_utils.c
CFLAGS = -Wall -Werror -Wextra
all: $(NAME)
$(NAME): $(INCLUDE) $(SRC:.c=.o)
	(cd libft; make all;)
	gcc $(CFLAGS) libft/libft.a $(SRC) -I $(INCLUDE) -o $(NAME)
bonus: $(INCLUDE_BONUS) $(SRC_BONUS:.c=.o)
	(cd libft; make all;)
	gcc $(CFLAGS) libft/libft.a $(SRC_BONUS) -I $(INCLUDE_BONUS) -o $(bonus)
clean:
	(cd libft; make clean;)
	rm -f $(SRC:.c=.o) $(SRC_BONUS:.c=.o)
fclean: clean
	(cd libft; make fclean;)
	rm -f $(NAME) $(bonus) $(EXTOFILES)
re: fclean all
.PHONY: all clean fclean re