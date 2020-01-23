/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:24:00 by cbruno            #+#    #+#             */
/*   Updated: 2019/03/18 09:28:01 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void inline		put_pxl(t_game *game, int x, int y, unsigned int color)
{
	game->image.img[(y * WIDTH) + x] = color;
}

void			*color_idx_range(void *in)
{
	t_bg_fill_info	*fill_info;
	unsigned int	i;

	fill_info = (t_bg_fill_info *)in;
	i = fill_info->start;
	while (i < fill_info->stop)
		fill_info->game->image.img[i++] = fill_info->color;
	return (NULL);
}

void			put_background(t_game *game, unsigned int ceiling,
		unsigned int floor)
{
	t_bg_fill_info	fill_info[NUM_THREADS];
	int				i;
	int				fill_length;
	int				rc;

	i = 0;
	fill_length = (LENGTH * WIDTH) / NUM_THREADS;
	while (i < NUM_THREADS)
	{
		fill_info[i].game = game;
		fill_info[i].stop = (fill_length * (i + 1));
		fill_info[i].start = fill_info[i].stop - fill_length;
		fill_info[i].color = ((i + 1) > (NUM_THREADS / 2))
			? floor : ceiling;
		rc = pthread_create(&game->threads[i], NULL, color_idx_range,
				(void *)&fill_info[i]);
		if (rc)
			print_error(game);
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
		pthread_join(game->threads[i++], NULL);
}

void			put_col(t_game *game, int col, float height)
{
	int		i;

	i = 0;
	while (i < WIDTH)
	{
		if ((i > (LENGTH / 2) - (height / 2)) && (i < (LENGTH / 2) +
					(height / 2)))
			put_pxl(game, col, i, GREEN);
		i++;
	}
}

void			paint(t_game *game)
{
	if (game->option == 0)
		show_menu(game);
	if (game->option == 1)
	{
		put_background(game, CEILING_COL, FLOOR_COL);
		projection(game);
	}
}
