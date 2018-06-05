/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mousse2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:21:13 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/28 16:57:58 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	put_mousse_0_2(int keycode, int x, int y, t_tri *l)
{
	keycode = 0;
	if ((x >= 600 && x <= 800) && (y >= 700 && y <= 900))
	{
		l->sous_menu = 40;
		erase_menu(l);
		menu_light(l);
	}
	if ((x >= 50 && x <= 100) && (y >= 150 && y <= 200))
		exit(0);
	if ((x >= 850 && x <= 900) && (y >= 150 && y <= 200))
		screenshoot((unsigned int *)(l->MAP), l);
}

void	put_mousse_11(int keycode, int x, int y, t_tri *l)
{
	if ((x >= 50 && x <= 100) && (y >= 150 && y <= 200))
	{
		l->sous_menu = 10;
		erase_menu(l);
		menu_file(l);
	}
	if ((x >= 100 && x <= 200) && (y >= 0 && y <= 100))
		l->augment += 100;
	if ((x >= 0 && x <= 100) && (y >= 0 && y <= 100))
		l->augment -= 100;
	put_mousse_11_2(keycode, x, y, l);
	put_mousse_11_3(keycode, x, y, l);
}

void	put_mousse_11_2(int keycode, int x, int y, t_tri *l)
{
	char	*(str[20]);
	int		fd;

	if ((x >= 650 && x <= 750) && (y >= 800 && y <= 900))
	{
		l->current_cam_w = 0;
		l->true_split = 0;
		l->split = 0;
		l->sous_menu = 11;
		l->w_swap = l->WIDTH;
		l->h_swap = l->HEIGHT;
		str[1] = ft_strjoin("./map/", ls(l, l->file_load));
		fd = open(str[1], O_RDONLY);
		parsing_txt(l->frame, fd);
		free(str[1]);
		l->WIDTH = l->w_swap;
		l->HEIGHT = l->h_swap;
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_render, 923, 0);
		expose_hook(l->frame);
	}
	keycode = 0;
	fd = 0;
}

void	put_mousse_11_3(int keycode, int x, int y, t_tri *l)
{
	char	*(str[20]);

	if ((x >= 200 && x <= 300) && (y >= 800 && y <= 900))
	{
		l->current_cam_w = 0;
		l->true_split = 0;
		l->split = 0;
		split_in_1(l);
		l->sous_menu = 11;
		ft_store_list(l->frame);
		init_scene(l->frame);
		init_variable(l->frame);
		str[1] = ft_strjoin("./map/", ls(l, l->file_load));
		parsing_choice(l->frame, str);
		free(str[1]);
		init_textures(l->frame);
		l->current_cam = l->CAM;
		l->IMG = mlx_new_image(l->MLX, l->WIDTH, l->HEIGHT);
		l->MAP = (int*)mlx_get_data_addr(l->IMG, &l->t1, &l->t2, &l->t3);
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_render, 923, 0);
		expose_hook(l->frame);
	}
	keycode = 0;
}

void	put_mousse_40(int keycode, int x, int y, t_tri *l)
{
	event_light(l, x, y);
	if (l->sous_menu == 42)
		clique_add_light(l, x, y);
	if (l->sous_menu == 41)
		clique_modif_light(l, x, y);
	keycode = 0;
}
