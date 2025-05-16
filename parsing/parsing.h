#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1

typedef struct s_maplist
{
	char				*line;
	struct s_maplist	*next;
}						t_maplist;

typedef struct s_rgb
{
	char				*f;
	char				*c;
}						t_rgb;

typedef struct s_texture
{
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	t_rgb				*rgb;
	int					c_color;
	int					f_color;
}						t_wall_textures;

typedef struct s_data
{
	char				**map;
	int					row;
	int					col;
	int					j;
	int					i;
}						t_data;

typedef struct s_cub
{
	t_data				*data;
	t_wall_textures		*texture;
}						t_cub;

int						proccess_input(t_data *data, t_cub *cub, char *path,
							t_wall_textures *texture);
int						init_texture(t_wall_textures *texture);
int						init_data(t_data *data);
int						init_cub(t_cub *cub, t_data *data,
							t_wall_textures *texture);
int						ft_atoi(char *str);
char					**ft_split(char const *s, char c);
char					*get_next_line(int fd);
size_t					ft_strlen(char *str);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
void					*ft_memcpy(void *to, const void *from, size_t n);
char					*ft_strdup(char *src);
char					*ft_strtrim(char *s1, char *set);
size_t					ft_strlcpy(char *dst, char *src, size_t size);
int						check_space(char c);
char					*ft_strchr(char *s, int c);
int						valid_texture(t_cub *cub, t_wall_textures *texture,
							int fd);
int						is_valid_rgb(char *rgb);
int						check_colors(t_wall_textures *texture);
int						parse_texture_extension(t_wall_textures *texture);
int						read_texture_lines(t_wall_textures *texture, int fd);
int						parse_texture_line(t_wall_textures *texture,
							char *line);
int						texture_path(t_wall_textures *texture, char *line,
							char *trimmed);
int						set_texture_path(t_wall_textures *texture, char *line,
							char *trimmed);
void					free_array(char **arr);
int						check_extension(char *exten, char *s);
t_maplist				*create_map(char *line);
void					add_map_node(t_maplist **head, char *line);
int						skip_textures(char **line, int fd);
int						is_valid_characters(char *line);
int						init_map(t_maplist *m, t_data *data);
int						build_map(t_data *data, t_maplist *m);
int						is_not_closed(t_maplist *prev, t_maplist *current,
							t_maplist *next);
int						validate_map(t_maplist *map);
void					parse_map_line(t_data *data, t_maplist *temp);
t_maplist				*get_map(int fd);
int						get_biggest_line(t_maplist *head);
void					ft_freemap(t_maplist **map);
void					*ft_memset(void *ptr, int x, size_t n);
void					free_all(t_cub *cub);
void					free_data(t_data *data, t_wall_textures *texture);
int						checkline(char **line, int fd, t_maplist **map,
							int *start);
int						check_empty_lines(int fd, t_maplist **map,
							char *previeus);
int						is_invalid_texture(char *str);
void					free_heap(t_cub *cub);
char					*remove_spaces(char *str);
int						find_map(char *map);
int						ft_exit(t_cub *cub);
int						get_colors(char *rgb);
int						check_map(t_data *data, char *path);

// GET NEXT LINE
char					*ft_strjoin(char *str, char *buffer);
char					*ft_substr(char *string, int start, int len);
void					ft_joinstring(char *string, char *str, char *buffer);
bool					is_only_spaces(char *str);

#endif
