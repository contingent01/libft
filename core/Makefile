# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 18:39:38 by mdkhissi          #+#    #+#              #
#    Updated: 2022/08/07 14:43:01 by mdkhissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------- LIBRARY --------------
NAME		= libft.a
DESCRIPTION	= Libft

# ----------- COMPILER FLAGS -------
CC			= clang
CFLAGS		= -Wall -Wextra -Werror

# ----------- INCLUDE --------------
INCLUDE		=	includes
INCLUDES	=	-I $(INCLUDE)

# ----------- FILES ----------------
OBJ			= ./objs
SRC			= ./srcs
SRCS		= ft_atoi.c ft_strjoin.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			ft_split.c ft_split2.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
			ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
SRCB		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS		= $(patsubst %.c, $(OBJ)/%.o,$(SRCS))
OBJB		= $(patsubst %.c, $(OBJ)/%.o,$(SRCB))

# ----------- COLORS ---------------
BLACK		= \033[1;30m
RED			= \033[1;31m
GREEN		= \033[1;32m
PURPLE		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m
EOC			= \033[0;0m

# ----------- RULES ----------------
all		: ${NAME}
$(NAME)	: ${OBJS}
	@echo -e "$(PURPLE)§> $(RED)Building $(DESCRIPTION) $(GREEN)√$(EOC)"
	@ar rcs ${NAME} ${OBJS}

$(OBJ)/%.o	: $(SRC)/%.c | $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ)		:	
	@mkdir $@
	@echo -e "$(PURPLE)§> $(RED)Compiling object files $(GREEN)√$(EOC)"
	
bonus	: ${OBJB} ${OBJS}
	ar rcs ${NAME} ${OBJS} ${OBJB}

clean	:
	rm -rf ${OBJ}

fclean	:	clean
	rm -f ${NAME}

re		:	fclean all

.PHONY	: all clean fclean re bonus
