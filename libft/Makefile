# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivromero <ivromero@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 13:25:53 by ivromero          #+#    #+#              #
#    Updated: 2024/01/17 17:52:49 by ivromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = \
ft_atoi.c		ft_isdigit.c	ft_memmove.c	ft_split.c		ft_strlcpy.c	ft_strrchr.c \
ft_bzero.c		ft_isprint.c	ft_memset.c		ft_strchr.c		ft_strlen.c		ft_substr.c \
ft_calloc.c		ft_itoa.c		ft_putchar_fd.c	ft_strdup.c		ft_strmapi.c	ft_tolower.c \
ft_isalnum.c	ft_memcmp.c		ft_putendl_fd.c	ft_striteri.c	ft_strncmp.c	ft_toupper.c \
ft_isalpha.c	ft_memcpy.c		ft_putnbr_fd.c	ft_strjoin.c	ft_strnstr.c \
ft_isascii.c	ft_memchr.c		ft_putstr_fd.c	ft_strlcat.c	ft_strtrim.c \
ft_lstnew.c		ft_lstadd_front.c ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c\
ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c	  ft_lstmap.c \
get_next_line.c	ft_printf.c		ft_printf_utils.c 

OBJS = $(SRCS:.c=.o)

CC		= cc
RM		= rm -f
AR		= ar rcs

CFLAGS = -Wall -Wextra -Werror

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)
		@echo "Compilación terminada: $@"
		make info

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY : all clean fclean re info

info:
		@echo "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"
		@echo "⬜                                                                ⬜"
		@echo "⬜      LIBFT sin {llaves} AKA tiny_libft                         ⬜"
		@echo "⬜                                                                ⬜"
		@echo "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"
		@echo  
		@echo "Solo con las {} de las funciones 😳."
		@echo "Tratando de minimizar las funciones."
		@echo "Admito que en momentos me he visto en la tesitura de elegir entre optimizar código y optimizar tiempo de computo pero he mantenido un equilibrio. Se podía comprimir mas..."
		@echo "En el tester que he hecho un benchmark contra la función original para comprobar si era tan rápida. (Con strlen me ha ganado la máquina. El resto - o + empate.)"
		@echo "Con instrucciones como:"
		@echo "-------------------------------------------------------------------"
		@echo "while (nbr)\n	nbr /= 10 + (int)(0 * ++len);"
		@echo "-------------------------------------------------------------------"
		@echo "int	ft_tolower(int c)\n{\n	return (c + 32 * (c >= 'A' && c <= 'Z'));\n}"
		@echo "-------------------------------------------------------------------"
		@echo "if (n == -2147483648)\n		return (ft_putstr_fd("-2147483648", fd));"
		@echo "-------------------------------------------------------------------"
		@echo "if (!node)\n	return (ft_lstclear(new_list, del), del(content), NULL);"
		@echo "-------------------------------------------------------------------"
		@echo ""
		@echo ""
		 
		@echo "          ⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬜⬜⬜⬜⬜"
		@echo "          ⬜⬜⬜⬛⬛🟧🟧🟧🟧🟧⬛⬛⬜⬜⬜"
		@echo "          ⬜⬜⬛🟧🟧🟧🟧🟧🟧🟧🟧🟧⬛⬜⬜"
		@echo "          ⬜⬛🟧🟧🟧🟧⬛⬛⬛🟧🟧🟧🟧⬛⬜"
		@echo "          ⬜⬛🟧🟧⬛⬛🟫🟫🟫⬛⬛🟧🟧⬛⬜"
		@echo "          ⬛🟧🟧⬛🟫⬜⬜🏼⬜⬜🟫⬛🟧🟧⬛"
		@echo "          ⬛🟧⬛🟫⬜⬜⬜⬜⬜⬜⬜🟫⬛🟧⬛"
		@echo "          ⬛🟧⬛🟫⬜⬜⬛⬜⬛⬜⬜🟫⬛🟧⬛"
		@echo "          ⬛🟧⬛🟫⬜⬜⬜⬜⬜⬜⬜🟫⬛🟧⬛"
		@echo "          ⬛🟧⬛🟫🟫⬜⬜🏼⬜⬜🟫🟫⬛🟧⬛"
		@echo "          ⬜⬛🟧⬛🟫🟫🏼🏼🏼🟫🟫⬛🟧⬛⬜"
		@echo "          ⬜⬛🟧🟧⬛⬛⬛⬛⬛⬛⬛🟧🟧⬛⬜"
		@echo "          ⬜⬜⬛🟧🟧🟧🟧⬛🟧🟧🟧🟧⬛⬜⬜"
		@echo "          ⬜⬜⬛⬛⬛🟧⬛🟧⬛🟧⬛⬛⬛⬜⬜"
		@echo "          ⬜⬛🟧🟧🟧⬛⬛⬛⬛⬛🟧🟧🟧⬛⬜"
		@echo "          ⬛🟧🟧⬛🟧🟧🟧⬛🟧🟧🟧⬛🟧🟧⬛"
		@echo "          ⬛⬛⬛⬛🟧🟧🟧⬛🟧🟧🟧⬛⬛⬛⬛"
		@echo "          ⬛🟫🟫⬛🟧🟧🟧⬛🟧🟧🟧⬛🟫🟫⬛"
		@echo "          ⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜"
		@echo "          ⬜⬜⬜⬛🟧🟧🟧⬛🟧🟧🟧⬛⬜⬜⬜"
		@echo "          ⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜"
