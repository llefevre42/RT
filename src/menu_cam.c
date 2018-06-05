/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:28:17 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/21 18:40:48 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	menu_cam(t_tri *l)
{
	mlx_string_put(l->mlx, l->win, 425, 170, 0X000000, "Menu Camera");
	mlx_put_image_to_window(l->mlx, l->win, l->pt_p_menu_cam, 0, 0);
	free(str_itoa_b(l, 470, 975, l->SCENE.lum_amb * 10));
	if (l->frame->scene.px == 0)
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_white_button, 530, 950);
	else
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_grey_button, 530, 950);
	if (l->frame->scene.aa == 0)
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_white_button, 582, 950);
	else
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_grey_button, 582, 950);
	mlx_string_put(l->mlx, l->win, 540, 965, 0, "P.X");
	mlx_string_put(l->mlx, l->win, 590, 965, 0, "A.A");
	if (l->frame->scene.sepia == 0)
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_white_button, 650, 950);
	else
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_grey_button, 650, 950);
	menu_cam2(l);
}

void	menu_cam2(t_tri *l)
{
	mlx_put_image_to_window(l->mlx, l->win, l->pt_p_white_button, 752, 950);
	if (l->frame->scene.bw == 0)
		mlx_put_image_to_window(l->mlx, l->win, \
				l->pt_p_white_button, 701, 1001);
	else
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_grey_button, 701, 1001);
	if (l->frame->scene.cartoon == 0)
		mlx_put_image_to_window(l->mlx, l->win, \
				l->pt_p_white_button, 650, 1001);
	else
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_grey_button, 650, 1001);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_p_white_button, 701, 950);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_p_white_button, 752, 1001);
	mlx_string_put(l->mlx, l->win, 655, 960, 0X000000, "Sepia");
	mlx_string_put(l->mlx, l->win, 660, 1011, 0X000000, "Cart");
	mlx_string_put(l->mlx, l->win, 711, 1011, 0X000000, "B/W");
	mlx_string_put(l->mlx, l->win, 755, 1011, 0X000000, "Reset");
}
