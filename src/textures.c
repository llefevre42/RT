/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:33:24 by yhemme            #+#    #+#             */
/*   Updated: 2018/05/01 17:30:42 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vec	get_color(int x, int y, t_texture *tex)
{
	int		i;
	t_vec	color;

	color = ft_vec_create(0, 0, 0);
	i = 4 * (x + (y * tex->w));
	if (x < tex->h && y < tex->w)
	{
		color.z = (unsigned char)tex->img[i] / 255.0f;
		color.y = (unsigned char)tex->img[i + 1] / 255.0f;
		color.x = (unsigned char)tex->img[i + 2] / 255.0f;
	}
	return (color);
}

t_vec	wrap_plan(t_frame *e, t_ray *ray, t_object *obj, t_texture *tex)
{
	double	u;
	double	v;
	t_vec	d;

	d = ft_vec_linear(1, ray->orig, ray->t, ray->dir);
	if (obj->data.y == 0 && obj->data.x == 0)
		d.z = d.y;
	else if (obj->data.y == 0)
		d.x = d.y;
	d.x += e->move_x_tex;
	d.z += e->move_z_tex;
	u = (d.x) / (e->stretch_tex);
	v = (d.z) / (e->stretch_tex);
	if (e->repeat_tex)
	{
		u = u < 0 ? -u : u;
		v = v < 0 ? -v : v;
		u = u - (int)u;
		v = v - (int)v;
	}
	if (u > 0 && u < 1 && v > 0 && v < 1)
		d = get_color(u * tex->w, v * tex->h, tex);
	else
		d = obj->color;
	return (d);
}

t_vec	wrap_c(t_ray *ray, t_object *obj, t_texture *tex)
{
	t_vec	sub;
	double	u;
	double	v;
	t_vec	d;

	sub = ft_vec_linear(1, ray->orig, ray->t, ray->dir);
	sub = ft_vec_linear(1, sub, -1, obj->orig);
	sub = chg_rep_vec(mat_rot_u(acos(ft_vec_dot(obj->data, \
		ft_vec_create(0, 1, 0))), ft_vec_cross(obj->data, \
		ft_vec_create(0, 1, 0))), sub);
	u = sub.y * 0.5 + 0.5;
	v = -atan2(sub.x, sub.z) / (2 * M_PI) + 0.5;
	u /= 50;
	u = u < 0 ? -u : u;
	v = v < 0 ? -v : v;
	u = u - (int)u;
	u = u * tex->w;
	v = v * tex->h;
	if (u > 0 && v > 0)
		d = get_color(v, u, tex);
	else
		d = obj->color;
	return (d);
}

t_vec	wrap_sphere(t_ray *ray, t_object *obj, t_texture *tex)
{
	double	u;
	double	v;
	t_vec	d;

	d = ft_vec_linear(1, obj->orig, -1, \
		ft_vec_linear(1, ray->orig, ray->t, ray->dir));
	d = ft_normalize(d);
	u = 0.5 + (atan2(d.z, d.x) / (2.0 * M_PI));
	v = 0.5 - (asin(d.y) / M_PI);
	u = 1 - u;
	v = 1 - v;
	u = u * tex->w;
	v = v * tex->h;
	if (u * v < tex->w * tex->h && u >= 0 && v > 0)
		return (get_color(u, v, tex));
	return (obj->color);
}

t_vec	apply_tex(t_frame *frame, char *name, t_object *obj, t_ray *ray)
{
	t_texture *tex;

	if (!(tex = get_tex(frame, name)))
		return (obj->color);
	if (obj->type == PLAN)
		return (wrap_plan(frame, ray, obj, tex));
	if (obj->type == SPHERE)
		return (wrap_sphere(ray, obj, tex));
	if (obj->type == CONE || obj->type == CYLINDRE)
		return (wrap_c(ray, obj, tex));
	return (obj->color);
}
