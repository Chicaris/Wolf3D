/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 11:20:33 by bruno             #+#    #+#             */
/*   Updated: 2019/04/26 09:24:17 by hde-moff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*str;
	size_t		i;

	if ((str = (char *)malloc((size + 1) * sizeof(char))) == NULL)
		exit(1);
	i = 0;
	while (i < size)
	{
		((char *)str)[i] = 0;
		i++;
	}
	str[size] = '\0';
	return (str);
}
