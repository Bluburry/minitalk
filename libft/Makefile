# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 18:06:52 by tpinto-e          #+#    #+#              #
#    Updated: 2023/03/30 15:18:28 by tpinto-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

PRINTF_SRC = ft_printf.c ft_utils.c ft_printhexa.c ft_printptr.c
LIBFT_SRC = ft_atoi.c  ft_bzero.c  ft_calloc.c  ft_isalnum.c  ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
	ft_strlcat.c ft_strchr.c ft_strlcpy.c ft_strncmp.c ft_strdup.c \
	ft_striteri.c ft_strjoin.c ft_strlen.c ft_strmapi.c ft_strnstr.c \
	ft_strrchr.c ft_substr.c ft_strtrim.c ft_tolower.c ft_toupper.c
LIBFT_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	ft_lstmap.c 
EXTRA = ft_check_alnum.c

LIBFT_OUT = $(LIBFT_SRC:.c=.o)
LIBFT_BONUSOUT = $(LIBFT_BONUS:.c=.o)
PRINTF_OUT = $(PRINTF_SRC:.c=.o)
EXTRA_OUT = $(EXTRA:.c=.o)
	
%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

all: $(NAME)
$(NAME) : $(LIBFT_OUT) $(LIBFT_BONUSOUT) $(PRINTF_OUT) $(EXTRA_OUT)
	@ar rcs $(NAME) $(LIBFT_OUT) $(LIBFT_BONUSOUT) $(PRINTF_OUT) $(EXTRA_OUT)

clean : 
	@$(RM) $(LIBFT_OUT) $(LIBFT_BONUSOUT) $(PRINTF_OUT) $(EXTRA_OUT)

fclean : clean
	@$(RM) $(NAME)

re: fclean all

.SILENT:

.PHONY: all, clean, fclean, re, bonus
