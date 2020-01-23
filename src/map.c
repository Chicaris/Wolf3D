/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-moff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 01:22:18 by hde-moff          #+#    #+#             */
/*   Updated: 2019/04/21 17:26:58 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int			get_nbr_line(t_game *game)
{
	int		fd;
	int		res;
	char	*line;

	res = 0;
	if (!(fd = open(game->file, O_RDONLY)))
		print_error(game);
	else
	{
		while (get_next_line(fd, &line) == 1)
		{
			free(line);
			res++;
		}
	}
	if (close(fd) == -1)
		print_error(game);
	return (res - 1);
}

static void			get_nbr_char(t_game *game)
{
	int		i;

	i = 0;
	while (game->map.grid[i] != NULL)
		i++;
	if (game->map.length <= 1 || game->map.width <= 1)
		print_error(game);
	game->map.length = i / game->map.width;
}

void				generate_p_grid(t_game *game)
{
	int i;
	int j;

	i = 0;
	game->map.p_grid = NULL;
	if ((game->map.p_grid =
				malloc(sizeof(int *) * game->map.length)) == NULL)
		print_error(game);
	while (i < game->map.length)
	{
		if ((game->map.p_grid[i] =
					malloc(sizeof(int) * game->map.width)) == NULL)
			print_error(game);
		j = 0;
		while (j < game->map.width)
		{
			game->map.p_grid[i][j] = ft_atoi(game->map.grid[i
					+ j * game->map.length]);
			j++;
		}
		i++;
	}
}

static t_bool		read_file(t_game *game, char *file)
{
	int		fd;
	char	*line;
	char	*str;

	game->map.width = get_nbr_line(game);
	if (!(str = ft_strnew(0)))
		print_error(game);
	if (!(fd = open(file, O_RDONLY)))
		print_error(game);
	else
	{
		if (get_next_line(fd, &line) == 1)
		{
			free(line);
			while (get_next_line(fd, &line) == 1)
				str = concat_str(game, str, line);
			game->map.grid = ft_split_whitespace(str);
			get_nbr_char(game);
		}
		else
			return (false);
	}
	if (close(fd) == -1)
		print_error(game);
	return (true);
}

t_bool				init_map(t_game *game, char *file)
{
	if (read_file(game, file) == false)
		return (false);
	generate_p_grid(game);
	return (true);
}
