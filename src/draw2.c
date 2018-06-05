/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:01:18 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/16 19:33:48 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		pixel_to_map(t_frame *frame, int i, int j, int hex)
{
	int		k;

	k = j * WIDTH + i;
	if (i >= 0 && i < WIDTH && j >= 0 && j < HEIGHT)
		MAP[k] = hex;
	return ;
}

void		map_clear(t_frame *frame)
{
	int		i;

	i = 0;
	while (i++ <= WIDTH * HEIGHT - 1)
		MAP[i] = 0;
}
