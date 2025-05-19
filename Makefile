NAME = cub3D
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm

SRCS = main.c \
	parsing/free_parsing.c \
	parsing/get_map.c \
	parsing/init_data.c \
	parsing/parse_input.c \
	parsing/rgb_colors.c \
	parsing/validate_map.c \
	parsing/ft_atoi.c \
	parsing/get_next_line.c \
	parsing/libft_func.c \
	parsing/texture_parser.c \
	parsing/ft_split.c \
	parsing/get_next_line_utils.c \
	parsing/map_utils.c \
	parsing/read_texture.c \
	parsing/tools.c \
	execution/exec/cub_init.c \
	execution/exec/hook_config.c \
	execution/exec/intersections.c \
	execution/exec/vertical.c \
	execution/exec/execution.c \
	execution/exec/horizontal.c \
	execution/exec/textures.c \
	execution/utils/check_wall.c \
	execution/utils/free_game.c \
	execution/utils/normalize_angle.c \
	execution/utils/player_position.c \
	execution/utils/copy.c \
	execution/utils/map_confg.c \
	execution/utils/pixel_put.c \
	execution/basic/line.c \
	execution/basic/square.c \
	execution/basic/map.c



OBJS = $(SRCS:.c=.o)
MLX_LIBRARY = minilibx-linux/mlx.a


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIBRARY)
	$(CC)   $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

$(MLX_LIBRARY):
	make -C minilibx-linux



%.o: %.c
	$(CC) $(CFLAGS) -c $? -o $@

clean:
	make clean -C minilibx-linux
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re