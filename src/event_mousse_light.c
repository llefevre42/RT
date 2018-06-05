/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mousse_form.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:14:25 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/15 16:11:17 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	event_light(t_tri *lst, int x, int y)
{
	if (lst->sous_menu == 40)
		event_light_40(lst, x, y);
	else if (lst->sous_menu == 41)
		event_light_41(lst, x, y);
	else if (lst->sous_menu == 42)
		event_light_42(lst, x, y);
	else if (lst->sous_menu == 43)
		event_light_43(lst, x, y);
}

void	event_light_40(t_tri *lst, int x, int y)
{
	if ((x >= 50 && x <= 100) && (y >= 150 && y <= 200))
	{
		erase_menu(lst);
		lst->sous_menu = 0;
		main_menu(lst);
	}
	if ((x >= 375 && x <= 575) && (y >= 300 && y <= 500))
	{
		erase_menu(lst);
		lst->sous_menu = 41;
		modif_light(lst);
	}
	if ((x >= 125 && x <= 325) && (y >= 550 && y <= 750))
	{
		erase_menu(lst);
		lst->sous_menu = 42;
		add_light_i(lst);
	}
	if ((x >= 625 && x <= 825) && (y >= 550 && y <= 750))
	{
		erase_menu(lst);
		lst->sous_menu = 43;
		del_light(lst);
	}
}

void	event_light_41(t_tri *lst, int x, int y)
{
	if ((x >= 50 && x <= 100) && (y >= 150 && y <= 200))
	{
		erase_menu(lst);
		lst->sous_menu = 40;
		menu_light(lst);
	}
	if ((x >= 150 && x <= 200) && (y >= 200 && y <= 250))
	{
		if (lst->l_add_form_who > 0)
			lst->l_add_form_who -= 1;
		else
			lst->l_add_form_who = lst->l_count_liste - 1;
		l_current_obj(lst);
		erase_menu(lst);
		modif_light(lst);
	}
	event_light_41_2(lst, x, y);
}

void	event_light_41_2(t_tri *lst, int x, int y)
{
	if ((x >= 750 && x <= 800) && (y >= 200 && y <= 250))
	{
		l_count_liste(lst);
		if (lst->l_add_form_who < lst->l_count_liste - 1)
			lst->l_add_form_who += 1;
		else
			lst->l_add_form_who = 0;
		l_current_obj(lst);
		erase_menu(lst);
		modif_light(lst);
	}
}
