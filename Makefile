CLR_RMV := \033[0m
RED := \033[1;31m
GREEN := \033[1;32m
YELLOW := \033[1;33m
BLUE := \033[1;34m
CYAN := \033[1;36m

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
RM = rm -rf

SRC = libft/ft_atoi.c \
      libft/ft_bzero.c \
      libft/ft_calloc.c \
      libft/ft_isalnum.c \
      libft/ft_isalpha.c \
      libft/ft_isascii.c \
      libft/ft_isdigit.c \
      libft/ft_isprint.c \
      libft/ft_itoa.c \
      libft/ft_memchr.c \
      libft/ft_memcmp.c \
      libft/ft_memcpy.c \
      libft/ft_memmove.c \
      libft/ft_memset.c \
      libft/ft_putchar_fd.c \
      libft/ft_putendl_fd.c \
      libft/ft_putnbr_fd.c \
      libft/ft_putstr_fd.c \
      libft/ft_split.c \
      libft/ft_strchr.c \
      libft/ft_strdup.c \
      libft/ft_striteri.c \
      libft/ft_strjoin.c \
      libft/ft_strlcat.c \
      libft/ft_strlcpy.c \
      libft/ft_strlen.c \
      libft/ft_strmapi.c \
      libft/ft_strncmp.c \
      libft/ft_strnstr.c \
      libft/ft_strrchr.c \
      libft/ft_strtrim.c \
      libft/ft_substr.c \
      libft/ft_tolower.c \
      libft/ft_toupper.c \
      libft/get_next_line.c \
      libft/get_next_line_utils.c \
      libft/ft_hexptr.c \
      libft/ft_printf.c \
      libft/ft_printhex_lower.c \
      libft/ft_printhex_upper.c \
      libft/ft_putchar.c \
      libft/ft_putstr.c \
      libft/ft_putnbr.c \
      src/main.c \
      src/map_checker.c \
      src/player_checker.c \
      src/more_checkers.c \
      src/errors.c \
      src/more_errors.c \
      src/floodthemap.c \
      src/freeing.c \
      src/initialise_map.c \
      src/movement.c \
      src/displaying.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) -lmlx -lXext -lX11 -lm -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
