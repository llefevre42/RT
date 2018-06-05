/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:22:28 by rpinault          #+#    #+#             */
/*   Updated: 2018/02/12 18:40:25 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_quad_calc(t_vec v, t_mat q, t_vec w)
{
	double	res;

	res = v.x * (q.a * w.x + q.b * w.y + q.c * w.z)
		+ v.y * (q.d * w.x + q.e * w.y + q.f * w.z)
		+ v.z * (q.g * w.x + q.h * w.y + q.i * w.z);
	return (res);
}
