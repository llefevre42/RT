/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:29:43 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/21 15:48:31 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	text_home(t_tri *l)
{
	int	t1;
	int	t2;
	int	t3;

	if (!(l->pt_p_home = mlx_xpm_file_to_image(l->frame->video.mlx,
			"texture/home.xpm", &t2, &t3)))
		ft_error(1);
	l->p_home = mlx_get_data_addr(l->pt_p_home, &t1, &t2, &t3);
}

void	text_render(t_tri *l)
{
	int	t1;
	int	t2;
	int	t3;

	if (!(l->pt_p_render = mlx_xpm_file_to_image(l->frame->video.mlx,
			"texture/render.xpm", &t2, &t3)))
		ft_error(1);
	l->p_render = mlx_get_data_addr(l->pt_p_render, &t1, &t2, &t3);
}

void	text_mini_file(t_tri *l)
{
	int	t1;
	int	t2;
	int	t3;

	if (!(l->pt_p_mini_file = mlx_xpm_file_to_image(l->frame->video.mlx,
			"texture/mini_file.xpm", &t2, &t3)))
		ft_error(1);
	l->p_mini_file = mlx_get_data_addr(l->pt_p_mini_file, &t1, &t2, &t3);
}

void	text_menu_file(t_tri *l)
{
	int	t1;
	int	t2;
	int	t3;

	if (!(l->pt_p_menu_file = mlx_xpm_file_to_image(l->frame->video.mlx,
			"texture/file_interface.xpm", &t2, &t3)))
		ft_error(1);
	l->p_menu_file = mlx_get_data_addr(l->pt_p_menu_file, &t1, &t2, &t3);
}

void	text_menu_shape(t_tri *l)
{
	int	t1;
	int	t2;
	int	t3;

	if (!(l->pt_p_menu_shape = mlx_xpm_file_to_image(l->frame->video.mlx,
			"texture/shape_modif.xpm", &t2, &t3)))
		ft_error(1);
	l->p_menu_shape = mlx_get_data_addr(l->pt_p_menu_shape, &t1, &t2, &t3);
}
