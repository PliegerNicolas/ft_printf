# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nplieger <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 16:17:44 by nplieger          #+#    #+#              #
#    Updated: 2022/12/15 13:51:05 by nplieger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	libftprintf.a
EXECUTABLE_NAME	:=	./a.out

INCS_DIR		:=	includes
LIBFT_DIR		:=	libft
OBJ_DIR			:=	objs
SRC_DIR			:=	srcs
LIBFT			:= $(LIBFT_DIR)/libft.a

SRCS			:=	ft_printf \
					ft_parse_format \
					list/ft_initialize_flags \
					list/ft_next_flags \
					ft_memcpy \
					handlers/ft_handler_args \
					handlers/ft_handler_flags \
					handlers/ft_handler_percent \
					utils/ft_strrev \
					utils/ft_power \
					utils/ft_dmod \
					utils/ft_issignedzero \
					utils/ft_precision_charcount \
					utils/ft_select_paddingchar \
					utils/ft_dtoa \
					utils/ft_ptoa \
					utils/ft_llitoa \
					utils/ft_itoa_base \
					utils/ft_sntoa \
					utils/ft_putcharc \
					utils/ft_putstrc \
					utils/ft_isnumeric \
					utils/ft_addprefix \
					flags/ft_isflag \
					flags/ft_asterisk \
					flags/ft_blank \
					flags/ft_dash \
					flags/ft_digits \
					flags/ft_hash \
					flags/ft_plus \
					flags/ft_zero \
					flags/ft_numeric \
					types/ft_istype \
					types/ft_convertor_d \
					types/ft_convertor_i \
					types/ft_convertor_o \
					types/ft_convertor_x \
					types/ft_convertor_u \
					types/ft_convertor_c \
					types/ft_convertor_s \
					types/ft_convertor_f \
					types/ft_convertor_e \
					types/ft_convertor_g \
					types/ft_convertor_p

SRCSC			:=	$(addsuffix .c, $(SRCS))
CC_SRCSC		:=	$(addprefix $(SRC_DIR)/, $(SRCSC))
OBJS			:=	$(SRCSC:%.c=$(OBJ_DIR)/%.o)

CC				:=	gcc
AR				:=	ar -rcs
CFLAGS			=	-Wall -Wextra -Werror
CFLAGS_DEBUG	+= -g
RM				:=	/bin/rm -f

all: $(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	$(AR) $(NAME) $(OBJS)

$(OBJS):	$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

bonus:	all

clean:
	make fclean -C $(LIBFT_DIR)
	find . -type f -name '*.o' -delete
	$(RM) -r $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(EXECUTABLE_NAME)

re: fclean all

test: all
	$(CC) $(CFLAGS_DEBUG) -I $(INCS_DIR) -I $(LIBFT_DIR) main.c $(NAME) -o $(EXECUTABLE_NAME)

.PHONY: all clean fclean re bonus test
