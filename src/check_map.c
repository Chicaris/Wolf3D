/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:11:50 by cbruno            #+#    #+#             */
/*   Updated: 2019/04/25 09:56:52 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static t_bool	is_border(t_map map, int i, int j)
{
	if (i == 0)
		return (true);
	if (i == map.width - 1)
		return (true);
	if (j == 0)
		return (true);
	if (j == map.length - 1)
		return (true);
	return (false);
}

t_bool			check_map(t_game *game)
{
	int		i;
	int		j;
	int		c;

	i = 0;
	while (i < game->map.width)
	{
		j = 0;
		while (j < game->map.length)
		{
			c = ft_atoi(game->map.grid[j + i * game->map.length]);
			if (!(c == 0 || c == 1))
				print_error(game);
			if (is_border(game->map, i, j) == true)
				if (c != 1)
					return (false);
			j++;
		}
		i++;
	}
	return (true);
}
