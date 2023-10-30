# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isbraz-d <isbraz-d@student.com.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 15:27:40 by isbraz-d          #+#    #+#              #
#    Updated: 2023/09/26 11:31:51 by isbraz-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Werror -Wextra -g

SRCS = check_map.c save_map.c main.c check_path.c images.c keyboard.c clean.c

LIBFT		=	../libft/libft.a

CFLAGS		=	-Wall -Wextra -Werror -g #-fsanitize=address
MLX 		=	mlx/libmlx.a

RM			=	rm -f

OBJS		=	$(SRCS:%.c=%.o)

MLXFLAGS	=	-L ../mlx/ -lmlx -Ilmlx -lXext -lX11


# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

all:		$(NAME)

$(NAME):	$(OBJS)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@make -C ../libft
	@make -C ../mlx
	$(CC) $(SRCS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)


clean:
	@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
	$(RM) $(OBJS)

fclean:		clean
	@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
	$(RM) $(NAME)
	make fclean -C ../libft/

re:	fclean all

.PHONY:		all clean fclean re