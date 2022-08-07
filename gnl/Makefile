# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 18:39:38 by mdkhissi          #+#    #+#              #
#    Updated: 2022/08/07 14:52:44 by mdkhissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------- LIBRARY --------------
NAME		= libgnl.a
DESCRIPTION = Get_next_line

# ----------- COMPILER FLAGS -------
CC			= clang
CFLAGS		= -Wall -Wextra -Werror

# ----------- INCLUDE --------------
INCLUDE		=	includes
INCLUDES	=	-I $(INCLUDE)

# ----------- FILES ----------------
OBJ			= ./objs
SRC			= ./srcs
SRCS		= get_next_line.c get_next_line_utils.c
OBJS		= $(patsubst %.c, $(OBJ)/%.o,$(SRCS))

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
$(NAME): ${OBJS}
	@echo -e "$(PURPLE)§> $(RED)Building $(DESCRIPTION) $(GREEN)√$(EOC)"
	@ar rcs ${NAME} ${OBJS}

$(OBJ)/%.o	: $(SRC)/%.c | $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ)		:
	@mkdir $@
	@echo -e "$(PURPLE)§> $(RED)Compiling object files $(GREEN)√$(EOC)"

clean	:
	rm -rf ${OBJ}

fclean	:	clean
	rm -f ${NAME}

re		:	fclean all

.PHONY	: all clean fclean re
