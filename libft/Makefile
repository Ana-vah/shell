# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 09:44:36 by vdescamp          #+#    #+#              #
#    Updated: 2023/04/26 11:33:12 by vdescamp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_realloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strcmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strmapi.c \
		ft_striteri.c \

SRCSBONUS =	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \


OBJS = ${SRCS:.c=.o}

OBJSBONUS = $(SRCSBONUS:.c=.o)

NAME = libft.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

bonus:    $(OBJSBONUS)
		ar rc $(NAME) $(OBJSBONUS)

all: ${NAME}

clean:
	${RM} ${OBJS} $(OBJSBONUS)

fclean: clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re
