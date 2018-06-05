/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:18:33 by rpinault          #+#    #+#             */
/*   Updated: 2018/02/12 18:43:17 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec		ft_vec_mult(t_vec a, t_vec b)
{
	t_vec	c;

	c.x = a.x * b.x;
	c.y = a.y * b.y;
	c.z = a.z * b.z;
	return (c);
}

t_vec		ft_vec_create(double x, double y, double z)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec		ft_vec_scal(double k, t_vec a)
{
	a.x *= k;
	a.y *= k;
	a.z *= k;
	return (a);
}

double		ft_vec_dot(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec		ft_vec_linear(double a, t_vec u, double b, t_vec v)
{
	t_vec	res;

	res.x = a * u.x + b * v.x;
	res.y = a * u.y + b * v.y;
	res.z = a * u.z + b * v.z;
	return (res);
}
