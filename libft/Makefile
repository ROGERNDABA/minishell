# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/21 22:58:58 by rmdaba            #+#    #+#              #
#*   Updated: 2018/07/16 12:52:08 by Roger            ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #


NAME = libft.a

FLAGS =-Wall -Wextra -Werror

HEADER = ./../incl/libft.h

SRCS = 	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
		ft_isblank.c ft_iscntrl.c ft_isdigit.c ft_isgraph.c ft_islower.c\
		ft_isprint.c ft_isspace.c ft_isupper.c ft_isxdigit.c ft_itoa.c\
		ft_itoa_base.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c\
		ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
		ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memdup.c ft_memmove.c\
		ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
		ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_str_is_alpha.c\
		ft_str_is_lowercase.c ft_str_is_numeric.c ft_str_is_printable.c ft_str_is_uppercase.c\
		ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c\
		ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c\
		ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c\
		ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c\
		ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c\
		ft_strtrim.c ft_tolower.c ft_toupper.c  ft_strcat.c\
		buffer.c ft_check_fmt.c ft_find_flag.c ft_print_error.c\
		ft_printf.c ft_printf_base.c ft_printf_base_tools.c\
		ft_printf_nbr.c ft_printf_nbr_tools.c ft_printf_putchar.c\
		ft_printf_string.c ft_printf_stringuni.c ft_printf_stringuni2.c\
		ft_putchar_uni.c ft_putchar_uni2.c ft_type.c ft_getchar.c ft_strspn.c\
		ft_strcspn.c ft_strtok.c get_next_line.c ft_strcjoin.c

OBJ = 	$(SRC:%.c=%.o)


all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(addprefix srcs/, $(SRCS))
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
	@printf "\e[32m[ ✔ ]libft library made\n"

clean:
	@rm -rf *.o
	@printf "\e[31m[ ✔ ] Libft object files removed\n\e[0m"

fclean: clean
	@rm -rf $(NAME)
	@printf "\e[33m[ ✔ ] Libft library removed\n\e[0m"

re: fclean all

.PHONY: all, clean, fclean, re
