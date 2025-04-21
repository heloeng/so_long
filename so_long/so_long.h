#ifndef SO_LONG_H
# define SO_LONG_H

# define UP 1001
# define LEFT 2002
# define DOWN 3003
# define RIGHT 4004
# define NORTH 1100
# define SOUTH 2202
# define EAST 3303
# define WEST 4404

# include "libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_data
{
	void	*mlx;
	void	*window;

	char	**map;
	char	**map_copy;
	int		x;
	int		nb_line;
	int		nb_char;
	int		w;
	int		h;

	void	*img_s;
	void	*img_0;
	void	*img_1;
	void	*img_z;
	void	*img_e;
	void	*img_c;
	void	*img_p;
	void	*img_u_p;
	void	*img_l_p;
	void	*img_d_p;
	void	*img_r_p;
	void	*img_dig;

	int		e_line;
	int		e_char;
	int		p_line;
	int		p_char;

	int		e_count;
	int		c_count;
	int		p_count;
	int		c_count_t;

	int		direction;
	int		loop;

}			t_data;

char		**load_map_from_file(t_data *data, char *filename);
char		**copy_map_data(t_data *data);
int			check_map_errors(t_data data);
int			is_valid_extension(char *filename);
int			validate_map_characters(t_data data);
int			check_valid_path(t_data *data);
int			load_game_images(t_data *data);
int			render_map_images(t_data *data);
int			locate_player_and_exit(t_data *data);
void		count_collectibles(t_data *data);
void		display_score(t_data *data);
int			process_key_input(int key, t_data *data);
int			end_game(t_data *data);
void		move_up(t_data *data);
void		move_left(t_data *data);
void		move_down(t_data *data);
void		move_right(t_data *data);
int			exit_game(t_data *data);
void		cleanup_game_resources(t_data *data);
void		free_map_data(t_data *data);
void		free_game_images(t_data *data);
void		free_map_datacpy(t_data *data);
void		free_map_dataall(t_data *data);

#endif
