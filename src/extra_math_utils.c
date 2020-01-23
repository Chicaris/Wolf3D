/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_math_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-moff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 01:17:51 by hde-moff          #+#    #+#             */
/*   Updated: 2019/03/07 14:35:07 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	get_matrix_rot(float m[2][2], float angle)
{
	m[0][0] = cos(angle);
	m[0][1] = -sin(angle);
	m[1][0] = sin(angle);
	m[1][1] = cos(angle);
}

t_bool	invers_matrix(float res[2][2], float m[2][2])
{
	float	det;

	det = (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
	if (fabs(det) < FLT_EPSILON)
		return (false);
	res[0][0] = (1.0 / det) * m[1][1];
	res[0][1] = -(1.0 / det) * m[0][1];
	res[1][0] = -(1.0 / det) * m[1][0];
	res[1][1] = (1.0 / det) * m[0][0];
	return (true);
}

t_bool	line_intersection(int res[2], int line[2][2], int pos[2], float dir[2])
{
	float	matrix[2][2];
	float	inv[2][2];
	float	cst[2];

	matrix[0][0] = (line[1][1] - line[0][1]);
	matrix[0][1] = -(line[1][0] - line[0][0]);
	matrix[1][0] = dir[1];
	matrix[1][1] = -dir[0];
	cst[0] = line[1][1] * line[0][0] - line[1][0] * line[0][1];
	cst[1] = dir[1] * pos[0] - dir[0] * pos[1];
	if (invers_matrix(inv, matrix) == true)
	{
		res[0] = (int)round(cst[0] * inv[0][0] + cst[1] * inv[0][1]);
		res[1] = (int)round(cst[0] * inv[1][0] + cst[1] * inv[1][1]);
		return (true);
	}
	else
		return (false);
}

void	vect_cpy(int dest[2], int src[2])
{
	dest[0] = src[0];
	dest[1] = src[1];
}

void	vect_norm(float vect[2])
{
	float	length;

	length = sqrtf(vect[0] * vect[0] + vect[1] * vect[1]);
	vect[0] = vect[0] / length;
	vect[1] = vect[1] / length;
}
