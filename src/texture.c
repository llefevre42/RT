/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 15:34:43 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/21 16:18:34 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	text_form(t_tri *l)
{
	text_light_add(l);
	text_light_del(l);
	text_light_modif(l);
	text_flecheg(l);
	text_flecheb(l);
	text_render(l);
	text_home(l);
	text_mini_file(l);
	text_menu_file(l);
	text_menu_form(l);
	text_menu_shape(l);
	text_menu_cam(l);
	text_grey_button(l);
	text_white_button(l);
}

void	text_menu_form(t_tri *l)
{
	int	t1;
	int	t2;
	int	t3;

	if (!(l->pt_p_menu_form = mlx_xpm_file_to_image(l->frame->video.mlx,
			"texture/object_menu.xpm", &t2, &t3)))
		ft_error(1);
	l->p_menu_form = mlx_get_data_addr(l->pt_p_menu_form, &t1, &t2, &t3);
}

void	text_menu_cam(t_tri *l)
{
	int	t1;
	int	t2;
	int	t3;

	if (!(l->pt_p_menu_cam = mlx_xpm_file_to_image(l->frame->video.mlx,
			"texture/menu_cam.xpm", &t2, &t3)))
		ft_error(1);
	l->p_menu_cam = mlx_get_data_addr(l->pt_p_menu_cam, &t1, &t2, &t3);
}

void	text_white_button(t_tri *l)
{
	int	t1;
	int	t2;
	int	t3;

	if (!(l->pt_p_white_button = mlx_xpm_file_to_image(l->frame->video.mlx,
			"texture/white_button.xpm", &t2, &t3)))
		ft_error(1);
	l->p_white_button = mlx_get_data_addr(l->pt_p_white_button, &t1, &t2, &t3);
}

void	text_grey_button(t_tri *l)
{
	int	t1;
	int	t2;
	int	t3;

	if (!(l->pt_p_grey_button = mlx_xpm_file_to_image(l->frame->video.mlx,
			"texture/grey_button.xpm", &t2, &t3)))
		ft_error(1);
	l->p_grey_button = mlx_get_data_addr(l->pt_p_grey_button, &t1, &t2, &t3);
}
