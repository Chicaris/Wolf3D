/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-moff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:40:26 by hde-moff          #+#    #+#             */
/*   Updated: 2019/04/18 17:33:36 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void					ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void					transpose_texture(t_texture *t)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i < t->width)
	{
		j = i + 1;
		while (j < t->width)
		{
			ft_swap(&t->data[(t->width * i) + j], &t->data[(t->width * j) + i]);
			j++;
		}
		i++;
	}
}

t_texture				read_texture(t_game *game, char *filename,
		int width, int height)
{
	t_texture		texture;
	t_image			image;

	image.img_ptr = mlx_xpm_file_to_image(game->graphic.mlx_ptr, filename,
			&width, &height);
	if (image.img_ptr == NULL)
		print_error(game);
	image.img = (int *)mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.size_x), &(image.endian));
	texture.height = height;
	texture.width = width;
	texture.data = image.img;
	return (texture);
}
