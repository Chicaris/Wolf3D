/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:39:03 by cbruno            #+#    #+#             */
/*   Updated: 2019/03/07 13:54:42 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_bool		init_graphic(t_game *game)
{
	t_graphic	self;

	self.title = "WOLF3D";
	self.x_center = LENGTH / 2;
	self.y_center = WIDTH / 2;
	self.x_min = -self.x_center;
	self.x_max = self.x_center;
	self.y_min = -self.y_center;
	self.y_max = self.y_center;
	if (!(self.mlx_ptr = mlx_init()))
		print_error(game);
	if (!(self.win_ptr = mlx_new_window(self.mlx_ptr,
					WIDTH, LENGTH, self.title)))
		print_error(game);
	game->graphic = self;
	return (true);
}

void		mainloop(t_game *game)
{
	paint(game);
	mlx_key_hook(game->graphic.win_ptr, deal_key, game);
	mlx_hook(game->graphic.win_ptr, KEYPRESS, 0, key_press, game);
	mlx_hook(game->graphic.win_ptr, MOUSEPRESS, 0, mouse_press, game);
	mlx_hook(game->graphic.win_ptr, MOUSERELEASE, 0, mouse_release, game);
	mlx_hook(game->graphic.win_ptr, MOUSEMOVE, 0, mouse_move, game);
	mlx_hook(game->graphic.win_ptr, 17, 1L << 17, &red_cross, game);
	mlx_loop(game->graphic.mlx_ptr);
}
