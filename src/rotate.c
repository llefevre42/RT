/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:45:43 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/17 14:41:29 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_mat		chg_rep_mat(t_mat m, t_mat v)
{
	t_mat	nv;

	nv.a = m.a * v.a + m.b * v.d + m.c * v.g;
	nv.b = m.a * v.b + m.b * v.e + m.c * v.h;
	nv.c = m.a * v.c + m.b * v.f + m.c * v.i;
	nv.d = m.d * v.a + m.e * v.d + m.f * v.g;
	nv.e = m.d * v.b + m.e * v.e + m.f * v.h;
	nv.f = m.d * v.c + m.e * v.f + m.f * v.i;
	nv.g = m.g * v.a + m.h * v.d + m.i * v.g;
	nv.h = m.g * v.b + m.h * v.e + m.i * v.h;
	nv.i = m.g * v.c + m.h * v.f + m.i * v.i;
	return (nv);
}

t_vec		chg_rep_vec(t_mat m, t_vec v)
{
	t_vec	nv;

	nv = ft_vec_create(0., 0., 0.);
	nv.x = m.a * v.x + m.b * v.y + m.c * v.z;
	nv.y = m.d * v.x + m.e * v.y + m.f * v.z;
	nv.z = m.g * v.x + m.h * v.y + m.i * v.z;
	return (nv);
}

t_mat		mat_rot_x(double theta)
{
	t_mat	rot;

	rot.a = 1.;
	rot.b = 0.;
	rot.c = 0.;
	rot.d = 0.;
	rot.e = cos(theta);
	rot.f = -sin(theta);
	rot.g = 0.;
	rot.h = sin(theta);
	rot.i = cos(theta);
	return (rot);
}

t_mat		mat_rot_y(double theta)
{
	t_mat	rot;

	rot.a = cos(theta);
	rot.b = 0.;
	rot.c = sin(theta);
	rot.d = 0.;
	rot.e = 1.;
	rot.f = 0.;
	rot.g = -sin(theta);
	rot.h = 0.;
	rot.i = cos(theta);
	return (rot);
}

t_mat		mat_rot_z(double theta)
{
	t_mat	rot;

	rot.a = cos(theta);
	rot.b = -sin(theta);
	rot.c = 0.;
	rot.d = sin(theta);
	rot.e = cos(theta);
	rot.f = 0.;
	rot.g = 0.;
	rot.h = 0.;
	rot.i = 1.;
	return (rot);
}
