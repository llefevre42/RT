/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mousse_light2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:25:48 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/16 23:21:06 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	event_light_42(t_tri *lst, int x, int y)
{
	if ((x >= 50 && x <= 100) && (y >= 150 && y <= 200))
	{
		erase_menu(lst);
		lst->sous_menu = 40;
		menu_light(lst);
	}
	if ((x >= 150 && x <= 200) && (y >= 200 && y <= 250))
	{
		erase_menu(lst);
		add_light_i(lst);
	}
	if ((x >= 750 && x <= 800) && (y >= 200 && y <= 250))
	{
		erase_menu(lst);
		add_light_i(lst);
	}
}

void	event_light_43(t_tri *lst, int x, int y)
{
	if ((x >= 50 && x <= 100) && (y >= 150 && y <= 200))
	{
		erase_menu(lst);
		lst->sous_menu = 40;
		menu_light(lst);
	}
	if ((x >= 150 && x <= 200) && (y >= 200 && y <= 250))
	{
		erase_menu(lst);
		del_light(lst);
	}
	if ((x >= 750 && x <= 800) && (y >= 200 && y <= 250))
	{
		erase_menu(lst);
		del_light(lst);
	}
}
