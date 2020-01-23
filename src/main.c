/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:27:48 by cbruno            #+#    #+#             */
/*   Updated: 2019/04/22 18:05:08 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		prev_init(t_game *game)
{
	game->file = NULL;
	game->graphic.win_ptr = NULL;
	game->image.img_ptr = NULL;
	game->texture_list = NULL;
}

t_bool			init_game(t_game *game, char *file)
{
	prev_init(game);
	game->file = ft_strdup(file);
	if (init_graphic(game) == false)
		return (false);
	if (init_image(game) == false)
		return (false);
	if (init_map(game, file) == false)
		return (false);
	if (check_map(game) == false)
		return (false);
	if (init_player(game) == false)
		return (false);
	if (init_list_texture(game) == false)
		return (false);
	if (init_mouse(game) == false)
		return (false);
	if (init_sound(game) == false)
		return (false);
	if (init_projection(game) == false)
		return (false);
	game->option = menu;
	check_song(game, "afplay ./assets/songs/falling_in_love.mp3 &");
	system("afplay ./assets/songs/falling_in_love.mp3 &");
	return (true);
}

int				main(int argc, char *argv[])
{
	t_game game;

	if (argc != 2)
		print_usage();
	else
	{
		if (init_game(&game, argv[1]) == false)
			print_error(&game);
		mainloop(&game);
	}
	return (true);
}
