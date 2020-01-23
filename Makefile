# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbruno <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 09:23:39 by cbruno            #+#    #+#              #
#    Updated: 2019/04/19 16:42:19 by hde-moff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= wolf3d

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror 
LIBFT	= ./includes/libft

ARCH = $(shell arch)

ifeq ($(ARCH), x86_64)
	MINILIBX	= ./includes/minilibx
	FRAMEWORK	= -lm -lft -lmlx -lX11 -lXext -lpthread
else
	MINILIBX 	= ./includes/minilibx_macos
	FRAMEWORK	= -lmlx -lft -framework OpenGL -framework AppKit -lpthread
endif

objects	=	./src/free.o ./src/key.o ./src/graphic.o ./src/main.o
objects	+=	./src/print.o ./src/map.o ./src/player.o
objects	+=	./src/projection.o ./src/utils.o ./src/intersections.o
objects +=	./src/image.o ./src/paint.o ./src/menu.o ./src/direction.o
objects +=	./src/assets.o ./src/draw.o ./src/texture.o ./src/mouse.o
objects +=	./src/sound.o ./src/extra_math_utils.o ./src/check_map.o
objects +=  ./src/walk.o

.SILENT:

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -DARCH=$(ARCH) -c -o $@ $<
	printf '\033[36m[ ✔ ] %s\n\033[0m' "$<"

$(NAME): lib $(objects)
	$(CC) $(CFLAGS) -o $@ $(objects) -L $(MINILIBX) -L $(LIBFT) $(FRAMEWORK)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "WOLF3D"

lib:
	clear
	make -s -C $(LIBFT)
	make -s -C $(MINILIBX)

clean:
	make -s -C $(LIBFT) clean
	make -s -C $(MINILIBX) clean
	rm -f $(objects)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Libprintf"

fclean:
	make -s -C $(LIBFT) fclean
	make -s -C $(MINILIBX) clean
	rm -f $(objects)
	rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean Libprintf"

re: fclean all
