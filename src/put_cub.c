/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 03:53:48 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/11 01:47:45 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

unsigned int		*put_in_img(int x, int y, unsigned int *img, t_tri *lst)
{
	int x_max;
	int y_max;
	int tmp;

	tmp = x;
	x_max = x + lst->l;
	y_max = y + lst->h;
	while (y < y_max + 1)
	{
		x = tmp;
		while (x < x_max)
		{
			if (y > 0)
				img[x + ((y - 1) * lst->lsize)] = lst->color;
			x++;
		}
		y++;
	}
	return (img);
}
