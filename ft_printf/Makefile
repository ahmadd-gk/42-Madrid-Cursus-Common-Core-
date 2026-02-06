# **************************************************************************** #
#                                   LIBFT                                      #
# **************************************************************************** #

# Nombre del ejecutable (en este caso, biblioteca)
NAME	= libftprintf.a

# Compilador y flags
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

AR		= ar rcs
RM		= rm -f

# Lista de archivos fuente
SRCS	= ft_printf.c format_cases.c format_cases2.c ft_printf_utils.c

# Archivos objeto (.o)
OBJS	= $(SRCS:.c=.o)

# -------------------- #
#      COMPILATION     #
# -------------------- #

# Regla por defecto
all: $(NAME)

# Cómo crear la librería
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Compila cada .c en su correspondiente .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# -------------------- #
#        CLEAN         #
# -------------------- #

# Borra archivos .o
clean:
	$(RM) $(OBJS)

# Borra todo, incluida la librería o archivo programa
fclean: clean
	$(RM) $(NAME)

# Limpia y recompila
re: fclean all

# .PHONY: indica que la/s regla/s no representa/n un archivo real
.PHONY: all clean fclean re
