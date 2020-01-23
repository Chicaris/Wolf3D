/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:58:39 by cbruno            #+#    #+#             */
/*   Updated: 2019/04/19 14:31:26 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		free_list_texture(t_game *game)
{
	t_list_texture		*begin;
	t_list_texture		*tmp;

	begin = game->texture_list;
	while (begin != NULL)
	{
		tmp = begin->next;
		free(begin);
		begin = tmp;
	}
}

void			free_all(t_game *game)
{
	if (game->file != NULL)
		free(game->file);
	if (game->texture_list != NULL)
		free_list_texture(game);
	if (game->graphic.win_ptr != NULL)
	{
		if (game->image.img_ptr != NULL)
			mlx_destroy_image(game->graphic.mlx_ptr, game->image.img_ptr);
		mlx_destroy_window(game->graphic.mlx_ptr, game->graphic.win_ptr);
	}
	system("killall afplay 2&>/dev/null >/dev/null");
	exit(0);
}

int				red_cross(t_game *game)
{
	free_all(game);
	exit(0);
	return (0);
}
