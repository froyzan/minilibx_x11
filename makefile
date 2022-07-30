NAME	= cub3D
CC		= gcc
Make	= make
CFLAGS	= -O3 -Wall -Wextra -Werror

LIBS	= -L libft/ -lft ${MLX_LNK} -lm
INC		= -I includes/ -I libft/ -I $(MLX_DIR) -I get_next_line/
OBJS	= ${SRCS:.c=.o}

SRCS	=	srcs/cub3d.c \
			srcs/events/keyboard.c \
			srcs/events/move_player.c \
			srcs/events/rotate.c \
			srcs/parser/color.c \
			srcs/parser/leaks_check.c \
			srcs/parser/map_parser.c \
			srcs/parser/parser.c \
			srcs/parser/prepare_map.c \
			srcs/parser/player.c \
			srcs/parser/resolution.c\
			srcs/parser/sprite.c \
			srcs/parser/texture.c \
			srcs/raycaster/raycaster.c \
			srcs/raycaster/raycaster_utils.c \
			srcs/raycaster/sprites.c \
			srcs/raycaster/walls.c \
			srcs/utils/geometry.c \
			srcs/utils/screenshot.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \

OS		= $(shell uname)
ifeq ($(OS), Linux)
	MLX_DIR	= minilibx-linux
	MLX_LNK	= -L ${MLX_DIR} -lmlx -lXext -lX11 -lbsd
	SRCS	+=	srcs/parser/exit_parser.c \
				srcs/utils/mlx_custom.c
else
	MLX_DIR	= minilibx-opengl
	MLX_LNK	= -L ${MLX_DIR} -lmlx -framework OpenGL -framework AppKit
	SRCS	+=	srcs/parser/mac_exit_parser.c \
				srcs/utils/mac_mlx_custom.c
endif

all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INC} 

${NAME}: ${OBJS} ft mlx
		@echo "\033[32m-= Making Cub3D... =-"
		${CC} ${CFLAGS} ${INC} ${OBJS} ${LIBS} -o ${NAME}
		@echo "\033[32m            _      ___________  "
		@echo "\033[32m           | |    |____ |  _  \ "
		@echo "\033[32m  ___ _   _| |__      / / | | | "
		@echo "\033[32m / __| | | | '_ \     \ \ | | | "
		@echo "\033[32m| (__| |_| | |_) |.___/ / |/ /  "
		@echo "\033[32m \___|\__,_|_.__/ \____/|___/   "
		@echo "\033[32mUsage: ./cub3D <map.cub> [--save]"

mlx:
	@echo "\033[34m-= Making mlx... =-"
	@make -C $(MLX_DIR)
	@echo "\033[34m-= mlx Done ! =-"

ft:
	@echo "\033[33m-= Making Libft... =-"
	@make -C libft
	@echo "\033[33m-= Libft Done ! =-"

clean:
	rm -f ${OBJS}
	make -C libft clean

fclean: clean
	@echo "\033[33m-= Cleaning Libft... =-"
	@make fclean -C libft
	@echo "\033[34m-= Cleaning mlx... =-"
	@make clean -C $(MLX_DIR)
	@echo "\033[35m-= Cleaning Cub3D... =-"
	rm -f ${NAME}
	@echo "Done.\033[0;0m"

re: fclean all

.PHONY: all clean fclean re mlx ft
