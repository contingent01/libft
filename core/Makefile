# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 18:39:38 by mdkhissi          #+#    #+#              #
#    Updated: 2022/08/07 17:45:31 by mdkhissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------- LIBRARY --------------
NAME		= libft.a
DESCRIPTION	= Libft

# ----------- COMPILER FLAGS -------
CC			= clang
CFLAGS		= -Wall -Wextra -Werror

# ----------- INCLUDE --------------
INCLUDE		=	.
INCLUDES	=	-I $(INCLUDE)

# ----------- FILES ----------------
OBJ			= ./objs
SRC			= ./srcs
SRCS		= ft_atois.c ft_c.c ft_c2.c ft_mem.c ft_mem2.c ft_print.c ft_str.c ft_str2.c ft_str3.c ft_str4.c ft_split.c ft_strtrim.c ft_sarr.c
SRCB		= ft_lst.c ft_lst2.c
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
