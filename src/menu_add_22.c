/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_add_22.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:53:45 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/21 19:11:05 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	clique_add(t_tri *lst, int x, int y)
{
	lst->preview_in = 1;
	if ((x >= 150 && x <= 200) && (y >= 450 && y <= 500))
	{
		lst->input = 1;
		lst->current_tab = &lst->tab_pos_x;
		lst->max_u = 999;
	}
	else if ((x >= 250 && x <= 300) && (y >= 450 && y <= 500))
	{
		lst->input = 1;
		lst->current_tab = &lst->tab_pos_y;
		lst->max_u = 999;
	}
	else if ((x >= 350 && x <= 400) && (y >= 450 && y <= 500))
	{
		lst->input = 1;
		lst->current_tab = &lst->tab_pos_z;
		lst->max_u = 999;
	}
	else
		clique_add_2(lst, x, y);
}

void	clique_add_2(t_tri *lst, int x, int y)
{
	if ((x >= 550 && x <= 600) && (y >= 450 && y <= 500))
	{
		lst->input = 1;
		lst->current_tab = &lst->tab_dir_x;
		lst->max_u = 999;
	}
	else if ((x >= 650 && x <= 700) && (y >= 450 && y <= 500))
	{
		lst->input = 1;
		lst->current_tab = &lst->tab_dir_y;
		lst->max_u = 999;
	}
	else if ((x >= 750 && x <= 800) && (y >= 450 && y <= 500))
	{
		lst->input = 1;
		lst->current_tab = &lst->tab_dir_z;
		lst->max_u = 999;
	}
	else
		clique_add_3(lst, x, y);
}

void	clique_add_3(t_tri *lst, int x, int y)
{
	if ((x >= 350 && x <= 400) && (y >= 570 && y <= 620))
	{
		lst->input = 1;
		lst->current_tab = &lst->tab_color_r;
		lst->max_u = 255;
	}
	else if ((x >= 450 && x <= 500) && (y >= 570 && y <= 620))
	{
		lst->input = 1;
		lst->current_tab = &lst->tab_color_g;
		lst->max_u = 255;
	}
	else if ((x >= 550 && x <= 600) && (y >= 570 && y <= 620))
	{
		lst->input = 1;
		lst->current_tab = &lst->tab_color_b;
		lst->max_u = 255;
	}
	else
		clique_add_4(lst, x, y);
}

void	clique_add_4(t_tri *lst, int x, int y)
{
	if ((x >= 150 && x <= 200) && (y >= 710 && y <= 760))
	{
		lst->input = 1;
		lst->current_tab = &lst->tab_ray;
		lst->max_u = 999;
	}
	else if ((x >= 250 && x <= 300) && (y >= 710 && y <= 760))
	{
		lst->input = 1;
		lst->current_tab = &lst->tab_transp;
		lst->max_u = 100;
	}
	else if ((x >= 350 && x <= 400) && (y >= 710 && y <= 760))
	{
		lst->input = 1;
		lst->current_tab = &lst->tab_matiere;
		lst->max_u = 100;
	}
	else
		clique_add_5(lst, x, y);
}
