/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:17:39 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/28 19:10:21 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	split_in_2(t_tri *lst)
{
	char	*(str[17]);

	ft_store_list(lst->frame);
	init_scene(lst->frame);
	init_variable(lst->frame);
	if (lst->file_load == 0)
		parsing_choice(lst->frame, lst->current_str);
	else
	{
		str[1] = ft_strjoin("./map/", ls(lst, lst->file_load));
		parsing_choice(lst->frame, str);
		free(str[1]);
	}
	init_textures(lst->frame);
	lst->WIDTH = 1000;
	lst->HEIGHT = 500;
	lst->IMG = mlx_new_image(lst->MLX, lst->WIDTH, lst->HEIGHT);
	lst->MAP = (int*)mlx_get_data_addr(lst->IMG, &lst->t1, &lst->t2, &lst->t3);
	mlx_put_image_to_window(lst->mlx, lst->win, lst->pt_p_render, 923, 0);
	lst->cam1 = lst->CAM;
	lst->cam2 = lst->CAM;
	lst->split = 0;
	expose_hook(lst->frame);
}

void	split_in_4(t_tri *lst)
{
	char	*(str[17]);

	ft_store_list(lst->frame);
	init_scene(lst->frame);
	init_variable(lst->frame);
	if (lst->file_load == 0)
		parsing_choice(lst->frame, lst->current_str);
	else
	{
		str[1] = ft_strjoin("./map/", ls(lst, lst->file_load));
		parsing_choice(lst->frame, str);
		free(str[1]);
	}
	init_textures(lst->frame);
	lst->WIDTH = 500;
	lst->HEIGHT = 500;
	lst->IMG = mlx_new_image(lst->MLX, lst->WIDTH, lst->HEIGHT);
	lst->MAP = (int*)mlx_get_data_addr(lst->IMG, &lst->t1, &lst->t2, &lst->t3);
	mlx_put_image_to_window(lst->mlx, lst->win, lst->pt_p_render, 923, 0);
	lst->cam1 = lst->CAM;
	lst->cam2 = lst->CAM;
	lst->cam3 = lst->CAM;
	lst->cam4 = lst->CAM;
	lst->split = 0;
	expose_hook(lst->frame);
}

void	split_in_1(t_tri *lst)
{
	char	*(str[17]);

	ft_store_list(lst->frame);
	init_scene(lst->frame);
	init_variable(lst->frame);
	if (lst->file_load == 0)
		parsing_choice(lst->frame, lst->current_str);
	else
	{
		str[1] = ft_strjoin("./map/", ls(lst, lst->file_load));
		parsing_choice(lst->frame, str);
		free(str[1]);
	}
	init_textures(lst->frame);
	lst->IMG = mlx_new_image(lst->MLX, lst->WIDTH, lst->HEIGHT);
	lst->MAP = (int*)mlx_get_data_addr(lst->IMG, \
		&lst->t1, &lst->t2, &lst->t3);
	mlx_put_image_to_window(lst->mlx, lst->win, lst->pt_p_render, 923, 0);
	expose_hook(lst->frame);
}
