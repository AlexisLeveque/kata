# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/16 20:20:16 by aleveque          #+#    #+#              #
#    Updated: 2017/06/26 17:35:30 by aleveque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = kata

OBJDIR = obj

SRC = main.c ft_strsplit.c

OBJ = $(SRC:.c=.o)

OBJP = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

SRCPATH = $(SRC)

all: $(OBJDIR) $(NAME)

re: fclean all

$(OBJDIR)/%.o: ./%.c
	@$(CC) -c -o $@ $^ -g

$(OBJDIR):
	@echo "\033[1;32mcompiling obj"
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJP)
	@echo "\033[1;34mcompiling exec"
	@$(CC) -g -o $@ $^

clean:
	@echo "\033[1;31mcleaning obj"
	@rm -rf $(OBJDIR)

fclean:
	@echo "\033[1;31mcleaning exec"
	@rm -rf $(OBJDIR)
	@rm -rf $(NAME)

