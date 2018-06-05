/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_light2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:45:59 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/21 15:14:54 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	add_light_i(t_tri *l)
{
	mlx_put_image_to_window(l->mlx, l->win, l->pt_p_flecheg, 150, 200);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_p_fleched, 750, 200);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 150, 450);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 250, 450);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 350, 450);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 550, 450);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 650, 450);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 750, 450);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 350, 570);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 450, 570);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 550, 570);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 450, 950);
	add_light_i2(l);
}

void	add_light_i2(t_tri *l)
{
	mlx_string_put(l->mlx, l->win, 160, 465, 0, l->tab_pos_x);
	mlx_string_put(l->mlx, l->win, 260, 465, 0, l->tab_pos_y);
	mlx_string_put(l->mlx, l->win, 360, 465, 0, l->tab_pos_z);
	mlx_string_put(l->mlx, l->win, 560, 465, 0, l->tab_dir_x);
	mlx_string_put(l->mlx, l->win, 660, 465, 0, l->tab_dir_y);
	mlx_string_put(l->mlx, l->win, 760, 465, 0, l->tab_dir_z);
	mlx_string_put(l->mlx, l->win, 360, 585, 0, l->tab_color_r);
	mlx_string_put(l->mlx, l->win, 460, 585, 0, l->tab_color_g);
	mlx_string_put(l->mlx, l->win, 560, 585, 0, l->tab_color_b);
	mlx_string_put(l->mlx, l->win, 260, 390, 0XFFFFFF, "pos");
	mlx_string_put(l->mlx, l->win, 655, 390, 0XFFFFFF, "diff");
	mlx_string_put(l->mlx, l->win, 555, 390, 0XFFFFFF, "spec");
	mlx_string_put(l->mlx, l->win, 755, 390, 0XFFFFFF, "???");
	mlx_string_put(l->mlx, l->win, 450, 520, 0XFFFFFF, "color");
	mlx_string_put(l->mlx, l->win, 460, 970, 0XFFFFFF, "add");
}

void	del_light(t_tri *l)
{
	mlx_put_image_to_window(l->mlx, l->win, l->pt_p_flecheg, 150, 200);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_p_fleched, 750, 200);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 450, 950);
	mlx_string_put(l->mlx, l->win, 460, 970, 0XFFFFFF, "del");
}
