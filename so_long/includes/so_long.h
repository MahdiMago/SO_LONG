#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"
# include "X11/keysym.h"
# include "X11/X.h"

typedef	struct
{
	int	x;
	int	y;
	int	c_count;
	int	move_count;
}	Position;

typedef struct
{
	int	x_max;
	int	y_max;
	int	count_collectibles;
	int	check_exit;
}	MapInfo;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	char	**lines;
	char	*map;
	int		test;
}				t_vars;

typedef	struct
{
	void	*exit;
	void	*floor;
	void	*character;
	void	*collectible;
	void	*wall;
	int		img_width;
	int		img_height;
}	Picture;

typedef struct
{
	int	x;
	int	y;
	int	win_x;
	int	win_y;
}	for_put_image;

typedef struct s_data
{
	for_put_image	put_image;
	Picture			pics;
	t_vars			vars;
	MapInfo			mapinfo;
	Position		pos;
}	t_data;

int			head_of_check(int argc, char **argv, t_data *data);
int			main_check_map(char **lines, char *map, t_data *data);
int			handle_keypress(int keycode, void *param);
int			close_window(void *param);
void		init_for_put_image(for_put_image *data);
int			put_image(t_data *data);
int			is_ber_file(char *filename);
char		*read_map(const char *filename);
char		*verif_map(int argc, char **argv);
int			check_file(int argc, char **argv);
Picture		define_img(t_data *data);
int			handle_keypress(int keycode, void *param);
int			close_window(void *param);
char		**copy_lines_of_map(char *map);
int			head_of_making(t_data *data);
int			close_cross(t_data *data);
void		player_pos(char **lines, Position *pos);
int			hook_handler(int keycode, t_data *data);
int			avatar_move(t_data *data, t_vars *vars, Position *pos, int direction);
void		avatar_move_2(t_data *data, int direction);
void		avatar_move_3(t_data *data, int direction);
int			is_there_collectible(char *map);
int			avatar_move(t_data *data, t_vars *vars, Position *pos, int direction);
void		avatar_move_vertical(t_data *data, int direction);
void		avatar_move_horizontal(t_data *data, int direction);
int			exit_game(t_data *data);
void		init_data(t_data *data);

#endif
