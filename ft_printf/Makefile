SRCS = srcs/ft_printf.c srcs/ft_printf_utils.c srcs/ft_core.c srcs/ft_formatters.c srcs/ft_ntoston.c srcs/ft_parsers.c srcs/ft_sutils.c srcs/ft_utils.c

OBJS = ft_printf.o ft_printf_utils.o ft_core.o ft_formatters.o ft_ntoston.o ft_parsers.o ft_sutils.o ft_utils.o

HEADER= -I includes

NAME = libftprintf.a

CC = clang

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)
$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) $(HEADER)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	${RM} ${NAME} $(OBJS)

re: fclean all

.PHONY: all clean fclean re bonus
