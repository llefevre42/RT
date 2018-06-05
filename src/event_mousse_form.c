/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mousse_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:23:50 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/16 16:28:31 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	event_form(t_tri *lst, int x, int y)
{
	if (lst->sous_menu == 20)
		event_form_20(lst, x, y);
	if (lst->sous_menu == 21)
		event_form_21(lst, x, y);
	if (lst->sous_menu == 22)
		event_form_22(lst, x, y);
	if (lst->sous_menu == 23)
		event_form_23(lst, x, y);
	if (lst->sous_menu == 24)
		event_form_24(lst, x, y);
}

void	event_form_20(t_tri *lst, int x, int y)
{
	if ((x >= 50 && x <= 100) && (y >= 150 && y <= 200))
	{
		lst->sous_menu = 0;
		erase_menu(lst);
		main_menu(lst);
	}
	if ((x >= 375 && x <= 575) && (y >= 300 && y <= 500))
	{
		erase_menu(lst);
		lst->sous_menu = 21;
		lst->current_object = -1;
		modif_form(lst);
	}
	if ((x >= 125 && x <= 325) && (y >= 550 && y <= 750))
	{
		erase_menu(lst);
		lst->sous_menu = 22;
		lst->current_object = 0;
		add_form(lst);
	}
	event_form_20_2(lst, x, y);
}

void	event_form_20_2(t_tri *lst, int x, int y)
{
	if ((x >= 625 && x <= 825) && (y >= 550 && y <= 750))
	{
		erase_menu(lst);
		lst->sous_menu = 23;
		del_form(lst);
	}
	if ((x >= 375 && x <= 575) && (y >= 800 && y <= 1000))
	{
		erase_menu(lst);
		lst->sous_menu = 24;
		menu_split(lst);
	}
}

void	event_form_21(t_tri *lst, int x, int y)
{
	if ((x >= 50 && x <= 100) && (y >= 150 && y <= 200))
	{
		erase_menu(lst);
		lst->sous_menu = 20;
		menu_form(lst);
	}
	if ((x >= 150 && x <= 200) && (y >= 200 && y <= 250))
	{
		if (lst->modif_form_who > 0)
			lst->modif_form_who -= 1;
		else
			lst->modif_form_who = lst->count_liste - 1;
		erase_menu(lst);
		modif_form(lst);
	}
	if ((x >= 750 && x <= 800) && (y >= 200 && y <= 250))
	{
		count_liste(lst);
		if (lst->modif_form_who < lst->count_liste - 1)
			lst->modif_form_who += 1;
		else
			lst->modif_form_who = 0;
		erase_menu(lst);
		modif_form(lst);
	}
}

void	event_form_22(t_tri *lst, int x, int y)
{
	if ((x >= 50 && x <= 100) && (y >= 150 && y <= 200))
	{
		erase_menu(lst);
		lst->sous_menu = 20;
		menu_form(lst);
	}
	if ((x >= 150 && x <= 200) && (y >= 200 && y <= 250))
	{
		if (lst->add_form_who > 0)
			lst->add_form_who -= 1;
		else
			lst->add_form_who = 3;
		erase_menu(lst);
		add_form(lst);
	}
	if ((x >= 750 && x <= 800) && (y >= 200 && y <= 250))
	{
		if (lst->add_form_who < 3)
			lst->add_form_who += 1;
		else
			lst->add_form_who = 0;
		erase_menu(lst);
		add_form(lst);
	}
}
