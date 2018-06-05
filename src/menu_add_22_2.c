/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_add_22_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:08:19 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/15 22:41:19 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	clique_add_5(t_tri *lst, int x, int y)
{
	if ((x >= 450 && x <= 500) && (y >= 710 && y <= 760))
	{
		lst->input = 1;
		lst->current_tab = &lst->tab_refra;
		lst->max_u = 100;
	}
	else if ((x >= 550 && x <= 600) && (y >= 710 && y <= 760))
	{
		lst->input = 1;
		lst->current_tab = &lst->tab_rug;
		lst->max_u = 100;
	}
	else if ((x >= 650 && x <= 700) && (y >= 710 && y <= 760))
	{
		lst->input = 1;
		lst->current_tab = &lst->tab_shine;
		lst->max_u = 100;
	}
	else
		clique_add_6(lst, x, y);
}

void	clique_add_6(t_tri *lst, int x, int y)
{
	if ((x >= 750 && x <= 800) && (y >= 710 && y <= 760))
	{
		lst->input = 1;
		lst->current_tab = &lst->tab_reflec;
		lst->max_u = 100;
	}
	else if ((x >= 460 && x <= 510) && (y >= 950 && y <= 1000))
	{
		lst->preview_in = 0;
		if (lst->current_object == 3)
			add_sphere(&lst->OBJECT_B, 0);
		if (lst->current_object == 0)
			add_plan(&lst->OBJECT_B, 0);
		if (lst->current_object == 2)
			add_cylindre(&lst->OBJECT_B, 0);
		if (lst->current_object == 1)
			add_cone(&lst->OBJECT_B, 0);
		clique_add_7(lst);
		lst->input = 0;
	}
	else
		clique_add_8(lst, x, y);
}

void	clique_add_7(t_tri *lst)
{
	t_object *obj;

	obj = lst->frame->scene.object_begin;
	obj->orig.x = ft_atoi(lst->tab_pos_x);
	obj->orig.y = ft_atoi(lst->tab_pos_y);
	obj->orig.z = ft_atoi(lst->tab_pos_z);
	obj->data.x = ft_atoi(lst->tab_dir_x);
	obj->data.y = ft_atoi(lst->tab_dir_y);
	obj->data.z = ft_atoi(lst->tab_dir_z);
	obj->data = ft_normalize(obj->data);
	obj->color.x = (atof_custom(lst->tab_color_r) / 255.);
	obj->color.y = (atof_custom(lst->tab_color_g) / 255.);
	obj->color.z = (atof_custom(lst->tab_color_b) / 255.);
	if (obj->type == 3)
		obj->r = (atof_custom(lst->tab_ray) / 100.);
	else
		obj->r = ft_atoi(lst->tab_ray);
	obj->indice = (atof_custom(lst->tab_refra) / 100.);
	obj->matiere = ft_atoi(lst->tab_matiere);
	obj->transp = (atof_custom(lst->tab_transp));
	obj->ks = (atof_custom(lst->tab_shine) / 100.);
	obj->indice = (atof_custom(lst->tab_refra) / 100.);
	obj->reflec = (atof_custom(lst->tab_reflec) / 100.);
	obj->rug = (atof_custom(lst->tab_rug) / 100.);
	expose_hook(lst->frame);
}

void	clique_add_8(t_tri *lst, int x, int y)
{
	if ((x >= 150 && x <= 200) && (y >= 200 && y <= 250))
	{
		if (lst->current_object >= 3)
			lst->current_object = 0;
		else
			lst->current_object++;
		lst->input = 0;
		erase_menu(lst);
		add_form(lst);
	}
	else if ((x >= 750 && x <= 800) && (y >= 200 && y <= 250))
	{
		if (lst->current_object == 0)
			lst->current_object = 3;
		else
			lst->current_object--;
		lst->input = 0;
		erase_menu(lst);
		add_form(lst);
	}
	else
		lst->input = 0;
	preview_add(lst);
	expose_hook(lst->frame);
	lst->preview_in = 0;
}
