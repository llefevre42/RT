/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:58:25 by rpinault          #+#    #+#             */
/*   Updated: 2018/02/27 15:16:34 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec			ft_hex_to_rgb(int hex)
{
	t_vec		rgb;

	rgb.x = (double)(((hex >> 16) & 0xFF) / 255.0f);
	rgb.y = (double)(((hex >> 8) & 0xFF) / 255.0f);
	rgb.z = (double)(((hex) & 0xFF) / 255.0f);
	return (rgb);
}

int				ft_rgb_to_hex(t_vec rgb)
{
	int			r;
	int			g;
	int			b;

	r = (int)(rgb.x * 255.0f);
	g = (int)(rgb.y * 255.0f);
	b = (int)(rgb.z * 255.0f);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int				ft_int_rgb_to_hex(double r1, double g1, double b1)
{
	int			r;
	int			g;
	int			b;

	r = (int)(r1 * 255.0f);
	g = (int)(g1 * 255.0f);
	b = (int)(b1 * 255.0f);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
