/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:13:23 by cbruno            #+#    #+#             */
/*   Updated: 2019/04/23 09:31:04 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "./libft/libft.h"
# include "./minilibx_macos/include/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <float.h>
# include <pthread.h>

# define KEY_ESC			53
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_W				13
# define KEY_S				1
# define KEY_A				0
# define KEY_D				2
# define KEY_M				46
# define KEY_N				45

# define KEYPRESS			2
# define KEYRELEASE			3
# define MOUSEPRESS			4
# define MOUSERELEASE		5
# define MOUSEMOVE			6

# define ROUGE				0xFF0000
# define LIME				0x00FF00
# define MAGENTA			0xFF00FF
# define CYAN				0x00FFFF
# define YELLOW				0xFFFF00
# define GREY				0x687876
# define GREEN				0x0E712C
# define CEILING_COL		0x383838
# define FLOOR_COL			0x717171

# define N_TEXTURE			0
# define S_TEXTURE			1
# define W_TEXTURE			2
# define E_TEXTURE			3
# define SPRITE				4

# define WIDTH				1280
# define LENGTH				800
# define NUM_THREADS		4

# define WALK_DIST			22
# define BLOCK_SIZE			64

typedef	enum				e_option
{
	menu,
	play,
}							t_option;

typedef enum				e_bool
{
	false,
	true
}							t_bool;

typedef struct				s_sound
{
	t_bool			status;
	int				numb;
	char			*song;
}							t_sound;

typedef struct				s_mouse
{
	t_bool			status;
	int				button;
	int				current[2];
	int				last[2];
}							t_mouse;

typedef	struct				s_texture
{
	int				*data;
	unsigned int	width;
	unsigned int	height;
}							t_texture;

typedef struct				s_list_texture
{
	t_texture					texture;
	struct s_list_texture		*next;
}							t_list_texture;

typedef struct				s_image
{
	void			*img_ptr;
	int				*img;
	int				bpp;
	int				size_x;
	int				endian;
}							t_image;

typedef struct				s_player
{
	int					position[2];
	float				direction[2];
	double				fov;
	int					distance_plan;
}							t_player;

typedef struct				s_proj
{
	int				distance_proj;
	int				x_center;
	int				y_center;
	float			step_angle;
}							t_proj;

typedef struct				s_map
{
	char			**grid;
	int				**p_grid;
	int				width;
	int				length;
}							t_map;

typedef struct				s_graphic
{
	char			*title;
	void			*mlx_ptr;
	void			*win_ptr;
	int				x_min;
	int				x_max;
	int				y_min;
	int				y_max;
	int				x_center;
	int				y_center;
}							t_graphic;

typedef struct				s_game
{
	char					*file;
	t_option				option;
	t_graphic				graphic;
	t_image					image;
	t_map					map;
	t_player				player;
	t_proj					projection;
	pthread_t				threads[NUM_THREADS];
	t_list_texture			*texture_list;
	t_mouse					mouse;
	t_sound					sound;
}							t_game;

typedef struct				s_col_info
{
	t_texture				*texture;
	int						height;
	int						x;
	int						col;
}							t_col_info;

typedef struct				s_bg_fill_info
{
	t_game			*game;
	unsigned int	start;
	unsigned int	stop;
	unsigned int	color;
}							t_bg_fill_info;

typedef struct				s_intersect_info
{
	int	horiz[2];
	int vert[2];
}							t_intersect_info;

t_bool						init_game(t_game *game, char *file);

void						print_usage(void);

void						print_error(t_game *game);

t_bool						init_graphic(t_game *game);

void						mainloop(t_game *game);

void						free_all(t_game *game);

int							red_cross(t_game *game);

void						rotate_camera(t_game *game, float angle);

void						move_camera(t_game *game, int step);

int							key_release(int key, void *param);

int							key_press(int key, void *param);

int							deal_key(int key, void *param);

t_bool						init_key(t_game *game);

char						*concat_str(t_game *game, char *str, char *add);

t_bool						init_map(t_game *game, char *file);

t_bool						init_player(t_game *game);

void						get_matrix_rot(float m[2][2], float angle);

void						get_matrix_multi(float res[2], float vect[2],
		float m[2][2]);

void						projection(t_game *game);

t_bool						init_projection(t_game *game);

void						vect_norm(float vect[2]);

t_bool						is_in_map(t_game *game, int point[2]);

int							get_num_map(t_game *game, int point[2]);

float						get_distance(int pos[2], int point[2]);

void						get_intersection(t_game *game, int res[2],
		int horiz[2], int vert[2]);

t_bool						line_intersection(int res[2], int line[2][2],
		int pos[2], float dir[2]);

float						wall_detection(t_game *game, int res[2],
		float dir[2]);

t_bool						right_intersection(int res[2], int right[2][2],
		int pos[2], float dir[2]);

void						vect_cpy(int dest[2], int src[2]);

t_bool						get_first_horiz(t_game *game, int res[2],
		int pos[2], float dir[2]);

t_bool						get_first_vert(t_game *game, int res[2],
		int pos[2], float dir[2]);

t_bool						horizontal_inter(t_game *game, int res[2],
		float dir[2]);

t_bool						vertical_inter(t_game *game, int res[2],
		float dir[2]);

t_bool						init_image(t_game *game);

void						put_pxl(t_game *game, int x, int y,
		unsigned int color);

void						put_background(t_game *game, unsigned int ceiling,
		unsigned int floor);

void						put_col(t_game *game, int col, float height);

void						paint(t_game *game);

void						show_menu(t_game *game);

t_texture					read_texture(t_game *game, char *filename,
		int width, int height);

void						hit_wall(t_game *game, float height,
		int coord[2], int col);

int							get_cadrant_rad(double angle);

t_bool						is_exeption(double angle);

int							get_cadrant_degree(int angle);

t_texture					*get_texture(t_game *game, int idx);

t_bool						init_list_texture(t_game *game);

int							mouse_press(int button, int x, int y, t_game *game);

int							mouse_release(int button, int x, int y,
		t_game *game);

int							mouse_move(int x, int y, t_game *game);

t_bool						init_mouse(t_game *game);

void						mute_song(t_game *game);

void						change_song(t_game *game);

t_bool						init_sound(t_game *game);

void						transpose_texture(t_texture *t);

t_bool						check_map(t_game *game);

int							check_song(t_game *game, const char *str);

#endif
