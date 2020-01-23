/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:16:54 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/21 13:16:57 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_rotate_x(float dst[4][4], float angle)
{
	matrix_unit(dst);
	dst[1][1] = cos(angle);
	dst[2][2] = dst[1][1];
	dst[2][1] = sin(angle);
	dst[1][2] = -dst[2][1];
}
