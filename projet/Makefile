# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tolrandr <tolrandr@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 13:14:37 by tolrandr          #+#    #+#              #
#    Updated: 2024/08/14 13:07:30 by tolrandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

#LIBFT_DIR = libft
#LIBFT = libft/libft.a
MINILIBX_DIR = minilibx
LDLIBS = -lX11 -lXext -lm

SRC_BONUS = ft_itoa.c src/error/ft_error_bonus.c src/error/ft_check_map_bonus.c src/error/ft_init_bonus.c src/error/ft_check_extension_bonus.c\
		src/error/ft_alloc_bonus.c src/error/ft_map_validate_bonus.c src/ft_map_bonus.c src/ft_event_bonus.c src/ft_window_bonus.c\
		src/ft_enemy_bonus.c src/ft_initialize_bonus.c src/ft_img_bonus.c src/so_long_bonus.c

GNL = gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)
OBJ_GNL = $(GNL:.c=.o)

FLAGS = -Wall

RM = rm -f

.c.o :
	cc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ_BONUS) $(OBJ_GNL)
		make -C $(MINILIBX_DIR)
		cc $(FLAGS) -o $(NAME) $(OBJ_BONUS) $(OBJ_GNL) -L -C $(MINILIBX_DIR)/libmlx.a $(LDLIBS)

all : $(NAME)


clean :
	$(RM) $(OBJ_GNL) $(OBJ_BONUS) $(OBJ_GNL_BONUS)

fclean : clean
	make clean -C $(MINILIBX_DIR)
	$(RM) $(NAME)

re : fclean all
