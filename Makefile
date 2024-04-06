# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkoechli <gkoechli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 09:51:19 by gduhau            #+#    #+#              #
#    Updated: 2023/02/16 14:41:43 by gkoechli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT	= all

SRCS	= srcs/main.c srcs/ft_split.c srcs/closing.c srcs/heights.c srcs/move_utils.c\
		parsing/cube.c parsing/utils_4.c parsing/gnl_utils.c parsing/gnl.c \
		parsing/mapcheck_error.c parsing/utils_2.c parsing/utils.c \
		parsing/utils_3.c parsing/free_stuff.c srcs/init.c srcs/move.c srcs/square.c srcs/color.c \
		srcs/mlx_utils.c srcs/algo_utils.c srcs/algo_1.c srcs/algo_2.c srcs/algo_3.c srcs/color_spe.c \
		srcs/color_utils.c srcs/square2.c

OBJS	= ${SRCS:.c=.o} 
MLX_FLAGS	= -lXext -lX11 -lm
NAME	= cub3D
CC		= clang
LD_FLAGS	= -L./libs -lmlx_Linux -L libft/ -lft
LD_FLAGS_MAC	= -L./libs -lmlx_Mac 
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra -g
HEADERS = -I includes/ -I libft/

flag:=1
.c.o:
		@setterm -cursor off
		@if [ $(flag) = "1" ]; then\
			clear ;\
			printf "\033[1;35m========================================\n";\
			printf "|           CUB3D LOADING          |\n";\
			printf "========================================\n";\
		fi
		@printf "\033[C\033[32mCompiling $@... \033[K\033[m\r"
		@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
		$(eval flag=$(shell echo $$(($(flag)+1))))
# .c.o:
# 	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


$(NAME):	$(OBJS)
			@echo "\033[K\033[1;32m Cub3d : compiled\033[m"
			@make --no-print-directory -C libft/
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LD_FLAGS} ${MLX_FLAGS} 
			@printf "\033[1;32m========================================\n"
			@printf "|         COMPILATION FINISHED !       |\n"
			@printf "========================================\n\033[m"
			@setterm -cursor on
# ${NAME}:	${OBJS} #solong.h
# 			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LD_FLAGS} ${MLX_FLAGS} 


all: ${NAME}

# val: ${NAME}
# 			valgrind --leak-check=full --tool=memcheck --show-reachable=yes --track-fds=yes --errors-for-leak-kinds=all --show-leak-kinds=all ./${NAME}

mac:	${OBJS} solong.h
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}  ${LD_FLAGS_MAC} -framework OpenGL -framework AppKit

clean:
			@printf "\033[1;31m========================================\n"
			@printf "|           CUB3D CLEANING         |\n"
			@printf "========================================\n\033[m"
			@printf "\033[K\033[1;33m Destroying objects\n\033[m"
			@make --no-print-directory clean -C libft/
			@$(RM) $(OBJS)
# clean:
# 			${RM} ${OBJS}

fclean:	clean
			@printf "\033[K\033[1;31m Destroying all\n\033[m"
			@make --no-print-directory fclean -C libft/
			@${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re val mac