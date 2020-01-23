/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 09:46:16 by cbruno            #+#    #+#             */
/*   Updated: 2019/02/23 15:16:56 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_bool		init_image(t_game *game)
{
	t_image		self;

	self.bpp = 0;
	self.size_x = 0;
	self.endian = 0;
	if (!(self.img_ptr = mlx_new_image(game->graphic.mlx_ptr, WIDTH, LENGTH)))
		return (false);
	if (!(self.img = (int *)mlx_get_data_addr(self.img_ptr, &(self.bpp),
					&(self.size_x), &(self.endian))))
		return (false);
	game->image = self;
	return (true);
}
