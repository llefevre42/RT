/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:40:35 by rpinault          #+#    #+#             */
/*   Updated: 2018/02/20 17:10:55 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_norme(t_vec a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_vec		ft_normalize(t_vec a)
{
	double	tmp;
	t_vec	b;

	tmp = sqrt(ft_vec_dot(a, a));
	if (tmp != 0.)
	{
		b.x = a.x / tmp;
		b.y = a.y / tmp;
		b.z = a.z / tmp;
	}
	else
	{
		b.x = 0.;
		b.y = 0.;
		b.z = 0.;
	}
	return (b);
}

double		ft_norme2(t_vec a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}

_Bool		ft_vec_equal(t_vec a, t_vec b)
{
	if ((a.x == b.x) && (a.y == b.y) && (a.z == b.z))
		return (1);
	else
		return (0);
}

t_vec		ft_vec_cross(t_vec b, t_vec c)
{
	t_vec	a;

	a.x = b.y * c.z - b.z * c.y;
	a.y = b.z * c.x - b.x * c.z;
	a.z = b.x * c.y - b.y * c.x;
	return (a);
}
