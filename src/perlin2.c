/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:20:38 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/16 22:40:13 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double		linear_interpolate(double a, double b, double t)
{
	return (1. - t) * a + t * b;
}

double		fast_dot(const int *v, const double x,
		const double y, const double z)
{
	return (v[0] * x + v[1] * y + v[2] * z);
}
