# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 18:46:38 by isbraz-d          #+#    #+#              #
#    Updated: 2023/09/17 11:35:51 by isbraz-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =  ft_substr.c ft_isalpha.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isascii.c \
	ft_atoi.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_strlen.c ft_isalpha.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
	ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_tolower.c ft_toupper.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_putchar_fd.c \
	ft_putnbr_fd.c  ft_putstr_fd.c ft_putendl_fd.c ft_striteri.c ft_strmapi.c \
	ft_split.c get_next_line.c get_next_line_utils.c ft_strcmp.c

OBJS = $(SRCS:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_CONV = $(BONUS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(OBJS)
	@ar -crs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS) $(BONUS_CONV)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: $(OBJS) $(BONUS_CONV)
	@ar -crs   $(NAME) $(OBJS) $(BONUS_CONV) 
	

