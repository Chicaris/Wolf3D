/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-moff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:18:26 by hde-moff          #+#    #+#             */
/*   Updated: 2019/04/26 09:39:26 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int							dst_height_clip_check(int dst_y_cursor)
{
	if (dst_y_cursor >= LENGTH || dst_y_cursor < 0)
		return (0);
	return (1);
}

void						draw_column(t_game *game, t_col_info i)
{
	float	src_cursor;
	int		dst_y_cur;
	float	step;

	src_cursor = (i.x * i.texture->width);
	dst_y_cur = (LENGTH / 2) - (i.height / 2);
	step = i.texture->width / (float)i.height;
	while (i.height > 0)
	{
		if (dst_height_clip_check(dst_y_cur))
			put_pxl(game, i.col, dst_y_cur, i.texture->data[(int)src_cursor]);
		src_cursor += step;
		i.height--;
		dst_y_cur++;
	}
}

void						hit_wall(t_game *game, float height,
		int coord[2], int col)
{
	t_col_info	col_info;

	col_info.height = (int)height;
	col_info.col = col;
	if (coord[0] % 64 == 0)
	{
		if (game->player.position[0] > coord[0])
			col_info.texture = get_texture(game, N_TEXTURE);
		else
			col_info.texture = get_texture(game, S_TEXTURE);
		col_info.x = coord[1] % 64;
	}
	else if (coord[1] % 64 == 0)
	{
		if (game->player.position[1] > coord[1])
			col_info.texture = get_texture(game, E_TEXTURE);
		else
			col_info.texture = get_texture(game, W_TEXTURE);
		col_info.x = coord[0] % 64;
	}
	else
		print_error(game);
	draw_column(game, col_info);
}
