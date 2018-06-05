/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 05:18:21 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/21 21:51:06 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	menu_light(t_tri *l)
{
	mlx_put_image_to_window(l->mlx, l->win, l->pt_p_light_modif, 375, 300);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_p_light_add, 125, 550);
	mlx_string_put(l->mlx, l->win, 450, 480, 0XFFFFFF, "Modif");
	mlx_string_put(l->mlx, l->win, 200, 730, 0XFFFFFF, "Add");
}

void	modif_light(t_tri *l)
{
	t_light *obj;

	if (!(obj = l_current_obj(l)))
		return ;
	reset_all(l);
	add_light_i(l);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xxs_black, 165, 420);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xxs_black, 265, 420);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xxs_black, 365, 420);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xxs_black, 565, 420);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xxs_black, 665, 420);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xxs_black, 765, 420);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xxs_black, 165, 510);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xxs_black, 265, 510);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xxs_black, 365, 510);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xxs_black, 565, 510);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xxs_black, 665, 510);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xxs_black, 765, 510);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xxs_black, 365, 540);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xxs_black, 465, 540);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xxs_black, 565, 540);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xxs_black, 365, 630);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xxs_black, 465, 630);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_cube_xxs_black, 565, 630);
	modif_light2(l, obj);
}

void	modif_light2(t_tri *l, t_light *obj)
{
	free(str_itoa_b(l, 160, 465, obj->orig.x));
	free(str_itoa_b(l, 260, 465, obj->orig.y));
	free(str_itoa_b(l, 360, 465, obj->orig.z));
	free(str_itoa_b(l, 560, 465, obj->i.x * 100));
	free(str_itoa_b(l, 660, 465, obj->i.y * 100));
	free(str_itoa_b(l, 760, 465, obj->i.z * 100));
	free(str_itoa_b(l, 360, 585, obj->color.x * 255));
	free(str_itoa_b(l, 460, 585, obj->color.y * 255));
	free(str_itoa_b(l, 560, 585, obj->color.z * 255));
}
