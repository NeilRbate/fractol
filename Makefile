# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 13:29:23 by jbarbate          #+#    #+#              #
#    Updated: 2023/01/12 14:12:11 by jbarbate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc
SRCS = src/main.c src/tools.c src/mandelbrot.c
LIBFT = libft/libft.a
MLX = mlx/libmlx.a
OBJS = ${SRCS:.c=.o}
NAME = fractol
CFLAGS = -Wall -Wextra -Werror

.c.o:
	@${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@echo "<| Compiling libft   |>"
	@make -C libft all
	@echo "-----------------------"
	@echo "<| Compiling project |>"
	@${GCC} -g ${CFLAGS} -lm -lmlx -framework OpenGl -framework AppKit -o ${NAME} ${LIBFT} ${MLX} ${OBJS}
	@echo "-----------------------"
	@echo "<| Compiling success |>"

all: ${OBJS} ${NAME}

clean: libclean
	@rm -f ${OBJS}
	@echo Everything is clean

libclean:
	@make -C libft fclean

fclean: clean
	@rm -f ${NAME}

re: fclean all