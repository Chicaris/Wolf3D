/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:01:05 by cbruno            #+#    #+#             */
/*   Updated: 2019/03/07 14:35:46 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			get_matrix_multi(float res[2], float vect[2], float m[2][2])
{
	res[0] = vect[0] * m[0][0] + vect[1] * m[0][1];
	res[1] = vect[0] * m[1][0] + vect[1] * m[1][1];
}

static float	wall_proj(t_game *game, float dist, float angle)
{
	float	theta;

	theta = (-M_PI / 6) + angle;
	dist *= cos(theta);
	return ((BLOCK_SIZE * game->player.distance_plan / dist));
}

void			projection(t_game *game)
{
	float	vect[2];
	int		point[2];
	float	matrix[2][2];
	float	height;
	int		col;

	col = 0;
	get_matrix_rot(matrix, -M_PI / 6);
	get_matrix_multi(vect, game->player.direction, matrix);
	get_matrix_rot(matrix, game->projection.step_angle);
	while (col < WIDTH)
	{
		height = wall_proj(game, wall_detection(game, point, vect),
				game->projection.step_angle * col);
		hit_wall(game, height, point, col);
		get_matrix_rot(matrix, game->projection.step_angle);
		get_matrix_multi(vect, vect, matrix);
		col++;
	}
	mlx_put_image_to_window(game->graphic.mlx_ptr, game->graphic.win_ptr,
			game->image.img_ptr, 0, 0);
}

t_bool			init_projection(t_game *game)
{
	t_proj	self;

	self.x_center = WIDTH / 2;
	self.y_center = LENGTH / 2;
	self.distance_proj = (WIDTH / 2) / tan((game->player.fov) / 2);
	self.step_angle = (float)game->player.fov / WIDTH;
	game->projection = self;
	return (true);
}
