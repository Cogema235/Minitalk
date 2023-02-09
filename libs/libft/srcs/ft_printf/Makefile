# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 10:51:32 by nomoulin          #+#    #+#              #
#    Updated: 2023/02/01 15:17:04 by nomoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = buffer cat ctoa ft_printf itoa lhextoa ptoa stoa uhextoa

SRCS = $(addsuffix .c, $(CFILES))
OBJS = $(addsuffix .o, $(CFILES))

CODE_DIR = .
SRCS_DIR = $(CODE_DIR)/srcs
OBJS_DIR = $(CODE_DIR)/objs

SRCS_PATHS = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS_PATHS = $(addprefix $(OBJS_DIR)/, $(OBJS))

CC = clang
CFLAGS = -Wall -Wextra -Werror

all : $(OBJS)

%.o : $(SRCS_DIR)/%.c $(OBJS_DIR)
	$(CC) -c $< $(CFLAGS) -o $(OBJS_DIR)/$@

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

clean : 
	rm -rf $(OBJS_DIR)

re : clean all

.PHONY : all clean re
