/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:11:50 by cbruno            #+#    #+#             */
/*   Updated: 2019/04/23 10:05:42 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_bool			tst_split(char **tmp)
{
	int		i;

	i = 0;
	while (*tmp != NULL)
	{
		i++;
		tmp++;
	}
	if (i != 2)
		return (false);
	return (true);
}

void			check_spawn(t_game *game, char **tmp, int res[2])
{
	res[0] = ft_atoi(tmp[0]);
	res[1] = ft_atoi(tmp[1]);
	if (res[0] >= game->map.width
			|| (res[0] <= 0)
			|| res[1] >= game->map.length || res[1] <= 0)
		print_error(game);
	res[0] = res[0] * BLOCK_SIZE + BLOCK_SIZE / 2;
	res[1] = res[1] * BLOCK_SIZE + BLOCK_SIZE / 2;
	if (get_num_map(game, res) == 1)
		print_error(game);
}

t_bool			init_position(t_game *game, int res[2])
{
	int		fd;
	char	*line;
	char	**tmp;

	if (!(fd = open(game->file, O_RDONLY)))
		print_error(game);
	else
	{
		if (get_next_line(fd, &line) == 1)
		{
			tmp = ft_split_whitespace(line);
			free(line);
			if (tst_split(tmp) == false)
				return (false);
			check_spawn(game, tmp, res);
		}
		else
			return (false);
	}
	if (close(fd) == -1)
		print_error(game);
	return (true);
}

t_bool			init_player(t_game *game)
{
	t_player	self;

	if (init_position(game, self.position) == false)
		return (false);
	self.direction[0] = 1.0;
	self.direction[1] = 0.0;
	vect_norm(self.direction);
	self.fov = M_PI / 3;
	self.distance_plan = (WIDTH / 2) / tan(M_PI / 6);
	game->player = self;
	return (true);
}
