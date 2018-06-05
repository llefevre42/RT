/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:58:20 by yhemme            #+#    #+#             */
/*   Updated: 2018/05/28 16:19:03 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	first_choice(int *c, t_vec *color)
{
	if ((c[0] % 2 == 0 && c[1] % 2 == 0) ||
			(c[0] % 2 != 0 && c[1] % 2 != 0))
	{
		color->x = 1.;
		color->y = 1.;
		color->z = 1.;
	}
	else
	{
		color->x = 0.;
		color->y = 0.;
		color->z = 0.;
	}
}

void	second_choice(int *c, t_vec *color)
{
	if ((c[0] % 2 == 0 && c[1] % 2 == 0) ||
			(c[0] % 2 != 0 && c[1] % 2 != 0))
	{
		color->x = 0.;
		color->y = 0.;
		color->z = 0.;
	}
	else
	{
		color->x = 1.;
		color->y = 1.;
		color->z = 1.;
	}
}

t_vec	check_texture(t_ray ray)
{
	t_vec	inter;
	t_vec	chess;
	int		c[3];
	t_vec	color;

	color = ft_vec_create(0., 0., 0.);
	inter = ft_vec_linear(1., ray.orig, ray.t, ray.dir);
	chess = ft_vec_linear(1., inter, -1., ray.obj_intersect->orig);
	chess = inter;
	c[0] = (int)(round(chess.x / 30.));
	c[1] = (int)(round(chess.y / 30.));
	c[2] = (int)(round(chess.z / 30.));
	if (c[2] % 2 == 0)
		first_choice(c, &color);
	else
		second_choice(c, &color);
	return (color);
}
