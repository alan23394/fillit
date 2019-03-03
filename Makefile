# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarnett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/07 12:55:52 by abarnett          #+#    #+#              #
#    Updated: 2018/11/14 17:36:58 by abarnett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=			fillit
LIB :=			libft.a

C_OBJS :=		$(patsubst %.c,%.o,$(wildcard ./srcs/*.c))
L_OBJS :=		$(patsubst %.c,%.o,$(wildcard ./libft/srcs/*.c))
INCLUDE_DIR :=	./includes

CFLAGS +=		-Wall -Wextra -Werror -I$(INCLUDE_DIR)
LDFLAGS +=		-L./ -lft

.PHONY:			all clean fclean re

all: $(NAME)

$(LIB): $(L_OBJS)
	ar rc $(LIB) $(L_OBJS)
	ranlib $(LIB)

$(NAME): $(LIB) $(C_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LDFLAGS)

clean:
	@- $(RM) $(C_OBJS) $(L_OBJS)

fclean: clean
	@- $(RM) $(NAME) $(LIB)

re: fclean all
