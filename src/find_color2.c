/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_color2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:02:55 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/16 17:37:42 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		color_sum2(t_frame *frame, t_ray *ray, t_lum lum, t_env_color *e)
{
	e->transp = 0.;
	if (OBJ_I != NULL && OBJ_I->transp != 0.)
	{
		e->transp = OBJ_I->transp;
		e->tmp_ray.orig = ft_vec_linear(1., ray->orig, ray->t, ray->dir);
		color_sum3(frame, ray, lum, e);
	}
	if (e->color.x > 1.)
		e->color.x = 1.;
	if (e->color.y > 1.)
		e->color.y = 1.;
	if (e->color.z > 1.)
		e->color.z = 1.;
}

void		color_sum3(t_frame *frame, t_ray *ray, t_lum lum, t_env_color *e)
{
	if (fabs(OBJ_I->indice - ray->indice) < 0.0001 && ray->indice != 1.)
	{
		e->tmp_ray.dir = ft_vec_linear(-e->tmp_ray.indice  \
			* ft_vec_dot(lum.norm, e->tmp_ray.dir) - sqrt(1. - \
			pow(e->tmp_ray.indice, 2) * (1. - \
			pow(ft_vec_dot(lum.norm, e->tmp_ray.dir), 2))), \
			lum.norm, e->tmp_ray.indice, e->tmp_ray.dir);
		e->tmp_ray.indice = 1.;
	}
	else if (fabs(OBJ_I->indice - ray->indice) > 0.0001)
	{
		e->tmp_ray.dir = ft_vec_linear(-e->tmp_ray.indice / OBJ_I->indice \
		* ft_vec_dot(lum.norm, e->tmp_ray.dir) - sqrt(1. - \
		pow(e->tmp_ray.indice / OBJ_I->indice, 2) * (1. - \
		pow(ft_vec_dot(lum.norm, e->tmp_ray.dir), 2))), \
		lum.norm, e->tmp_ray.indice / OBJ_I->indice, e->tmp_ray.dir);
		e->tmp_ray.indice = OBJ_I->indice;
	}
	else
		e->tmp_ray.dir = ray->dir;
	e->color = ft_vec_linear(1. - e->transp / 100., \
			e->color, e->transp / 100., intersect(&e->tmp_ray, frame));
}

void		lum_direct(t_frame *frame, t_ray *ray, t_lum *lum)
{
	t_light		light;

	init_light(&light);
	light.i.z = frame->scene.lumvec;
	lum->lp = ft_normalize(frame->scene.lumvec_dir);
	lum->dist = 10000;
	phong_shading(ray, &light, lum);
}

t_vec		intersect_color(t_frame *frame, t_ray *ray)
{
	t_env_inter e;

	e.tmp_light = LIGHT_B;
	init_ray(&e.light_ray);
	init_lum(&e.lum);
	e.p = ft_vec_linear(1., ray->orig, ray->t, ray->dir);
	e.lum.norm = find_normal(ray, e.p);
	while (e.tmp_light != NULL)
	{
		e.tmp_l = *e.tmp_light;
		init_ray(&e.light_ray);
		e.light_ray.orig = e.tmp_light->orig;
		e.lum.lp = ft_normalize(ft_vec_linear(1., e.p, -1., e.light_ray.orig));
		e.lum.dist = ft_norme2(ft_vec_linear(1., e.p, -1., e.light_ray.orig));
		e.light_ray.dir = e.lum.lp;
		find_intersect(frame, &e.light_ray);
		e.pq2 = ft_norme2(ft_vec_linear(1., ft_vec_linear(1., \
			e.light_ray.orig, e.light_ray.t, e.light_ray.dir), -1., e.p));
		intersect_color2(frame, ray, &e);
	}
	if (frame->scene.lumvec != 0)
		lum_direct(frame, ray, &e.lum);
	return (color_sum(frame, ray, e.lum));
}

void		intersect_color2(t_frame *frame, t_ray *ray, t_env_inter *e)
{
	while (e->light_ray.obj_intersect != NULL \
			&& e->light_ray.obj_intersect->transp != 0 && e->pq2 > 0.005)
	{
		e->tmp_l.color = ft_vec_scal(e->light_ray.obj_intersect->transp / \
		100., ft_vec_linear(e->light_ray.obj_intersect->transp / 100., \
		e->tmp_light->color, 1. - e->light_ray.obj_intersect->transp / 100., \
		ft_vec_mult(e->light_ray.obj_intersect->color, e->tmp_light->color)));
		e->light_ray.orig = ft_vec_linear(1., \
				e->light_ray.orig, e->light_ray.t, e->light_ray.dir);
		find_intersect(frame, &e->light_ray);
		e->pq2 = ft_norme2(ft_vec_linear(1., ft_vec_linear(1., \
		e->light_ray.orig, e->light_ray.t, e->light_ray.dir), -1., e->p));
	}
	if (e->pq2 < 0.005)
		phong_shading(ray, &e->tmp_l, &e->lum);
	e->tmp_light = e->tmp_light->next;
}
