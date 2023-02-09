# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 10:51:32 by nomoulin          #+#    #+#              #
#    Updated: 2023/02/01 12:01:31 by nomoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

BASE_DIR = srcs/base
PRINTF_DIR = srcs/ft_printf

all:
	@make -C $(BASE_DIR)
	@make -C $(PRINTF_DIR)
	$(AR) $(NAME) $(BASE_DIR)/objs/*.o $(PRINTF_DIR)/objs/*.o

clean:
	@make clean -C $(BASE_DIR)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
