# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/19 19:17:17 by rmdaba            #+#    #+#              #
#    Updated: 2018/07/19 19:17:34 by rmdaba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRCS = minishell.c commands.c builtins.c bonus.c manage_functions.c \
		cd_builtin.c env_builtin.c
OBJ = $(SRCS:.c=.o)
CC = gcc
FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@(cd libft && make)
	@$(CC) -c $(FLAG) $(addprefix srcs/, $(SRCS))
	@$(CC) -o $(NAME) $(OBJ) libft/libft.a
	@printf "\e[32m[ ✔ ] Excecutable minishel made\n"

clean:
	@(cd libft && make clean)
	@rm -f $(OBJ)
	@printf "\e[31m[ ✔ ] Minishell Object files removed\n\e[0m"

fclean: clean
	@(cd libft && make fclean)
	@rm -f $(NAME)
	@printf "\e[33m[ ✔ ] Minishell removed\n\e[0m"

re: fclean all
