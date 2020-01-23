/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:15:33 by cbruno            #+#    #+#             */
/*   Updated: 2019/03/07 01:23:18 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			show_menu(t_game *game)
{
	t_texture	texture_menu;
	int			i;
	int			j;

	i = 0;
	texture_menu = read_texture(game, "assets/images/main_menu.xpm", 1280, 800);
	while (i < LENGTH)
	{
		j = 0;
		while (j < WIDTH)
		{
			game->image.img[i * WIDTH + j] = texture_menu.data[i * WIDTH + j];
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->graphic.mlx_ptr, game->graphic.win_ptr,
			game->image.img_ptr, 0, 0);
}
