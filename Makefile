# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nplieger <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 16:17:44 by nplieger          #+#    #+#              #
#    Updated: 2022/11/15 17:33:43 by nplieger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	libftprintf.a
EXECUTABLE_NAME	:=	./ft_printf

INCS_DIR		:=	includes
LIBFT_DIR		:=	libft
OBJ_DIR			:=	objs
SRC_DIR			:=	srcs
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS			:=	ft_printf \
					ft_parse_format \
					t_flags/ft_initialize_flags \
					t_flags/ft_next_flags \
					handlers/ft_handler_args \
					handlers/ft_handler_flags \
					handlers/ft_handler_percent \
					put_methods/ft_strrev \
					put_methods/ft_itoa_base \
					put_methods/ft_putcharc \
					put_methods/ft_putpadding \
					put_methods/ft_putstrc \
					flags/ft_isflag \
					flags/ft_convertor_asterisk \
					flags/ft_convertor_blank \
					flags/ft_convertor_dash \
					flags/ft_convertor_digits \
					flags/ft_convertor_hash \
					flags/ft_convertor_plus \
					flags/ft_convertor_zero \
					types/ft_istype \
					types/ft_convertor_d \
					types/ft_convertor_i \
					types/ft_convertor_o

LIBFT_SRCS		:=	ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii \
					ft_isdigit ft_isprint ft_itoa ft_memchr ft_memcmp ft_memcpy \
					ft_memmove ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd \
					ft_putstr_fd ft_split ft_strchr ft_strdup ft_striteri ft_strjoin \
					ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr \
					ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper ft_lstnew \
					ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone \
					ft_lstclear ft_lstiter ft_lstmap

LIBFT_SRCSC		:=	$(addsuffix .c, $(LIBFT_SRCS))
CC_LIBFT_SRCSC	:=	$(addprefix $(LIBFT_DIR)/, $(LIBFT_SRCSC))
SRCSC			:=	$(addsuffix .c, $(SRCS))
CC_SRCSC		:=	$(addprefix $(SRC_DIR)/, $(SRCSC))
OBJS			:=	$(SRCSC:%.c=$(OBJ_DIR)/%.o)

CC				:=	gcc
AR				:=	ar -rcs
CFLAGS			:=	-Wall -Wextra -Werror
RM				:=	/bin/rm -f

all: $(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	$(AR) $(NAME) $(OBJS)

$(OBJS):	$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)
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

test: re
	@$(CC) $(CFLAGS) $(CC_SRCSC) $(CC_LIBFT_SRCSC) -L . -I $(INCS_DIR) -o $(EXECUTABLE_NAME)
	@echo "\n\033[92mExecution of program.\033[0m"
	@echo "\033[92m------------------\033[0m\n"	
	$(EXECUTABLE_NAME)

.PHONY: all clean fclean re bonus test
