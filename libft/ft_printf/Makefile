# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 22:34:41 by selow             #+#    #+#              #
#    Updated: 2025/06/18 08:50:33 by selow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar rcs
RM = rm -f
INCS = ft_printf.h 

SRC = ft_printf.c \
	ft_putnbr.c \
	put_u.c \
	ft_printf_utils.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@
	
bonus: $(BONUSES:.c=.o)
	$(AR) $(NAME) $^

clean:
	rm -f *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean bonus all clean
