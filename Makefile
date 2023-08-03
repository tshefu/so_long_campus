
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := so_long
CC        := cc
CFLAGS    := -Wall -Wextra -Werror -g
MFLAGS := -l mlx -lXext -lX11

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      libft/ft_atoi.c \
                        libft/ft_bzero.c \
                        libft/ft_calloc.c \
                        libft/ft_isalnum.c \
                        libft/ft_isalpha.c \
                        libft/ft_isascii.c \
                        libft/ft_isdigit.c \
                        libft/ft_isprint.c \
                        libft/ft_itoa.c \
                        libft/ft_lstadd_back.c \
                        libft/ft_lstadd_front.c \
                        libft/ft_lstclear.c \
                        libft/ft_lstdelone.c \
                        libft/ft_lstiter.c \
                        libft/ft_lstlast.c \
                        libft/ft_lstnew.c \
                        libft/ft_lstsize.c \
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
                        src/movement.c \
                        src/main.c \
                        src/displaying.c \
                        src/initialising.c \
                        src/freeing.c \
                        src/errors.c \
                        src/mapcheck.c \
                        src/floodthemap.c \
                          
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(MFLAGS) -o $(NAME) $(OBJ)

%.o: %.cc
		$(CC) $(CFLAGS) -o $@ -c $<

clean:
	 rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re 



