# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/08 11:56:28 by selow             #+#    #+#              #
#    Updated: 2025/12/15 23:37:25 by selow            ###   ########.fr        #
#    Updated: 2025/09/16 19:28:09 by selow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
NAME_FLAGS = -Wall -Wextra -Werror mlx_linux/libmlx_Linux.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o -Ilibft
OBJ_FLAGS = -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -Includes -Ilibft
CC = cc
RM = rm -f

LIB_PATH = ./libft
LIBFT = $(LIB_PATH)/libft.a

SRC =	src/fdf.c \
	src/parse_arg.c \
	src/draw_map.c \
	src/fdf_utils.c \
	src/free_everything.c \
	src/put_pixel.c \
	src/split_atoi.c \
	src/split_atoi_colour.c \

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) libft/libft.a $(NAME_FLAGS) -o $(NAME)

test: $(LIBFT) main.o
	$(CC) main.o libft/libft.a $(NAME_FLAGS) -o test

$(LIBFT):
	$(MAKE) -C $(LIB_PATH)

%.o: %.c $(INCS)
	$(CC) $(OBJ_FLAGS) -c $< -o $@

bonus: $(BONUSES:.c=.o)
	$(AR) $(NAME) $^

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIB_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_PATH) fclean

re: fclean all

.PHONY: re fclean bonus all clean
