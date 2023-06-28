# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 12:15:23 by vdescamp          #+#    #+#              #
#    Updated: 2023/06/16 13:38:46 by vdescamp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
OPT		= -lreadline
SRCS	= 		srcs/main.c						\
				srcs/prompt.c					\
				srcs/parsing/parsing.c			\
				srcs/parsing/tokenizer.c		\
				srcs/parsing/token_utils.c		\
				srcs/parsing/redirections.c		\
				srcs/parsing/meta_char.c		\
				srcs/parsing/meta_quotes.c		\
				srcs/parsing/meta_pipe.c		\
				srcs/parsing/meta_redirections.c\
				srcs/execution/path_control.c	\
				srcs/execution/execute_pipex.c	\
				srcs/execution/execution.c		\
				srcs/execution/exec_with_redirection.c		\
				srcs/builtins/check_builtins.c	\
				srcs/builtins/cd_builtin.c		\
				srcs/builtins/echo_builtin.c	\
				srcs/builtins/env_builtin.c		\
				srcs/builtins/exit_builtin.c	\
				srcs/builtins/export_builtin.c	\
				srcs/builtins/pwd_builtin.c		\
				srcs/builtins/unset_builtin.c	\
				srcs/environment/env_ctrl.c		\
				srcs/environment/env_value.c	\
				libft/ft_strcmp.c				\
				libft/ft_strncmp.c				\
				libft/ft_strtok.c				\
				libft/ft_strchr.c				\
				libft/ft_realloc.c			\
				libft/ft_strdup.c		\
				libft/ft_split.c			\
				libft/ft_isspace.c				\
				libft/ft_strjoin.c			\
				libft/ft_strlen.c		\
				libft/ft_strlcat.c			\
				libft/ft_strlcpy.c				\
				libft/ft_strnstr.c			\
				libft/ft_substr.c		\
				libft/ft_calloc.c			\
				libft/ft_strcat.c				\
				libft/ft_bzero.c			\
				libft/ft_strtrim.c		\
				libft/ft_memcpy.c

OBJS	= $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

NC			= \033[0m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN 		= \033[1;36m
RM			= rm -f

${NAME}:	${OBJS}
			${CC} ${OPT} ${FLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} *.o */*.o */*/*.o

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
