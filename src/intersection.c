/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:29:01 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/28 16:19:15 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_vec			intersect_shape(t_ray *ray, t_object *tmp)
{
	if ((tmp->type == SPHERE) || (tmp->type == LIGHT))
		return (intersect_sphere(ray, tmp));
	else if (tmp->type == PLAN)
		return (intersect_plan(ray, tmp));
	else if (tmp->type == CYLINDRE)
		return (intersect_cyl(ray, tmp));
	else if (tmp->type == CONE)
		return (intersect_cone(ray, tmp));
	else if (tmp->type == QUAD)
		return (intersect_quad(ray, tmp));
	else
		return (ft_vec_create(INT_MAX, INT_MAX, 0.));
}

void			verify_t(t_ray *ray, t_object *obj, double t)
{
	if (obj && t < ray->tmax && t > ray->tmin && t < ray->t)
	{
		ray->t = t;
		ray->obj_intersect = obj;
	}
	return ;
}

t_material		*extrude(t_ray *ray, t_object *obj, t_material *src)
{
	t_material	*extr;

	extr = NULL;
	obj_to_mate(ray, obj, &extr, intersect_shape(ray, obj));
	if (obj->transf != NULL)
		extr = extrude(ray, obj->transf, extr);
	if (obj->next_transf != NULL)
		src = extrude(ray, obj->next_transf, src);
	if (obj->transf_type == EXTRUSION || obj->transf_type == EXTRUSION_INV)
		src = obj_extr(src, extr, obj->volume);
	else if (obj->transf_type == INTERSECTION)
		src = obj_inter_volume(src, extr);
	else if (obj->transf_type == UNION)
		add_mate(extr, &src);
	return (src);
}

t_vec			surf_extrude(t_ray *ray, \
		t_object *obj, t_vec t12, t_vec t34)
{
	if (obj->type != PLAN)
	{
		if (t12.x >= t34.x && t12.x <= t34.y)
			t12.x = INT_MAX;
		if (t12.y >= t34.x && t12.y <= t34.y)
			t12.y = INT_MAX;
	}
	else if (obj->type == PLAN)
	{
		if ((ft_vec_dot(ray->dir, obj->data) >= 0. && t12.x >= t34.x) \
				|| (ft_vec_dot(ray->dir, obj->data) <= 0 && t12.x <= t34.x))
			t12.x = INT_MAX;
		if ((ft_vec_dot(ray->dir, obj->data) >= 0. && t12.y >= t34.x) \
				|| (ft_vec_dot(ray->dir, obj->data) <= 0 && t12.y <= t34.x))
			t12.y = INT_MAX;
	}
	return (t12);
}

t_vec			surf_extrude_inv(t_object *obj, t_vec t12, t_vec t34)
{
	if (obj->type != PLAN)
	{
		if (t12.x < t34.x || t12.x > t34.y)
			t12.x = INT_MAX;
		if (t12.y < t34.x || t12.y > t34.y)
			t12.y = INT_MAX;
	}
	return (t12);
}
