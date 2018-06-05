/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mousse_form2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:14:00 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/11 01:47:45 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	event_form_23(t_tri *lst, int x, int y)
{
	if ((x >= 50 && x <= 100) && (y >= 150 && y <= 200))
	{
		erase_menu(lst);
		lst->sous_menu = 20;
		menu_form(lst);
	}
	if ((x >= 150 && x <= 200) && (y >= 200 && y <= 250))
	{
		erase_menu(lst);
		del_form(lst);
	}
	if ((x >= 750 && x <= 800) && (y >= 200 && y <= 250))
	{
		erase_menu(lst);
		del_form(lst);
	}
}

void	event_form_24(t_tri *lst, int x, int y)
{
	if ((x >= 50 && x <= 100) && (y >= 150 && y <= 200))
	{
		lst->sous_menu = 20;
		erase_menu(lst);
		menu_form(lst);
	}
	if ((x >= 450 && x <= 550) && (y >= 400 && y <= 500))
	{
		if (lst->true_split == 0)
		{
			lst->true_split += 1;
			split_in_2(lst);
		}
		else if (lst->true_split == 1)
		{
			lst->true_split += 1;
			split_in_4(lst);
		}
	}
	event_form_24_2(lst, x, y);
}

void	event_form_24_2(t_tri *lst, int x, int y)
{
	if ((x >= 450 && x <= 550) && (y >= 600 && y <= 700))
	{
		lst->true_split = 0;
		lst->split = 0;
		split_in_1(lst);
		lst->current_cam_w = 1;
	}
}
