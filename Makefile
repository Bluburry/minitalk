# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 11:34:31 by tpinto-e          #+#    #+#              #
#    Updated: 2023/03/30 18:27:03 by tpinto-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
COMPILER = cc
CFLAGS = -Wall -Wextra -Werror -I .
RM = rm -rf

# location of the server files
SERVER_FLDR = src/server
# location of the client files
CLIENT_FLDR = src/client

# appending folder to mandatory files
SERVER_SRC = $(addprefix $(SERVER_FLDR)/, server.c)
CLIENT_SRC = $(addprefix $(CLIENT_FLDR)/, client.c)
# appending folder to bonus files
SERVER_BONUS_SRC = $(addprefix $(SERVER_FLDR)/, server_bonus.c)
CLIENT_BONUS_SRC = $(addprefix $(CLIENT_FLDR)/, client_bonus.c)


all : comp
	@$(COMPILER) $(CFLAGS) $(SERVER_SRC) $(NAME) -o server
	@$(COMPILER) $(CFLAGS) $(CLIENT_SRC) $(NAME) -o client
	@echo "server and client ready"

bonus : comp
	@$(COMPILER) $(CFLAGS) $(SERVER_BONUS_SRC) $(NAME) -o server
	@$(COMPILER) $(CFLAGS) $(CLIENT_BONUS_SRC) $(NAME) -o client
	@echo "server and client ready"

clean :
	@echo "sending clean to libft"
	@make clean -C ./libft
	@$(RM) server client
	@echo "Job done."

fclean : clean
	@make fclean -C ./libft
	@rm $(NAME)
	@echo "Job done, but better."

re : fclean all

# extra rules
comp :
	@echo "Entering libft."
	@$(MAKE) -C ./libft
	@cp ./libft/libft.a $(NAME)
	@echo "Creating archive."
	@ar rcs $(NAME)
	@echo "minitalk ready to use."

.SILENT:

.PHONY : all, bonus, clean, fclean, re, comp
