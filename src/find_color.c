/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:58:45 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/16 17:38:03 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_vec			find_normal(t_ray *ray, t_vec p)
{
	t_vec	n;

	n = ft_vec_create(0., 0., 0.);
	if (ray->obj_intersect->type == SPHERE)
		n = ft_vec_linear(1., p, -1., ray->obj_intersect->orig);
	else if (ray->obj_intersect->type == CYLINDRE)
	{
		n = ft_vec_linear(ft_vec_dot(ft_vec_linear(1., OBJ_I->orig, -1., p),
					OBJ_I->data), OBJ_I->data, 1., ft_vec_linear(1., p, -1.,
						OBJ_I->orig));
	}
	else if (ray->obj_intersect->type == CONE)
	{
		n = ft_vec_linear((1. + OBJ_I->r) * ft_vec_dot(ft_vec_linear(1.,
						OBJ_I->orig, -1., p), OBJ_I->data), OBJ_I->data, 1.,
				ft_vec_linear(1., p, -1., OBJ_I->orig));
	}
	else if (ray->obj_intersect->type == QUAD)
		n = gradient_quad(ray->obj_intersect
				, ft_vec_linear(1, p, -1, ray->obj_intersect->orig));
	else if (ray->obj_intersect->type == PLAN)
		n = ray->obj_intersect->data;
	return (find_normal2(ray, p, n));
}

t_vec			find_normal2(t_ray *ray, t_vec p, t_vec n)
{
	n = ft_normalize(ft_vec_scal(((-1.) * ft_vec_dot(ray->dir, n)), n));
	if (ray->obj_intersect->matiere == EAU)
	{
		n = ft_vec_linear(1, n, 0.2 * ray->obj_intersect->rug, \
				ft_vec_create(smooth_noise_3d(p.x, p.y, p.z, 20.), \
					smooth_noise_3d(p.x, p.y, p.z, 20.), \
					smooth_noise_3d(p.x, p.y, p.z, 20.)));
		n = ft_normalize(ft_vec_linear(1., n, 0.4 * \
				ray->obj_intersect->rug, ft_vec_create(smooth_noise_3d(0.1 \
				* p.x, p.y, p.z, 100.), smooth_noise_3d(0.1 * p.x, p.y, p.z, \
				100.), smooth_noise_3d(0.1 * p.x, p.y, p.z, 100.))));
	}
	return (n);
}

void			phong_shading(t_ray *ray, t_light *t, t_lum *l)
{
	t_vec		r;
	double		theta;

	r = ft_vec_create(0., 0., 0.);
	theta = ft_vec_dot(l->norm, l->lp) * (-1.);
	if ((theta > 0.) && (ray->obj_intersect->kd != 0.))
		l->lum_d = ft_vec_linear(1., l->lum_d, t->i.z * \
				t->i.x * theta / (0.1 + 0.00002 * l->dist), t->color);
	if (theta > 0. && ray->obj_intersect->ks != 0. && t->i.y != 0.)
	{
		r = ft_normalize(ft_vec_linear(2. * theta, l->norm, 1., l->lp));
		if (ft_vec_dot(r, ray->dir) < 0)
			l->lum_s = ft_vec_linear(1., l->lum_s, t->i.z * t->i.y
					* pow((-1) * ft_vec_dot(r, ray->dir), OBJ_I->alpha)
					/ (0.1 + 0.00002 * l->dist), t->color);
	}
}

static t_vec	color_reflect(t_frame *frame, \
		t_ray *ray, t_lum lum, t_vec color)
{
	t_ray	tmp_ray;
	double	reflec;

	init_ray(&tmp_ray);
	ray->reflec = ray->reflec + 1.;
	tmp_ray = *ray;
	tmp_ray.orig = ft_vec_linear(1., ray->orig, ray->t, ray->dir);
	tmp_ray.dir = ft_normalize(ft_vec_linear(1., \
				ray->dir, -2. * ft_vec_dot(lum.norm, ray->dir), lum.norm));
	reflec = tmp_ray.obj_intersect->reflec;
	color = ft_vec_linear(reflec, intersect(&tmp_ray, frame), \
			1. - reflec, color);
	return (color);
}

t_vec			color_sum(t_frame *frame, t_ray *ray, t_lum lum)
{
	t_env_color		e;

	init_ray(&e.tmp_ray);
	e.tmp_ray = *ray;
	if (OBJ_I->matiere == PIERRE)
		e.color = apply_tex(frame, "./textures/pierre.xpm", \
				ray->obj_intersect, ray);
	else if (frame->scene.check && OBJ_I != NULL)
		e.color = check_texture(e.tmp_ray);
	else
		e.color = OBJ_I->color;
	e.color = ft_vec_mult(e.color, ft_vec_linear(OBJ_I->ka * SCENE.lum_amb,
				ft_vec_create(1., 1., 1.), 1.,
				ft_vec_linear(OBJ_I->kd, lum.lum_d, OBJ_I->ks, lum.lum_s)));
	if (OBJ_I != NULL && OBJ_I->reflec > 0.1)
	{
		if (ray->reflec <= 6)
			e.color = color_reflect(frame, ray, lum, e.color);
		else
			e.color = ft_vec_scal(0., e.color);
	}
	color_sum2(frame, ray, lum, &e);
	return (e.color);
}
