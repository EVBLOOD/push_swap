# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 12:19:38 by sakllam           #+#    #+#              #
#    Updated: 2021/11/10 13:41:45 by sakllam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INC = libft.h
sources = ft_atoi.c\
		 ft_isalpha.c\
		 ft_isalpha.c\
		 ft_isalpha.c\
		 ft_itoa.c\
		 ft_itoa.c\
		 ft_itoa.c\
		 ft_memmove.c\
		 ft_memmove.c\
		 ft_memmove.c\
		 ft_putnbr_fd.c\
		 ft_putnbr_fd.c\
		 ft_putnbr_fd.c\
		 ft_strdup.c\
		 ft_strlcpy.c\
		 ft_strnstr.c\
		 ft_tolower.c\
		 ft_bzero.c\
		 ft_isascii.c\
		 ft_memchr.c\
		 ft_memset.c\
		 ft_putstr_fd.c\
		 ft_striteri.c\
		 ft_strlen.c\
		 ft_strrchr.c\
		 ft_toupper.c\
		 ft_calloc.c\
		 ft_isdigit.c\
		 ft_memcmp.c\
		 ft_putchar_fd.c\
		 ft_split.c\
		 ft_strjoin.c\
		 ft_strmapi.c\
		 ft_strtrim.c\
		 ft_isalnum.c\
		 ft_isprint.c\
		 ft_memcpy.c\
		 ft_putendl_fd.c\
		 ft_strchr.c\
		 ft_strlcat.c\
		 ft_strncmp.c\
		 ft_substr.c
bonussources =	ft_lstnew.c\
				ft_lstadd_front.c\
				ft_lstsize.c\
				ft_lstlast.c\
				ft_lstadd_back.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c
CFLAGS = -Wall -Werror -Wextra
object = $(sources:.c=.o)
bonusobject = $(bonussources:.c=.o)

all: $(NAME)
$(NAME): $(object) $(INC)
	gcc -c $(CFLAGS) $(sources) -I $(INC)
	@ar -rc $(NAME) $(object)
bonus: $(NAME) $(bonusobject)
	gcc -c $(CFLAGS) $(bonussources) -I $(INC)
	@ar -rc $(NAME) $(object) $(bonusobject)
clean:
	rm -f $(object) $(bonusobject)
fclean: clean
	rm -f $(NAME)
re: fclean all
