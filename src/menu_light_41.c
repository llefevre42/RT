/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_light_41.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 18:28:34 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/15 22:43:27 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	clique_add_light(t_tri *lst, int x, int y)
{
	if ((x >= 150 && x <= 200) && (y >= 450 && y <= 500))
	{
		lst->input = 2;
		lst->current_tab = &lst->tab_pos_x;
		lst->max_u = 999;
	}
	else if ((x >= 250 && x <= 300) && (y >= 450 && y <= 500))
	{
		lst->input = 2;
		lst->current_tab = &lst->tab_pos_y;
		lst->max_u = 999;
	}
	else if ((x >= 350 && x <= 400) && (y >= 450 && y <= 500))
	{
		lst->input = 2;
		lst->current_tab = &lst->tab_pos_z;
		lst->max_u = 999;
	}
	else
		clique_add_light2(lst, x, y);
}

void	clique_add_light2(t_tri *lst, int x, int y)
{
	if ((x >= 550 && x <= 600) && (y >= 450 && y <= 500))
	{
		lst->input = 2;
		lst->current_tab = &lst->tab_dir_x;
		lst->max_u = 999;
	}
	else if ((x >= 650 && x <= 700) && (y >= 450 && y <= 500))
	{
		lst->input = 2;
		lst->current_tab = &lst->tab_dir_y;
		lst->max_u = 999;
	}
	else if ((x >= 750 && x <= 800) && (y >= 450 && y <= 500))
	{
		lst->input = 2;
		lst->current_tab = &lst->tab_dir_z;
		lst->max_u = 999;
	}
	else
		clique_add_light3(lst, x, y);
}

void	clique_add_light3(t_tri *lst, int x, int y)
{
	if ((x >= 350 && x <= 400) && (y >= 570 && y <= 620))
	{
		lst->input = 2;
		lst->current_tab = &lst->tab_color_r;
		lst->max_u = 255;
	}
	else if ((x >= 450 && x <= 500) && (y >= 570 && y <= 620))
	{
		lst->input = 2;
		lst->current_tab = &lst->tab_color_g;
		lst->max_u = 255;
	}
	else if ((x >= 550 && x <= 600) && (y >= 570 && y <= 620))
	{
		lst->input = 2;
		lst->current_tab = &lst->tab_color_b;
		lst->max_u = 255;
	}
	else
		clique_add_light4(lst, x, y);
}

void	clique_add_light4(t_tri *lst, int x, int y)
{
	t_light *obj;

	if ((x >= 460 && x <= 510) && (y >= 970 && y <= 1020))
	{
		add_light(lst->frame);
		obj = lst->frame->scene.light_begin;
		obj->orig.x = ft_atoi(lst->tab_pos_x);
		obj->orig.y = ft_atoi(lst->tab_pos_y);
		obj->orig.z = ft_atoi(lst->tab_pos_z);
		obj->i.x = (atof_custom(lst->tab_dir_x) / 100.);
		obj->i.y = (atof_custom(lst->tab_dir_y) / 100.);
		obj->i.z = (atof_custom(lst->tab_dir_z) / 100.);
		obj->color.x = (atof_custom(lst->tab_color_r) / 255.);
		obj->color.y = (atof_custom(lst->tab_color_g) / 255.);
		obj->color.z = (atof_custom(lst->tab_color_b) / 255.);
		limitation(obj);
		expose_hook(lst->frame);
		lst->input = 0;
	}
	else
		lst->input = 0;
}

void	limitation(t_light *obj)
{
	if (obj->i.x > 1)
		obj->i.x = 1;
	if (obj->i.x < 0)
		obj->i.x = 0;
	if (obj->i.y > 1)
		obj->i.y = 1;
	if (obj->i.y < 0)
		obj->i.y = 0;
	if (obj->i.z > 1)
		obj->i.z = 1;
	if (obj->i.z < 0)
		obj->i.z = 0;
	if (obj->color.x > 1)
		obj->color.x = 1;
	if (obj->color.x < 0)
		obj->color.x = 0;
	if (obj->color.y > 1)
		obj->color.y = 1;
	if (obj->color.y < 0)
		obj->color.y = 0;
	if (obj->color.z > 1)
		obj->color.z = 1;
	if (obj->color.z < 0)
		obj->color.z = 0;
}
