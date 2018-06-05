/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 06:47:44 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/11 01:47:45 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	menu_split(t_tri *l)
{
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_s_white, 450, 400);
	mlx_string_put(l->mlx, l->win, 480, 430, 0X000000, "split");
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_s_white, 450, 600);
	mlx_string_put(l->mlx, l->win, 480, 630, 0X000000, "stop");
}
