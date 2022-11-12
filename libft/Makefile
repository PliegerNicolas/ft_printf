# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nplieger <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 12:55:46 by nplieger          #+#    #+#              #
#    Updated: 2022/11/11 13:41:22 by nplieger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME			:=	libft.a

SRCS			:=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
					ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
					ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
					ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
					ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
					ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

SRCS_BONUS		:=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
					ft_lstdelone.c	ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS			:=	${SRCS:.c=.o}
OBJS_BONUS		:=	${SRCS_BONUS:.c=.o}

INCLUDES		:=	./
CC				:=	gcc
AR				:=	ar rcs
RM				:=	rm -f
CFLAGS			:=	-Wall -Wextra -Werror -I${INCLUDES}

all:			${NAME}

$(NAME):		${OBJS}
			${AR} $@ $^

bonus:			${NAME} ${OBJS_BONUS}
			${AR} ${NAME} ${OBJS_BONUS}

clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:			clean
			${RM} ${NAME}

re:				fclean all

re_bonus:		fclean bonus

.PHONY:			all clean fclean re bonus
