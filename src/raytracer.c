/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 21:14:33 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/17 16:31:04 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_ray			ray_pixel_to_scene(double i, double j, t_frame *frame)
{
	t_ray		ray;
	double		theta;
	double		gamma;

	init_ray(&ray);
	if (CAM.type == SPHERE)
	{
		gamma = (-FOV / WIDTH * i + FOV / 2.) * WIDTH / HEIGHT * M_PI / 180.;
		theta = (FOV / HEIGHT * j + (180. - FOV) / 2.) * M_PI / 180.;
		ray.dir.x = -sin(theta) * sin(gamma);
		ray.dir.y = cos(theta);
		ray.dir.z = -sin(theta) * cos(gamma);
	}
	else if (CAM.type == PLAN)
	{
		ray.dir.x = (2. * i - WIDTH) / HEIGHT * tan(FOV / 2. * M_PI / 180.);
		ray.dir.y = (-2. * j + HEIGHT) / HEIGHT * tan(FOV / 2. * M_PI / 180.);
		ray.dir.z = -1.;
		ray.dir = ft_normalize(ray.dir);
	}
	return (ray);
}

void			ray_multi_thread(t_frame *frame)
{
	t_thread_s	sthread[10];
	int			i;

	i = 0;
	while (i < 10)
	{
		sthread[i].frame = frame;
		sthread[i].id = i * HEIGHT / 10;
		pthread_create(&sthread[i].thread, NULL, raytracer, &sthread[i]);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		pthread_join(sthread[i].thread, NULL);
		i++;
	}
}

void			pixel_put(t_frame *frame, int x, int y, t_vec col)
{
	int	i;
	int	j;
	int	lvl;
	int	color;

	color = ft_rgb_to_hex(apply_filter(frame, col));
	pixel_to_map(frame, x, y, color);
	if (frame->scene.px)
	{
		if (PIXEL_LVL % 2 == 0)
			lvl = PIXEL_LVL / 2;
		else
			lvl = PIXEL_LVL / 2 + 1;
		i = x - lvl;
		while (i < (x + lvl))
		{
			j = y - lvl;
			while (j < (y + lvl))
			{
				pixel_to_map(frame, i, j, color);
				j++;
			}
			i++;
		}
	}
}

t_vec			anti_aliasing(int x, int y, t_thread_s tmp_th)
{
	t_env_aa	e;

	e.col.x = 0;
	e.col.y = 0;
	e.col.z = 0;
	e.i = -0.25;
	while (e.i < 0.26)
	{
		e.j = -0.25;
		while (e.j < 0.26)
		{
			e.ray = ray_pixel_to_scene(x + e.i, y + e.j, tmp_th.frame);
			e.ray.orig = tmp_th.frame->cam.orig;
			e.ray.dir = chg_rep_vec(tmp_th.CAM.vue, e.ray.dir);
			e.col_tmp = intersect(&e.ray, tmp_th.frame);
			e.col.x = e.col.x + (e.col_tmp.x / 9);
			e.col.y = e.col.y + (e.col_tmp.y / 9);
			e.col.z = e.col.z + (e.col_tmp.z / 9);
			e.j += 0.25;
		}
		e.i += 0.25;
	}
	return (e.col);
}

void			*raytracer(void *sthread)
{
	t_env_ray e;

	e.tmp_th = *(t_thread_s*)sthread;
	e.i = 0;
	init_ray(&e.ray);
	while (e.i < e.tmp_th.WIDTH)
	{
		e.j = e.tmp_th.id;
		while (e.j < e.tmp_th.id + e.tmp_th.HEIGHT / 10)
		{
			e.ray = ray_pixel_to_scene(e.i, e.j, e.tmp_th.frame);
			e.ray.orig = e.tmp_th.frame->cam.orig;
			e.ray.dir = chg_rep_vec(e.tmp_th.CAM.vue, e.ray.dir);
			if (e.tmp_th.frame->scene.aa == 1 && e.tmp_th.frame->scene.px == 0)
				e.color = anti_aliasing(e.i, e.j, e.tmp_th);
			else
				e.color = intersect(&e.ray, e.tmp_th.frame);
			pixel_put(e.tmp_th.frame, e.i, e.j, e.color);
			e.j += (e.tmp_th.frame->scene.px ? PIXEL_LVL : 1);
		}
		e.i += (e.tmp_th.frame->scene.px ? PIXEL_LVL : 1);
	}
	pthread_exit(NULL);
}
