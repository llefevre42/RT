/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:01:10 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/30 13:13:06 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			add_quad(t_object **dst, int type)
{
	t_object	*p_object;

	p_object = (t_object*)ft_memalloc(sizeof(t_object));
	init_object(p_object);
	p_object->type = QUAD;
	add_object(dst, p_object, type);
	return ;
}

static t_vec	intersect_quad2(t_vec t12)
{
	double		tmp;

	if (t12.x > t12.y)
	{
		tmp = t12.x;
		t12.x = t12.y;
		t12.y = tmp;
	}
	return (t12);
}

t_vec			intersect_quad(t_ray *ray, t_object *object)
{
	t_vec		a;
	double		delta;
	t_vec		x;
	t_vec		t12;

	t12 = ft_vec_create(INT_MAX, INT_MAX, 0.);
	x = ft_vec_linear(1., ray->orig, -1., object->orig);
	a.x = ft_quad_calc(ray->dir, Q, ray->dir);
	a.y = ft_quad_calc(x, Q, ray->dir) + ft_quad_calc(ray->dir, Q, x)
		+ ft_vec_dot(U, ray->dir);
	a.z = ft_quad_calc(x, Q, x) + object->quad.k + ft_vec_dot(U, x);
	if ((delta = a.y * a.y - 4. * a.x * a.z) < 0)
		return (t12);
	else if (a.z != 0)
	{
		t12.x = (-a.y + sqrt(delta)) / (2. * a.x);
		t12.y = (-a.y - sqrt(delta)) / (2. * a.x);
	}
	else if (a.x == 0 && a.y != 0)
		t12.x = -a.z / a.y;
	return (intersect_quad2(t12));
}

t_vec			gradient_quad(t_object *object, t_vec p)
{
	t_vec		grad;

	grad.x = 2 * Q.a * p.x + (Q.b + Q.d)
		* p.y + (Q.c + Q.g) * p.z + U.x;
	grad.y = 2 * Q.e * p.y + (Q.b + Q.d)
		* p.x + (Q.f + Q.h) * p.z + U.y;
	grad.z = 2 * Q.i * p.z + (Q.c + Q.g)
		* p.x + (Q.f + Q.h) * p.y + U.z;
	grad = ft_normalize(grad);
	return (grad);
}
