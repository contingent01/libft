# ----------- LIBRARY --------------
NAME		= libftprintf.a
DESCRIPTION = Ft_Printf

# ----------- COMPILER FLAGS -------
CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g3
LPFLAGS		= -L$(LIBFT) -lft

# ----------- INCLUDE --------------
INCLUDE		=	includes
INCLUDES	=	-I $(INCLUDE) -I $(LIBFT)/includes

# ----------- FILES ----------------
OBJ			= ./objs
SRC			= ./srcs
LIBFT		= ../core
LFTOBJS	= 	$(wildcard $(LIBFT)/objs/*.o)
SRCS		= ft_printf.c ft_printf_utils.c ft_core.c ft_formatters.c ft_ntoston.c ft_parsers.c ft_sutils.c
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
$(NAME)	: ${OBJS}
	@echo -e "$(PURPLE)§> $(RED)Building $(DESCRIPTION) $(GREEN)√$(EOC)"
	@ar rcs ${NAME} $(LFTOBJS) ${OBJS} 

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
