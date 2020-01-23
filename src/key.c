/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:54:16 by cbruno            #+#    #+#             */
/*   Updated: 2019/04/20 18:59:22 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	rotate_camera(t_game *game, float angle)
{
	float	m[2][2];

	get_matrix_rot(m, angle);
	get_matrix_multi(game->player.direction, game->player.direction, m);
	vect_norm(game->player.direction);
	paint(game);
}

int		key_press(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == KEY_ESC)
		free_all(game);
	if (key == KEY_LEFT || key == KEY_A)
		rotate_camera(game, -M_PI / 18);
	if (key == KEY_RIGHT || key == KEY_D)
		rotate_camera(game, M_PI / 18);
	if (key == KEY_UP || key == KEY_W)
		move_camera(game, 10);
	if (key == KEY_DOWN || key == KEY_S)
		move_camera(game, -10);
	return (0);
}

int		deal_key(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == KEY_ESC)
		free_all(game);
	if (key == KEY_M)
		mute_song(game);
	if (key == KEY_N)
		change_song(game);
	if (key == KEY_LEFT)
		rotate_camera(game, -M_PI / 18);
	if (key == KEY_RIGHT)
		rotate_camera(game, M_PI / 18);
	if (key == KEY_UP)
		move_camera(game, 10);
	if (key == KEY_DOWN)
		move_camera(game, -10);
	return (0);
}
