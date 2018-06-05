/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 19:55:22 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/16 23:22:13 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_mat		mat_rot_u(double theta, t_vec u)
{
	t_mat	rot;

	rot.a = u.x * u.x + (1. - u.x * u.x) * cos(theta);
	rot.b = u.x * u.y * (1 - cos(theta)) - u.z * sin(theta);
	rot.c = u.x * u.z * (1. - cos(theta)) + u.y * sin(theta);
	rot.d = u.x * u.y * (1. - cos(theta)) + u.z * sin(theta);
	rot.e = u.y * u.y + (1. - u.y * u.y) * cos(theta);
	rot.f = u.y * u.z * (1. - cos(theta)) - u.x * sin(theta);
	rot.g = u.x * u.z * (1. - cos(theta)) - u.y * sin(theta);
	rot.h = u.y * u.z * (1. - cos(theta)) + u.x * sin(theta);
	rot.i = u.z * u.z + (1. - u.z * u.z) * cos(theta);
	return (rot);
}
