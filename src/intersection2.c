/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:04:34 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/24 19:27:32 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	verify_intersect(t_ray *ray, t_object *obj, t_vec t12)
{
	t_env_verif e;

	e.mate = NULL;
	e.begin = NULL;
	e.extr = NULL;
	if (obj && obj->transf != NULL)
	{
		obj_to_mate(ray, obj, &e.extr, t12);
		e.mate = extrude(ray, obj->transf, e.extr);
		e.begin = e.mate;
		t12.x = INT_MAX;
		t12.y = INT_MAX;
		obj = NULL;
		verify_intersect2(ray, obj, t12, &e);
		e.mate = e.begin;
	}
	else
	{
		if (obj->transf != NULL)
			t12 = surf_transf(ray, obj->transf, t12);
		verify_t(ray, obj, t12.x);
		verify_t(ray, obj, t12.y);
	}
}

void	verify_intersect2(t_ray *ray, t_object *obj, t_vec t12, t_env_verif *e)
{
	while (e->mate != NULL)
	{
		if ((e->mate->t1 > ray->tmin && e->mate->t1 < t12.x && \
					e->mate->t1 < t12.y && e->mate->t1 < ray->tmax) || \
				(e->mate->t2 > ray->tmin && e->mate->t2 < t12.x && \
				e->mate->t2 < t12.y && e->mate->t2 < ray->tmax))
		{
			t12.x = e->mate->t1;
			t12.y = e->mate->t2;
			obj = e->mate->obj1;
		}
		e->mate = e->mate->next;
	}
	e->mate = e->begin;
	if (e->mate != NULL)
		remove_all_mate(e->mate);
	verify_intersect3(ray, obj, t12);
}

void	verify_intersect3(t_ray *ray, t_object *obj, t_vec t12)
{
	if (obj)
	{
		if (obj->volume == 1 && t12.x < 0 && t12.y > ray->tmin)
			verify_t(ray, obj, 0.011);
		else
		{
			verify_t(ray, obj, t12.x);
			if (obj->volume == 0)
				verify_t(ray, obj, t12.y);
		}
	}
}

void	find_intersect(t_frame *frame, t_ray *ray)
{
	t_object	*tmp;

	ray->obj_intersect = NULL;
	ray->t = INT_MAX;
	tmp = OBJECT_B;
	while (tmp != NULL)
	{
		if ((ft_vec_equal(ray->orig, tmp->orig) == 0) || (tmp->type != LIGHT))
			verify_intersect(ray, tmp, intersect_shape(ray, tmp));
		tmp = tmp->next;
	}
	return ;
}

t_vec	intersect(t_ray *ray, t_frame *frame)
{
	t_vec		color;

	find_intersect(frame, ray);
	if (ray->obj_intersect != NULL && ray->t != INT_MAX)
	{
		if (OBJ_I->type != LIGHT)
			color = intersect_color(frame, ray);
		else
			color = OBJ_I->color;
	}
	else
		color = BG_COLOR;
	return (color);
}
