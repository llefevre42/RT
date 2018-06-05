/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_form2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:20:52 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/21 17:57:40 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	add_form(t_tri *l)
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
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 150, 710);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 250, 710);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 350, 710);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 450, 710);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 550, 710);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 650, 710);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 750, 710);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 450, 950);
	add_form2(l);
}

void	add_form2(t_tri *l)
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
	mlx_string_put(l->mlx, l->win, 160, 725, 0, l->tab_ray);
	mlx_string_put(l->mlx, l->win, 260, 725, 0, l->tab_transp);
	mlx_string_put(l->mlx, l->win, 360, 725, 0, l->tab_matiere);
	mlx_string_put(l->mlx, l->win, 460, 725, 0, l->tab_refra);
	mlx_string_put(l->mlx, l->win, 560, 725, 0, l->tab_rug);
	mlx_string_put(l->mlx, l->win, 660, 725, 0, l->tab_shine);
	mlx_string_put(l->mlx, l->win, 760, 725, 0, l->tab_reflec);
	add_form3(l);
}

void	add_form3(t_tri *l)
{
	mlx_string_put(l->mlx, l->win, 260, 390, 0XFFFFFF, "pos");
	mlx_string_put(l->mlx, l->win, 660, 390, 0XFFFFFF, "dir");
	mlx_string_put(l->mlx, l->win, 450, 520, 0XFFFFFF, "color");
	mlx_string_put(l->mlx, l->win, 160, 660, 0XFFFFFF, "ray");
	mlx_string_put(l->mlx, l->win, 250, 660, 0XFFFFFF, "transp");
	mlx_string_put(l->mlx, l->win, 350, 660, 0XFFFFFF, "matiere");
	mlx_string_put(l->mlx, l->win, 450, 660, 0XFFFFFF, "refra");
	mlx_string_put(l->mlx, l->win, 560, 660, 0XFFFFFF, "rug");
	mlx_string_put(l->mlx, l->win, 650, 660, 0XFFFFFF, "shine");
	mlx_string_put(l->mlx, l->win, 750, 660, 0XFFFFFF, "reflec");
	mlx_string_put(l->mlx, l->win, 460, 970, 0, "add");
	if (l->current_object == 3)
		mlx_string_put(l->mlx, l->win, 440, 400, 0XFFFFFF, "sphere");
	if (l->current_object == 0)
		mlx_string_put(l->mlx, l->win, 440, 400, 0XFFFFFF, "plan");
	if (l->current_object == 2)
		mlx_string_put(l->mlx, l->win, 440, 400, 0XFFFFFF, "cylinder");
	if (l->current_object == 1)
		mlx_string_put(l->mlx, l->win, 440, 400, 0XFFFFFF, "cone");
}

void	del_form(t_tri *l)
{
	mlx_put_image_to_window(l->mlx, l->win, l->pt_p_flecheg, 150, 200);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_p_fleched, 750, 200);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xs_white, 450, 950);
	mlx_string_put(l->mlx, l->win, 460, 970, 0XFFFFFF, "del");
	if (l->add_form_who == 0)
		mlx_string_put(l->mlx, l->win, 440, 350, 0XFFFFFF, "sphere");
	if (l->add_form_who == 1)
		mlx_string_put(l->mlx, l->win, 440, 350, 0XFFFFFF, "plan");
	if (l->add_form_who == 2)
		mlx_string_put(l->mlx, l->win, 440, 350, 0XFFFFFF, "cylinder");
	if (l->add_form_who == 3)
		mlx_string_put(l->mlx, l->win, 440, 350, 0XFFFFFF, "cone");
}
