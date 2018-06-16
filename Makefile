# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarnett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/07 12:55:52 by abarnett          #+#    #+#              #
#    Updated: 2018/06/12 13:57:23 by abarnett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

p_NAME := fillit
l_NAME := libft.a
C_OBJS := $(patsubst %.c,%.o,$(wildcard ./*.c))
L_OBJS := $(patsubst %.c,%.o,$(wildcard ./libft/*.c))
INCLUDE_DIRS := ./libft
CFLAGS += -Wall -Wextra -Werror -I$(INCLUDE_DIRS)
LDFLAGS += -L./ -lft

.PHONY: all clean fclean re

all: $(l_NAME) $(p_NAME)
	./$(p_NAME) sample.fillit

$(l_NAME): $(L_OBJS)
	ar rc $(l_NAME) $(L_OBJS)
	ranlib $(l_NAME)

$(p_NAME): $(C_OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(p_NAME) $(C_OBJS)

clean:
	@- $(RM) $(C_OBJS)

fclean: clean
	@- $(RM) $(p_NAME) $(l_NAME) $(L_OBJS)

re: fclean all