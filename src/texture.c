/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:27:56 by cbruno            #+#    #+#             */
/*   Updated: 2019/04/22 15:19:31 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int								get_size_list(t_list_texture *list)
{
	int		i;

	i = 0;
	while (list->next != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}

t_texture						*get_texture(t_game *game, int idx)
{
	int				i;
	t_list_texture	*list;

	i = 0;
	list = game->texture_list;
	while (i <= idx && list != NULL)
	{
		if (i == idx)
			return (&list->texture);
		list = list->next;
		i++;
	}
	return (NULL);
}

static t_list_texture			*create_list(t_game *game, char *str)
{
	t_list_texture	*new;

	if (!(new = (t_list_texture *)malloc(sizeof(t_list_texture))))
		return (NULL);
	else
	{
		new->texture = read_texture(game, str, BLOCK_SIZE, BLOCK_SIZE);
		transpose_texture(&(new->texture));
		new->next = NULL;
	}
	return (new);
}

t_bool							init_list_texture(t_game *game)
{
	t_list_texture	*self;
	t_list_texture	*tmp;

	self = create_list(game, "assets/images/stone_clean.xpm");
	tmp = self;
	tmp->next = create_list(game, "assets/images/wolf_dark_wall.xpm");
	tmp = tmp->next;
	tmp->next = create_list(game, "assets/images/wolf_dirt_wall.xpm");
	tmp = tmp->next;
	tmp->next = create_list(game, "assets/images/wolf_stone_wall.xpm");
	tmp = tmp->next;
	game->texture_list = self;
	return (true);
}
