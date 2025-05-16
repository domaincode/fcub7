#include "parsing.h"

int	check_player(t_cub *cub)
{
	int		i;
	int		j;
	char	cell;
	int		countp;

	i = -1;
	countp = 0;
	while (++i < cub->data->row)
	{
		j = -1;
		while (++j < cub->data->col)
		{
			cell = cub->data->map[i][j];
			if (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
				countp++;
		}
	}
	if (countp != 1)
		return (1);
	else
		return (0);
}

int	start_parser(t_cub *cub, t_data *data, char *path, int fd)
{
	if (!check_extension(path, "cub"))
	{
		printf("Error in Extension\n");
		return (1);
	}
	if (valid_texture(cub, cub->texture, fd))
		return (1);
	if (check_map(data, path))
	{
		printf("Invalid Map\n");
		return (1);
	}
	if (check_player(cub))
	{
		printf("player position not found\n");
		return (1);
	}
	return (0);
}

int	proccess_input(t_data *data, t_cub *cub, char *path,
	t_wall_textures *texture)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error in The file");
		(free(cub), free(texture));
		exit(1);
	}
	if (init_data(data))
		return (close(fd), 1);
	if (init_texture(texture))
		return (close(fd), 1);
	if (init_cub(cub, data, texture))
		return (close(fd), 1);
	if (start_parser(cub, data, path, fd))
	{
		free_data(cub->data, cub->texture);
		(free(cub), close(fd));
		exit(1);
	}
	close(fd);
	return (0);
}
