/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gene_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:35:17 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/21 16:19:08 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_error(int i)
{
	i = 0;
	ft_putstr("error\n");
	exit(1);
}

void	main_menu(t_tri *lst)
{
	mlx_put_image_to_window(lst->mlx, lst->win, lst->pt_p_home, 0, 0);
}

void	init_lst(t_tri *lst, t_frame *frame, char **str)
{
	lst->sous_menu = 0;
	lst->add_form_who = 0;
	lst->l_add_form_who = 0;
	lst->input = 0;
	lst->true_split = 0;
	lst->current_split = 1;
	lst->split = 1;
	lst->true_dupli = 0;
	lst->current_dupli = 1;
	lst->dupli = 1;
	lst->augment = 0;
	lst->number_file = 0;
	lst->up = 0;
	lst->current_cam_w = 1;
	init_lst2(lst, frame, str);
}

void	init_lst2(t_tri *lst, t_frame *frame, char **str)
{
	t_frame	*preview;

	if (!(preview = (t_frame *)malloc(sizeof(t_frame))))
		ft_error(1);
	lst->mlx = MLX;
	lst->win = WIN;
	frame->lst = lst;
	lst->frame = frame;
	lst->preview = preview;
	lst->current_cam_o = CAM.orig;
	lst->current_cam_d = CAM.dir;
	lst->current_cam = CAM;
	lst->current_cam_w = 1;
	lst->current_str = str;
	lst->file_load = 0;
	lst->preview_in = 0;
	lst->page = 0;
}

int		start(t_frame *frame, char **str)
{
	t_tri	lst;
	int		larg;
	int		haut;

	init_lst(&lst, frame, str);
	count_liste(&lst);
	generation(&lst);
	init_val(&lst);
	bases(&lst);
	gene_preview(&lst);
	main_menu(&lst);
	haut = ((1000 - lst.frame->video.width) / 2);
	larg = ((1000 - lst.frame->video.height) / 2);
	expose_hook(frame);
	mlx_mouse_hook(lst.win, put_mousse, &lst);
	mlx_hook(lst.win, 2, 0L, my_key_funct1, frame);
	mlx_loop(lst.mlx);
	return (0);
}
