/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intervalle2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:35:54 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/22 15:18:48 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			mate_extr_mate2(t_material *src, t_material *extr)
{
	if (extr->t1 <= src->t1 && extr->t2 > src->t1 && extr->t2 < src->t2)
	{
		src->t1 = extr->t2;
		src->obj1 = extr->obj2;
	}
	else if (extr->t1 > src->t1 && extr->t1 < src->t2 && extr->t2 >= src->t2)
	{
		src->t2 = extr->t1;
		src->obj2 = extr->obj1;
	}
}

void			obj_to_mate4(t_ray *ray, t_object *obj,
		t_material **extr, t_vec tv)
{
	if (ft_vec_dot(obj->data, ray->dir) > 0.)
		add_mate(create_mate(tv.x, INT_MAX, obj, obj), extr);
	else if (ft_vec_dot(obj->data, ray->dir) < 0.)
		add_mate(create_mate(-INT_MAX, tv.x, obj, obj), extr);
	else
	{
		if (ft_vec_dot(obj->data, ft_vec_linear(1., \
						ray->orig, -1., obj->orig)) > 0.)
			add_mate(create_mate(-INT_MAX, INT_MAX, obj, obj), extr);
		else
			*extr = NULL;
	}
}

void			obj_to_mate3(t_ray *ray, t_object *obj,
		t_material **extr, t_vec tv)
{
	if (obj->type == CONE && tv.x != INT_MAX && ft_vec_dot(ft_vec_linear(\
					1., ft_vec_linear(1., ray->orig, tv.x, ray->dir), -1., \
					obj->orig), ft_vec_linear(1., ft_vec_linear(1., \
							ray->orig, tv.y, ray->dir), -1., obj->orig)) < 0)
		add_mate(create_mate(tv.x, tv.y, obj, obj), extr);
	else if (obj->type == PLAN)
		obj_to_mate4(ray, obj, extr, tv);
	else if (tv.x == tv.y && tv.x == INT_MAX)
		add_mate(create_mate(-INT_MAX, INT_MAX, obj, obj), extr);
	else
	{
		add_mate(create_mate(-INT_MAX, tv.x, obj, obj), extr);
		add_mate(create_mate(tv.y, INT_MAX, obj, obj), extr);
	}
}

void			obj_to_mate2(t_ray *ray, t_object *obj,
		t_material **extr, t_vec tv)
{
	if (ft_vec_dot(obj->data, ray->dir) > 0.)
		add_mate(create_mate(tv.x, INT_MAX, obj, obj), extr);
	else if (ft_vec_dot(obj->data, ray->dir) < 0.)
		add_mate(create_mate(-INT_MAX, tv.x, obj, obj), extr);
	else
	{
		if (ft_vec_dot(obj->data, ft_vec_linear(1., ray->orig,\
						-1., obj->orig)) > 0.)
			add_mate(create_mate(-INT_MAX, INT_MAX, obj, obj), extr);
		else
			return ;
	}
}

void			obj_to_mate(t_ray *ray, t_object *obj,
		t_material **extr, t_vec tv)
{
	if (obj->type == BLANK)
		return ;
	if (obj->transf_type != EXTRUSION_INV)
	{
		if (obj->type == CONE && tv.x != INT_MAX \
				&& ft_meme_signe(ft_vec_dot(ft_vec_linear(1., ft_vec_linear(1.,
								ray->orig, tv.x, ray->dir), -1., obj->orig),
						obj->data), ft_vec_dot(ft_vec_linear(1.,
								ft_vec_linear(1., ray->orig, tv.y, ray->dir),
								-1., obj->orig), obj->data)) == 0)
		{
			add_mate(create_mate(-INT_MAX, tv.x, obj, obj), extr);
			add_mate(create_mate(tv.y, INT_MAX, obj, obj), extr);
		}
		else if (obj->type == PLAN)
			obj_to_mate2(ray, obj, extr, tv);
		else
			add_mate(create_mate(tv.x, tv.y, obj, obj), extr);
	}
	else
		obj_to_mate3(ray, obj, extr, tv);
}
