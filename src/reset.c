/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:45:17 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/21 16:23:42 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	gene_preview(t_tri *lst)
{
	char *(str[20]);

	init_scene(lst->preview);
	init_variable(lst->preview);
	str[1] = "./preview/preview.txt";
	parsing_choice(lst->preview, str);
	init_textures(lst->frame);
	lst->preview->video.mlx = lst->MLX;
	lst->preview->video.win = lst->WIN;
	lst->preview->video.width = 200;
	lst->preview->video.height = 200;
	lst->preview->video.img = mlx_new_image(lst->preview->video.mlx,\
			lst->preview->video.width, lst->preview->video.height);
	lst->preview->video.map = (int*)mlx_get_data_addr(lst->preview->video.img,\
			&lst->t1, &lst->t2, &lst->t3);
	mlx_put_image_to_window(lst->mlx, lst->win, lst->pt_p_render, 923, 0);
}

void	generation(t_tri *lst)
{
	lst->pt_img = mlx_new_image(lst->mlx, 2000, 1300);
	lst->img = (unsigned int *)mlx_get_data_addr(lst->pt_img,\
			&lst->t1, &lst->t2, &lst->t3);
}

void	erase_menu(t_tri *lst)
{
	mlx_put_image_to_window(lst->mlx, lst->win, lst->pt_p_menu_file, 0, 0);
}

void	init_val(t_tri *lst)
{
	lst->tab_pos_x = ft_strdup("   ");
	lst->tab_pos_y = ft_strdup("   ");
	lst->tab_pos_z = ft_strdup("   ");
	lst->tab_dir_x = ft_strdup("   ");
	lst->tab_dir_y = ft_strdup("   ");
	lst->tab_dir_z = ft_strdup("   ");
	lst->tab_color_r = ft_strdup("   ");
	lst->tab_color_g = ft_strdup("   ");
	lst->tab_color_b = ft_strdup("   ");
	lst->tab_ray = ft_strdup("   ");
	lst->tab_transp = ft_strdup("   ");
	lst->tab_refra = ft_strdup("   ");
	lst->tab_diff = ft_strdup("   ");
	lst->tab_shine = ft_strdup("   ");
	lst->tab_reflec = ft_strdup("   ");
	lst->tab_matiere = ft_strdup("   ");
	lst->tab_rug = ft_strdup("   ");
	lst->tab_limite = ft_strdup("   ");
}

void	bases(t_tri *lst)
{
	lst->pt_inter_g = mlx_new_image(lst->mlx, 2000, 1300);
	lst->inter_g = (unsigned int *)mlx_get_data_addr(lst->pt_inter_g,\
			&lst->t1, &lst->t2, &lst->t3);
	lst->pt_block_xl_red = mlx_new_image(lst->mlx, 850, 1000);
	lst->block_xl_red = (unsigned int *)mlx_get_data_addr(lst->pt_block_xl_red,\
			&lst->t1, &lst->t2, &lst->t3);
	lst->pt_back = mlx_new_image(lst->mlx, 50, 50);
	lst->back = (unsigned int *)mlx_get_data_addr(lst->pt_back,\
			&lst->t1, &lst->t2, &lst->t3);
	lst->pt_cube_xs_purple = mlx_new_image(lst->mlx, 50, 50);
	lst->cube_xs_purple = (unsigned int *)mlx_get_data_addr(\
			lst->pt_cube_xs_purple, &lst->t1, &lst->t2, &lst->t3);
	lst->pt_cube_xs_white = mlx_new_image(lst->mlx, 50, 50);
	lst->cube_xs_white = (unsigned int *)mlx_get_data_addr(\
			lst->pt_cube_xs_white, &lst->t1, &lst->t2, &lst->t3);
	lst->pt_cube_xxs_black = mlx_new_image(lst->mlx, 20, 20);
	lst->cube_xxs_black = (unsigned int *)mlx_get_data_addr(\
			lst->pt_cube_xxs_black, &lst->t1, &lst->t2, &lst->t3);
	lst->pt_cube_s_white = mlx_new_image(lst->mlx, 100, 100);
	lst->cube_s_white = (unsigned int *)mlx_get_data_addr(lst->pt_cube_s_white,\
			&lst->t1, &lst->t2, &lst->t3);
	lst->pt_cube_xs_grey = mlx_new_image(lst->mlx, 50, 50);
	lst->cube_xs_grey = (unsigned int *)mlx_get_data_addr(lst->pt_cube_xs_grey,\
			&lst->t1, &lst->t2, &lst->t3);
	load_block(lst);
}
