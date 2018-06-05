/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:04:05 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/21 14:06:16 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void		init_quad(t_object *obj)
{
	obj->quad.q.a = 0.;
	obj->quad.q.b = 0.;
	obj->quad.q.c = 0.;
	obj->quad.q.d = 0.;
	obj->quad.q.e = 0.;
	obj->quad.q.f = 0.;
	obj->quad.q.g = 0.;
	obj->quad.q.h = 0.;
	obj->quad.q.i = 0.;
	obj->quad.u.x = 0.;
	obj->quad.u.y = 0.;
	obj->quad.u.z = 0.;
}

void			init_object(t_object *obj)
{
	obj->type = 0;
	obj->orig = ft_vec_create(0., 0., 0.);
	obj->r = 10.;
	obj->data.x = 1.;
	obj->data.y = 0.;
	obj->data.z = 0.;
	obj->color.x = 0.;
	obj->color.y = 0.;
	obj->color.z = 0.;
	obj->alpha = 50.;
	obj->limit.x0 = -1234;
	obj->limit.x1 = -1234;
	obj->limit.y0 = -1234;
	obj->limit.y1 = -1234;
	obj->limit.z0 = -1234;
	obj->limit.z1 = -1234;
	init_object2(obj);
}

void			init_object2(t_object *obj)
{
	obj->ka = 1.;
	obj->kd = 1.;
	obj->ks = 1.;
	obj->transp = 0.;
	obj->reflec = 0.;
	obj->indice = 1.;
	obj->matiere = NORMAL;
	obj->rug = 0.;
	obj->volume = 0;
	obj->transf = NULL;
	obj->next_transf = NULL;
	obj->next = NULL;
	obj->transf_type = EXTRUSION;
	obj->next = NULL;
	init_quad(obj);
}

void			init_ray(t_ray *ray)
{
	ray->dir = ft_vec_create(0., 0., 0.);
	ray->orig = ft_vec_create(0., 0., 0.);
	ray->tmin = 0.01;
	ray->tmax = INT_MAX;
	ray->t = INT_MAX;
	ray->reflec = 0.01;
	ray->indice = 1.;
	ray->obj_intersect = NULL;
}

void			init_lum(t_lum *lum)
{
	lum->lum_d = ft_vec_create(0., 0., 0.);
	lum->lum_s = ft_vec_create(0., 0., 0.);
	lum->lp = ft_vec_create(0., 0., 0.);
	lum->norm = ft_vec_create(0., 0., 0.);
	lum->dist = 0.;
}
