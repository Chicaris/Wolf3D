/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:10:50 by cbruno            #+#    #+#             */
/*   Updated: 2019/03/07 01:06:42 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		get_cadrant_rad(double angle)
{
	if (angle > 0.0 && angle < 180.0 / 2)
		return (1);
	if (angle > 180.0 / 2 && angle < 180.0)
		return (2);
	if (angle > 180.0 && angle < 180.0 * 1.5)
		return (3);
	if (angle > 180.0 * 1.5 && angle < 180.0 * 2)
		return (4);
	return (0);
}

t_bool	is_exeption(double angle)
{
	t_bool		res;
	double		epsilon;

	epsilon = 1e7;
	res = true;
	if (fabs(angle - 0.0) < epsilon)
		res = false;
	if (fabs(angle - 90.0) < epsilon)
		res = false;
	if (fabs(angle - 180.0) < epsilon)
		res = false;
	if (fabs(angle - 225.0) < epsilon)
		res = false;
	return (res);
}

int		get_cadrant_degree(int angle)
{
	if (angle > 0 && angle < 180 / 2)
		return (1);
	if (angle > 180 / 2 && angle < 180)
		return (2);
	if (angle > 180 && angle < 180 * 1.5)
		return (3);
	if (angle > 180 * 1.5 && angle < 180 * 2)
		return (4);
	return (0);
}
