/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:07:19 by cbruno            #+#    #+#             */
/*   Updated: 2019/03/07 01:18:49 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_bool	is_point_visible(float dir[2], int pos[2], int point[2])
{
	int		vect[2];
	float	scalar_product;

	vect[0] = pos[0] - point[0];
	vect[1] = pos[1] - point[1];
	scalar_product = vect[0] * dir[0] + vect[1] * dir[1];
	if (scalar_product > 0.0)
		return (false);
	return (true);
}

t_bool	get_first_horiz(t_game *game, int res[2], int pos[2], float dir[2])
{
	int		line[2][2];
	t_bool	rv;

	line[0][0] = 0;
	line[0][1] = ((pos[1] / BLOCK_SIZE)) * BLOCK_SIZE;
	line[1][0] = game->map.length * BLOCK_SIZE;
	line[1][1] = ((pos[1] / BLOCK_SIZE)) * BLOCK_SIZE;
	rv = false;
	if (line_intersection(res, line, pos, dir) == true)
	{
		rv = true;
		if (is_point_visible(dir, pos, res) == false)
		{
			line[0][1] += BLOCK_SIZE;
			line[1][1] += BLOCK_SIZE;
			line_intersection(res, line, pos, dir);
		}
	}
	return (rv);
}

t_bool	get_first_vert(t_game *game, int res[2], int pos[2], float dir[2])
{
	int			line[2][2];
	t_bool		rv;

	line[0][0] = ((pos[0] / BLOCK_SIZE)) * BLOCK_SIZE;
	line[0][1] = 0;
	line[1][0] = ((pos[0] / BLOCK_SIZE)) * BLOCK_SIZE;
	line[1][1] = game->map.width * BLOCK_SIZE;
	rv = false;
	if (line_intersection(res, line, pos, dir) == true)
	{
		rv = true;
		if (is_point_visible(dir, pos, res) == false)
		{
			line[0][0] += BLOCK_SIZE;
			line[1][0] += BLOCK_SIZE;
			line_intersection(res, line, pos, dir);
		}
	}
	return (rv);
}

t_bool	horizontal_inter(t_game *game, int res[2], float dir[2])
{
	int	start_pos[2];

	if (get_first_horiz(game, start_pos, game->player.position, dir) == false)
		return (false);
	vect_cpy(res, start_pos);
	while (get_num_map(game, res) == 0)
	{
		if (dir[1] < 0)
			res[1] -= BLOCK_SIZE;
		else
			res[1] += BLOCK_SIZE;
		res[0] = start_pos[0] + round(dir[0] /
				dir[1] * (float)(res[1] - start_pos[1]));
	}
	return (true);
}

t_bool	vertical_inter(t_game *game, int res[2], float dir[2])
{
	int	start_pos[2];

	if (get_first_vert(game, start_pos, game->player.position, dir) == false)
		return (false);
	vect_cpy(res, start_pos);
	while (get_num_map(game, res) == 0)
	{
		if (dir[0] < 0)
			res[0] -= BLOCK_SIZE;
		else
			res[0] += BLOCK_SIZE;
		res[1] = start_pos[1] + round(dir[1] /
				dir[0] * (float)(res[0] - start_pos[0]));
	}
	return (true);
}
