################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := libft.a
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      ft_lstadd_back.c \
                          get_next_line.c \
                          get_next_line_utils.c \
                          ft_hexptr.c \
                          ft_printf.c \
                          ft_printhex_lower.c \
                          ft_printhex_upper.c \
                          ft_putchar.c \
                          ft_putnbr.c \
                          ft_putstr.c \
                          ft_bzero.c \
                          ft_putstr_fd.c \
                          ft_memchr.c \
                          ft_itoa.c \
                          ft_isalpha.c \
                          ft_isdigit.c \
                          ft_memcmp.c \
                          ft_tolower.c \
                          ft_toupper.c \
                          ft_strrchr.c \
                          ft_isprint.c \
                          ft_strtrim.c \
                          ft_strjoin.c \
                          ft_strchr.c \
                          ft_isascii.c \
                          ft_strmapi.c \
                          ft_striteri.c \
                          ft_putendl_fd.c \
                          ft_calloc.c \
                          ft_strnstr.c \
                          ft_strlcat.c \
                          ft_isalnum.c \
                          ft_putchar_fd.c \
                          ft_memcpy.c \
                          ft_strncmp.c \
                          ft_putnbr_fd.c \
                          ft_split.c \
                          ft_strdup.c \
                          ft_substr.c \
                          ft_memset.c \
                          ft_strlcpy.c \
                          ft_atoi.c \
                          ft_strlen.c \
                          ft_memmove.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} ${OBJS}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


