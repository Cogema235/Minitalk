# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 14:06:17 by nomoulin          #+#    #+#              #
#    Updated: 2023/02/01 15:12:34 by nomoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = client jsp main
SRCS = $(addsuffix .c, $(CFILES))
OBJS = $(addsuffix .o, $(CFILES))

CODE_DIR = .
SRCS_DIR = $(CODE_DIR)/srcs
OBJS_DIR = $(CODE_DIR)/objs

SRCS_PATHS = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS_PATHS = $(addprefix $(OBJS_DIR)/, $(OBJS))

CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME = client

LIBFT_PATH = ../../libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS_DIR) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS_PATHS) $(LIBFT) -o $(NAME)
		@clear

%.o : $(SRCS_DIR)/%.c
	$(CC) -c $< $(CFLAGS) -o $(OBJS_DIR)/$@

$(LIBFT) :
	@make -C $(LIBFT_PATH)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

clean : 
	@rm -rf $(OBJS_DIR)
	@clear

fclean : clean
	rm -f $(NAME)
	@clear

re : fclean all

.PHONY : all clean fclean re