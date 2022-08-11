# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 18:39:38 by mdkhissi          #+#    #+#              #
#    Updated: 2022/08/11 16:42:13 by mdkhissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------- LIBRARY --------------
NAME		= libft.a
DESCRIPTION	= Libft

# ----------- COMPILER FLAGS -------
CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g3

# ----------- INCLUDE --------------
INCLUDE		= includes
C_INCLUDES	= -I $(CORE)/$(INCLUDE)
P_INCLUDES	= -I $(PRINTF)/$(INCLUDE)
G_INCLUDES	= -I $(GNL)/$(INCLUDE)

# ----------- LIBS ----------------
CORE		= core
PRINTF		= ft_printf
GNL			= gnl

#------------ FILES ---------------
OBJ			= objs
SRC			= srcs
C_SRCS		= ft_atois.c ft_c.c ft_c2.c ft_mem.c ft_mem2.c ft_print.c ft_str.c ft_str2.c ft_str3.c \
				ft_str4.c ft_split.c ft_strtrim.c ft_sarr.c ft_lst.c ft_lst2.c
P_SRCS		= ft_printf.c ft_printf_utils.c ft_core.c ft_formatters.c ft_ntoston.c ft_parsers.c \
				ft_sutils.c main.c
G_SRCS		= get_next_line.c
C_OBJS		= $(patsubst %.c, $(CORE)/$(OBJ)/%.o,$(C_SRCS))
P_OBJS		= $(patsubst %.c, $(PRINTF)/$(OBJ)/%.o,$(P_SRCS))
G_OBJS		= $(patsubst %.c, $(GNL)/$(OBJ)/%.o,$(G_SRCS))

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
$(NAME)	: $(C_OBJS) $(P_OBJS) $(G_OBJS)
	ar rcs ${NAME} $(C_OBJS) $(P_OBJS) $(G_OBJS)
	@echo "$(PURPLE)§> $(RED)Building $(DESCRIPTION) $(GREEN)√$(EOC)"

$(CORE)/$(OBJ)/%.o		: $(CORE)/$(SRC)/%.c | $(CORE)/$(OBJ)
	$(CC) $(CFLAGS) $(C_INCLUDES) -c $< -o $@

$(PRINTF)/$(OBJ)/%.o	: $(PRINTF)/$(SRC)/%.c | $(PRINTF)/$(OBJ)
	$(CC) $(CFLAGS) $(C_INCLUDES) $(P_INCLUDES) -c $< -o $@

$(GNL)/$(OBJ)/%.o		: $(GNL)/$(SRC)/%.c | $(GNL)/$(OBJ)
	$(CC) $(CFLAGS) $(C_INCLUDES) $(G_INCLUDES) -c $< -o $@

$(CORE)/$(OBJ)		:	
	@-mkdir $(CORE)/$(OBJ)
	@echo "$(PURPLE)§> $(RED)Compiling $(CORE) object files$(EOC)"

$(PRINTF)/$(OBJ)		:	
	@-mkdir $(PRINTF)/$(OBJ)
	@echo "$(PURPLE)§> $(RED)Compiling $(PRINTF) object files$(EOC)"

$(GNL)/$(OBJ)		:	
	@-mkdir $(GNL)/$(OBJ)
	@echo "$(PURPLE)§> $(RED)Compiling $(GNL) object files$(EOC)"

bonus	: clean $(C_OBJS) $(P_OBJS) $(G_OBJS)
	@echo "$(PURPLE)§> $(RED)Building $(DESCRIPTION) $(GREEN)√$(EOC)"
	ar rcs ${NAME} $(C_OBJS) $(P_OBJS) $(G_OBJS)

clean	:
	rm -rf $(CORE)/$(OBJ) $(PRINTF)/$(OBJ) $(GNL)/$(OBJ)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re bonus
