# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 16:32:35 by pbernier          #+#    #+#              #
#    Updated: 2017/09/25 21:38:56 by pbernier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT			=	MOD1
NAME			=	mod1
OBJDIR			=	objs/
SRCDIR			=	srcs/
SRC				=	main.c \
					error.c \
					init.c \
					usage.c \
					get_line.c \
					ver_char.c \
					ver_value.c \
					check_file.c \
					check_char.c \
					check_value.c
OBJ				=	$(addprefix $(OBJDIR),$(SRC:.c=.o))
LIB				=	lib/libft/libft.a
CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra -Ofast
DFLAGS			=	-fsanitize=address -g
INCLUDES		=	-I includes/ -I lib/libft/includes/

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	@make -C ./lib/libft
	@printf "[$(PROJECT)] Objs compilation done.                                               \n"
	@$(CC) -o $(NAME) $(OBJ) $(LIB) $(FLAGS)
	@printf "[$(PROJECT)] $(NAME) compiled.                                                    \n"


$(OBJDIR)%.o: $(SRCDIR)%.c
	@printf "[$(PROJECT)] Compiling $< to $@                                                   \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(OBJDIR):
	@mkdir objs

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJDIR)
	@make -C ./lib/libft clean
	@printf "[$(PROJECT)] Obj removed.                                                           \n"

fclean: clean
	@rm -f $(LIB)
	@rm -rf $(NAME)
	@printf "[$(PROJECT)] $(NAME) removed.                                                       \n"

re: fclean all

.PHONY: all clean fclean re
