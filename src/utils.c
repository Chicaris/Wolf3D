/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:48:32 by cbruno            #+#    #+#             */
/*   Updated: 2019/04/23 09:40:04 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_bool		is_in_map(t_game *game, int point[2])
{
	t_bool	res;

	res = false;
	if (point[0] >= 0 && point[0] < game->map.length * BLOCK_SIZE)
		res = true;
	if (point[1] >= 0 && point[1] < game->map.width * BLOCK_SIZE)
		res = true;
	return (res);
}

float		get_distance(int pos[2], int point[2])
{
	float dx;
	float dy;

	dx = (point[0] - pos[0]);
	dy = (point[1] - pos[1]);
	return (sqrtf(dx * dx + dy * dy));
}

int			get_num_map(t_game *game, int point[2])
{
	int		i;
	int		j;

	i = point[0] / BLOCK_SIZE;
	if ((point[0] % BLOCK_SIZE) == 0 && game->player.position[0] > point[0])
		i -= 1;
	j = point[1] / BLOCK_SIZE;
	if ((point[1] % BLOCK_SIZE) == 0 && game->player.position[1] > point[1])
		j -= 1;
	if (i >= 0 && i < game->map.length && j >= 0 && j < game->map.width)
		return (game->map.p_grid[i][j]);
	else
		return (-1);
}

void		select_intersection(t_game *game, int res[2], float *distance,
		t_intersect_info i)
{
	float	dist_horiz;
	float	dist_vert;

	dist_horiz = get_distance(game->player.position, i.horiz);
	dist_vert = get_distance(game->player.position, i.vert);
	if (dist_horiz < dist_vert)
	{
		vect_cpy(res, i.horiz);
		*distance = dist_horiz;
	}
	else
	{
		vect_cpy(res, i.vert);
		*distance = dist_vert;
	}
}

float		wall_detection(t_game *game, int res[2], float dir[2])
{
	t_intersect_info	i;
	int					horiz[2];
	int					vert[2];
	float				distance;

	if (horizontal_inter(game, horiz, dir) == false)
	{
		vect_cpy(res, vert);
		distance = get_distance(game->player.position, vert);
	}
	else if (vertical_inter(game, vert, dir) == false)
	{
		vect_cpy(res, horiz);
		vect_cpy(res, horiz);
		distance = get_distance(game->player.position, horiz);
	}
	else
	{
		vect_cpy(i.horiz, horiz);
		vect_cpy(i.vert, vert);
		select_intersection(game, res, &distance, i);
	}
	return (distance);
}
