#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/06 13:29:57 by cducaffy          #+#    #+#              #
#    Updated: 2015/05/06 13:30:12 by cducaffy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=	wolf3d
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
LIBFTDIR		=	./libft/
LIBFTH			=	-I$(LIBFTDIR)
LIBXFLAGS		=	-Lminilibx_macos/ -lmlx -framework OpenGL -framework AppKit
LIBFTFLAGS		=	-L$(LIBFTDIR) -lft
INCS_DIR		=	includes
OBJS_DIR		=	objects
SRCS_DIR		=	sources
SRCS			=	main.c\
					tools.c\
					expose.c\
					read_map.c\
					set.c\
					wolf.c\
					draw_line.c\
					img.c\
					keypress.c\

OBJS 			=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

all				:	$(NAME)

$(NAME)			:	$(OBJS_DIR) $(OBJS)
	Make -C minilibx_macos/
	$(CC) -o $(NAME) $(OBJS) $(LIBFTFLAGS) $(LIBXFLAGS)

$(OBJS_DIR)/%.o	:	$(addprefix $(SRCS_DIR)/, %.c)
	$(CC) $(CFLAGS) -o $@ -c $^ -I $(INCS_DIR) $(LIBFTH) $(MLX)

$(OBJS_DIR)	:	makelibft
	@mkdir -p $(OBJS_DIR)

makelibft:
	make -C $(LIBFTDIR)

fclean			:	clean
	rm -f $(NAME)

clean			:
	rm -rf $(OBJS_DIR)
	make fclean -C $(LIBFTDIR)
	make clean -C minilibx_macos/

re				:	fclean all

.PHONY: clean all re fclean