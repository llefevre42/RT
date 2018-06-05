/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 20:02:06 by rpinault          #+#    #+#             */
/*   Updated: 2018/02/13 18:17:52 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat		ft_mat_null(void)
{
	t_mat	z;

	z.a = 0.;
	z.b = 0.;
	z.c = 0.;
	z.d = 0.;
	z.e = 0.;
	z.f = 0.;
	z.g = 0.;
	z.h = 0.;
	z.i = 0.;
	return (z);
}

t_mat		ft_mat_id(void)
{
	t_mat	z;

	z.a = 1.;
	z.b = 0.;
	z.c = 0.;
	z.d = 0.;
	z.e = 1.;
	z.f = 0.;
	z.g = 0.;
	z.h = 0.;
	z.i = 1.;
	return (z);
}

t_mat		ft_mat_mult(t_mat x, t_mat y)
{
	t_mat	z;

	z.a = x.a * y.a + x.b * y.d + x.c * y.g;
	z.b = x.a * y.b + x.b * y.e + x.c * y.h;
	z.c = x.a * y.c + x.b * y.f + x.c * y.i;
	z.d = x.d * y.a + x.e * y.d + x.f * y.g;
	z.e = x.d * y.b + x.e * y.e + x.f * y.h;
	z.f = x.d * y.c + x.e * y.f + x.f * y.i;
	z.g = x.f * y.a + x.g * y.d + x.h * y.g;
	z.h = x.f * y.b + x.g * y.e + x.h * y.h;
	z.i = x.f * y.c + x.g * y.f + x.h * y.i;
	return (z);
}

t_vec		ft_vec_product(t_vec a, t_vec b)
{
	t_vec	r;

	r.x = (a.y * b.z) - (a.z * b.y);
	r.y = (a.z * b.x) - (a.x * b.z);
	r.z = (a.x * b.y) - (a.y * b.x);
	return (r);
}
