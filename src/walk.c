/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-moff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:41:47 by hde-moff          #+#    #+#             */
/*   Updated: 2019/04/21 17:39:03 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		check_up_wall(t_game *game, int npos[2])
{
	int	tmp[2];
	int	up_wall_y;

	if (npos[1] <= 64)
		up_wall_y = 64;
	else
		up_wall_y = ((npos[1] / 64) + 1) * 64;
	tmp[0] = npos[0];
	tmp[1] = up_wall_y;
	if (get_num_map(game, tmp) == 1)
	{
		if (up_wall_y - npos[1] > WALK_DIST)
			return (1);
		else
			return (0);
	}
	return (1);
}

int		check_down_wall(t_game *game, int npos[2])
{
	int	tmp[2];
	int	down_wall_y;

	if (npos[1] <= 64)
		down_wall_y = 0;
	else
		down_wall_y = (npos[1] / 64) * 64;
	tmp[0] = npos[0];
	tmp[1] = down_wall_y;
	if (get_num_map(game, tmp) == 1)
	{
		if (npos[1] - down_wall_y > WALK_DIST)
			return (1);
		else
			return (0);
	}
	return (1);
}

int		check_left_wall(t_game *game, int npos[2])
{
	int	tmp[2];
	int	left_wall_x;

	if (npos[0] <= 64)
		left_wall_x = 0;
	else
		left_wall_x = (npos[0] / 64) * 64;
	tmp[0] = left_wall_x;
	tmp[1] = npos[1];
	if (get_num_map(game, tmp) == 1)
	{
		if (npos[0] - left_wall_x > WALK_DIST)
			return (1);
		else
			return (0);
	}
	return (1);
}

int		check_right_wall(t_game *game, int npos[2])
{
	int	tmp[2];
	int	right_wall_x;

	if (npos[0] <= 64)
		right_wall_x = 0;
	else
		right_wall_x = ((npos[0] / 64) + 1) * 64;
	tmp[0] = right_wall_x;
	tmp[1] = npos[1];
	if (get_num_map(game, tmp) == 1)
	{
		if (right_wall_x - npos[0] > WALK_DIST)
			return (1);
		else
			return (0);
	}
	return (1);
}

void	move_camera(t_game *game, int step)
{
	int	tmp[2];
	int	delta[2];

	vect_cpy(tmp, game->player.position);
	delta[0] = (int)round(step * game->player.direction[0]);
	delta[1] = (int)round(step * game->player.direction[1]);
	tmp[0] += delta[0];
	tmp[1] += delta[1];
	if (delta[0] > 0 && check_right_wall(game, tmp))
		game->player.position[0] += delta[0];
	else if (delta[0] < 0 && check_left_wall(game, tmp))
		game->player.position[0] += delta[0];
	if (delta[1] > 0 && check_up_wall(game, tmp))
		game->player.position[1] += delta[1];
	else if (delta[1] < 0 && check_down_wall(game, tmp))
		game->player.position[1] += delta[1];
	paint(game);
}
