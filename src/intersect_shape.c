/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:37:12 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/16 17:43:31 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_vec			intersect_plan(t_ray *ray, t_object *object)
{
	t_vec		t12;
	double		d;
	t_vec		ao;

	t12 = ft_vec_create(INT_MAX, INT_MAX, 0.);
	d = ft_vec_dot(object->data, ray->dir);
	if (d == 0.)
	{
		if (ft_vec_dot(object->data, \
			ft_vec_linear(1., ray->orig, -1., object->orig)) == 0.)
			t12.x = ray->tmin;
		else
			t12.x = -INT_MAX;
		return (t12);
	}
	else
	{
		ao = ft_vec_linear(1., ray->orig, -1., object->orig);
		t12.x = -1. * ft_vec_dot(object->data, ao) / d;
	}
	return (t12);
}

static t_vec	solve_delta(double k[3])
{
	t_vec		t12;
	double		delta;

	t12 = ft_vec_create(INT_MAX, INT_MAX, 0.);
	delta = k[1] * k[1] - 4. * k[0] * k[2];
	if (delta < 0.01)
		return (t12);
	else
	{
		t12.x = (-k[1] - sqrt(delta)) / (2. * k[0]);
		t12.y = (-k[1] + sqrt(delta)) / (2. * k[0]);
	}
	if (t12.x > t12.y)
	{
		delta = t12.x;
		t12.x = t12.y;
		t12.y = delta;
	}
	return (t12);
}

t_vec			intersect_sphere(t_ray *ray, t_object *obj)
{
	t_vec		t12;
	double		k[3];

	k[0] = ft_vec_dot(ray->dir, ray->dir);
	k[1] = 2. * ft_vec_dot(ft_vec_linear(1., ray->orig, -1., obj->orig)
			, ray->dir);
	k[2] = ft_norme2(ft_vec_linear(1., obj->orig, -1., ray->orig))
		- obj->r * obj->r;
	t12 = solve_delta(k);
	return (t12);
}

t_vec			intersect_cyl(t_ray *ray, t_object *obj)
{
	t_vec		t12;
	double		k[3];
	t_vec		x;

	x = ft_vec_linear(1., ray->orig, -1., obj->orig);
	k[0] = ft_vec_dot(ray->dir, ray->dir)
		- pow(ft_vec_dot(ray->dir, obj->data), 2);
	k[1] = 2. * (ft_vec_dot(ray->dir, x) - ft_vec_dot(ray->dir, obj->data)
			* ft_vec_dot(obj->data, x));
	k[2] = ft_vec_dot(x, x) - pow(ft_vec_dot(x, obj->data), 2) - obj->r
		* obj->r;
	t12 = solve_delta(k);
	return (t12);
}

t_vec			intersect_cone(t_ray *ray, t_object *obj)
{
	t_vec		t12;
	double		k[3];
	t_vec		c;

	c = ft_vec_linear(1., ray->orig, -1., obj->orig);
	k[0] = ft_norme2(ray->dir) - (1. + obj->r)
		* pow(ft_vec_dot(ray->dir, obj->data), 2);
	k[1] = 2. * (ft_vec_dot(ray->dir, c) - (1. + obj->r)
			* ft_vec_dot(ray->dir, obj->data) * ft_vec_dot(c, obj->data));
	k[2] = ft_norme2(c) - (1. + obj->r) * pow(ft_vec_dot(c, obj->data), 2);
	t12 = solve_delta(k);
	return (t12);
}
