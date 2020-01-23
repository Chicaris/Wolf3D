/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:06:55 by cbruno            #+#    #+#             */
/*   Updated: 2019/04/22 18:12:19 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			mute_song(t_game *game)
{
	if (game->option != 0)
	{
		if (game->sound.status == true)
		{
			game->sound.status = false;
			system("killall afplay 2&>/dev/null >/dev/null");
		}
		else
		{
			system("killall afplay 2&>/dev/null >/dev/null");
			game->sound.status = true;
			system(game->sound.song);
		}
	}
}

int				check_song(t_game *game, const char *str)
{
	int		i;
	char	**strarr;

	if ((strarr = ft_strsplit(str, ' ')) == NULL)
		print_error(game);
	if (access(strarr[1], F_OK) == -1)
		print_error(game);
	i = 0;
	while (strarr[i])
		free(strarr[i++]);
	free(strarr);
	return (1);
}

void			change_song_2(t_game *game)
{
	if (game->sound.numb == 0)
	{
		game->sound.numb = 1;
		if (check_song(game, "afplay ./assets/songs/flymetothemoon.mp3 &"))
			game->sound.song = "afplay ./assets/songs/flymetothemoon.mp3 &";
	}
	else if (game->sound.numb == 1)
	{
		game->sound.numb = 0;
		if (check_song(game, "afplay ./assets/songs/sunshine.mp3 &"))
			game->sound.song = "afplay ./assets/songs/sunshine.mp3 &";
	}
}

void			change_song(t_game *game)
{
	system("killall afplay 2&>/dev/null >/dev/null");
	if (game->option == 0)
	{
		if (check_song(game, "afplay ./assets/songs/falling_in_love.mp3 &"))
			game->sound.song = "afplay ./assets/songs/falling_in_love.mp3 &";
	}
	else
	{
		change_song_2(game);
	}
	system(game->sound.song);
}

t_bool			init_sound(t_game *game)
{
	t_sound		self;

	self.status = true;
	self.numb = 0;
	self.song = "afplay ./assets/songs/falling_in_love.mp3 &";
	game->sound = self;
	return (true);
}
