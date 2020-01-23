/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 10:33:37 by cbruno            #+#    #+#             */
/*   Updated: 2019/04/22 14:51:03 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				mouse_press(int button, int x, int y, t_game *game)
{
	if (game->option == 0)
	{
		if (x < 740 && x > 540 && y > 480 && y < 580)
		{
			game->option = play;
			change_song(game);
		}
		if (x < 740 && x > 540 && y > 635 && y < 735)
			free_all(game);
		paint(game);
	}
	if (game->option == 1)
	{
		game->mouse.status = true;
		if (button == 1)
		{
			game->mouse.button = 1;
			game->mouse.last[0] = x;
			game->mouse.last[1] = y;
		}
	}
	return (0);
}

int				mouse_release(int button, int x, int y, t_game *game)
{
	int		tmp;

	tmp = button;
	if (game->mouse.button == 1)
	{
		game->mouse.status = false;
		game->mouse.current[0] = x;
		game->mouse.current[1] = y;
	}
	game->mouse.button = 0;
	return (0);
}

int				mouse_move(int x, int y, t_game *game)
{
	double	delta_x;
	float	theta;

	if (game->mouse.status == true && game->mouse.button == 1)
	{
		if (x > 0 && x < WIDTH && y > 0 && y < LENGTH)
		{
			delta_x = game->mouse.last[0] - x;
			game->mouse.current[0] += delta_x;
			game->mouse.last[0] = x;
			theta = atan(delta_x / game->player.distance_plan);
			rotate_camera(game, theta);
		}
	}
	return (0);
}

t_bool			init_mouse(t_game *game)
{
	t_mouse		self;

	self.status = false;
	self.button = 0;
	self.current[0] = 0;
	self.current[1] = 0;
	self.last[0] = 0;
	self.last[1] = 0;
	game->mouse = self;
	return (true);
}
