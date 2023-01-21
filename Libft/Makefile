# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 15:57:12 by momaiouf          #+#    #+#              #
#    Updated: 2022/12/07 16:48:42 by momaiouf         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c ft_memset.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memcpy.c \
					ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
					ft_toupper.c ft_calloc.c ft_isdigit.c ft_striteri.c ft_memchr.c  \
					ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c

OBJS			= $(SRCS:.c=.o)

SRCS_BONUS		= 	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
					ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
					ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstlast_bonus.c

OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f
AR				= ar rcs
HEADER			= libft.h

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)

%.o: 			%.c $(HEADER) Makefile
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(SRCS_BONUS) $(OBJS_BONUS)
				$(AR) $(NAME) $(SRCS_BONUS) $(OBJS_BONUS)

.PHONY:			all clean fclean re bonus
