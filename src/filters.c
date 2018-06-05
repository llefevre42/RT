/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:51:57 by yhemme            #+#    #+#             */
/*   Updated: 2018/05/01 15:46:51 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	reset_filters(t_frame *frame)
{
	frame->scene.bw = 0;
	frame->scene.sepia = 0;
	frame->scene.cartoon = 0;
}

t_vec	bw(t_vec col)
{
	double	mix;

	mix = (col.x + col.y + col.z) / 3;
	col.x = mix;
	col.z = mix;
	col.y = mix;
	return (col);
}

t_vec	sepia(t_vec col)
{
	t_vec	color;

	color.x = col.x * .393 + col.y * .769 + col.z * .189;
	color.y = col.x * .349 + col.y * .686 + col.z * .168;
	color.z = col.x * .272 + col.y * .534 + col.z * .131;
	color.x = color.x > 1.0 ? 1.0 : color.x;
	color.y = color.y > 1.0 ? 1.0 : color.y;
	color.z = color.z > 1.0 ? 1.0 : color.z;
	return (color);
}

double	cartoon(double x)
{
	int a;

	a = x * 255;
	a = (a > 0 && a <= 50 ? 25 : a);
	a = (a > 50 && a <= 100 ? 75 : a);
	a = (a > 100 && a <= 200 ? 150 : a);
	a = (a > 200 && a <= 240 ? 225 : a);
	a = (a > 240 || a >= 255 ? 255 : a);
	x = a / 255.0f;
	return (x);
}

t_vec	apply_filter(t_frame *frame, t_vec col)
{
	if (frame->scene.bw)
		col = bw(col);
	if (frame->scene.sepia)
		col = sepia(col);
	if (frame->scene.cartoon)
	{
		col.x = cartoon(col.x);
		col.y = cartoon(col.y);
		col.z = cartoon(col.z);
	}
	return (col);
}
