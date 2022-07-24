# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psafflow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/05 16:30:59 by psafflow          #+#    #+#              #
#    Updated: 2020/15/28 11:11:57 by psafflow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

C_FILES=ft_memcpy.c ft_memccpy.c ft_memset.c ft_bzero.c ft_memmove.c\
		ft_memcmp.c ft_memchr.c ft_strlen.c ft_isalpha.c ft_isdigit.c\
		ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
		ft_strchr.c ft_strrchr.c ft_strlcat.c ft_strlcpy.c ft_atoi.c\
		ft_strnstr.c ft_strncmp.c ft_calloc.c ft_strdup.c ft_substr.c\
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

INCLUDES = $(NAME:.a=.h)
O_FILES = $(C_FILES:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(O_FILES) $(INCLUDES)
	ar -rcs $(NAME) $(O_FILES)

%.o: %.c $(INCLUDES)
	gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	/bin/rm -f $(O_FILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
