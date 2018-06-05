/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:10:00 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/21 14:44:54 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_ambiante(t_frame *frame, t_pars *p)
{
	ft_skiptobracket(p);
	SCENE.lum_amb = atof_custom(&p->f[p->i]);
	ft_endbracket(p);
}

void	ft_back(t_frame *frame, t_pars *p)
{
	ft_skiptobracket(p);
	BG_COLOR.x = atof_custom(&p->f[p->i]);
	ft_comma(p);
	BG_COLOR.y = atof_custom(&p->f[p->i]);
	ft_comma(p);
	BG_COLOR.z = atof_custom(&p->f[p->i]);
	ft_endbracket(p);
}

void	ft_size(t_frame *frame, t_pars *p)
{
	ft_skiptobracket(p);
	frame->video.width = atof_custom(&p->f[p->i]);
	ft_comma(p);
	frame->video.height = atof_custom(&p->f[p->i]);
	ft_endbracket(p);
}

t_mat	ft_rotation(t_frame *frame, t_pars *p)
{
	t_mat	out;
	t_vec	vec;
	double	val;
	int		i;

	i = frame ? 1 : 0;
	ft_skiptobracket(p);
	val = atof_custom(&p->f[p->i]);
	ft_comma(p);
	vec.x = atof_custom(&p->f[p->i]);
	ft_comma(p);
	vec.y = atof_custom(&p->f[p->i]);
	ft_comma(p);
	vec.z = atof_custom(&p->f[p->i]);
	ft_endbracket(p);
	out = mat_rot_u(val * M_PI / 180., ft_normalize(vec));
	return (out);
}

t_mat	ft_point(t_frame *frame, t_pars *p)
{
	t_mat	out;
	t_vec	vec;

	ft_skiptobracket(p);
	vec.x = atof_custom(&p->f[p->i]) - CAM.orig.x;
	ft_comma(p);
	vec.y = atof_custom(&p->f[p->i]) - CAM.orig.y;
	ft_comma(p);
	vec.z = atof_custom(&p->f[p->i]) - CAM.orig.z;
	ft_endbracket(p);
	out = mat_rot_u(acos(ft_vec_dot(ft_vec_create(0., 0., -1.), vec)),\
			ft_normalize(ft_vec_cross(ft_vec_create(0., 0., -1.), vec)));
	return (out);
}
