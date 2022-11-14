# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nplieger <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 09:39:46 by nplieger          #+#    #+#              #
#    Updated: 2022/11/14 16:08:01 by nplieger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a

INCS_DIR	:=	includes
LIBFT_DIR	:=	libft
LIBFT		:=	$(LIBFT_DIR)/libft.a

SRC_DIR		:=	srcs
SRCS		:=	ft_printf.c \
				ft_initialize_flags.c \
				ft_next_flags.c \
				ft_handler_percent.c \
				ft_handler_args.c \
				ft_handler_flags.c \
				ft_istype.c \
				ft_isflag.c \
				ft_parse_format.c \
				ft_putcharc.c \
				ft_putstrc.c \
				ft_put_padding.c \
				../libft/ft_isdigit.c \
				../libft/ft_strdup.c \
				../libft/ft_itoa.c \
				../libft/ft_strlen.c \
				../libft/ft_strlcpy.c \
				convertor_types/ft_convertor_d.c \
				convertor_types/ft_convertor_i.c

CC_SRCS		:=	$(addprefix $(SRC_DIR)/, $(SRCS))
OBJS		:=	$(SRCS:%.c=$(SRC_DIR)/%.o)

CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -g
RM			:=	/bin/rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -I $(LIBFT_DIR) $(CC_SRCS)
	ar rcs $(NAME) $<

$(OBJS): $(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INCS_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	make bonus -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)
	$(RM) ./a.out

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all
	
.PHONY: all clean fclean re
