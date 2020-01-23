/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:43:44 by cbruno            #+#    #+#             */
/*   Updated: 2019/04/26 09:25:15 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

char	*concat_str(t_game *game, char *str, char *add)
{
	char	*tmp;

	if ((tmp = ft_strdup(str)) == NULL)
		print_error(game);
	if ((str = ft_strjoin(tmp, add)) == NULL)
		print_error(game);
	free(tmp);
	if ((tmp = ft_strdup(str)) == NULL)
		print_error(game);
	if ((str = ft_strjoin(tmp, "  ")) == NULL)
		print_error(game);
	free(tmp);
	free(add);
	return (str);
}

void	print_usage(void)
{
	ft_putendl("usage: ./wolf3d [filename]");
	exit(0);
}

void	print_error(t_game *game)
{
	ft_putendl("error");
	free_all(game);
}
