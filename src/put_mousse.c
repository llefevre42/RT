/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mousse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 22:18:06 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/25 15:57:39 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		put_mousse(int keycode, int x, int y, void *param)
{
	t_tri	*l;

	l = ((t_tri *)param);
	l->key = keycode;
	if ((x >= 950 && x <= 1950) && (y >= 149 && y <= 649) \
			&& l->current_split == 1)
	{
		l->current_cam = l->cam1;
		l->current_cam_w = 1;
	}
	if ((x >= 950 && x <= 1950) && (y >= 649 && y <= 1149) \
			&& l->true_split == 1)
	{
		l->current_cam = l->cam2;
		l->current_cam_w = 2;
	}
	if ((x >= 950 && x <= 1450) && (y >= 149 && y <= 649) \
			&& l->true_split == 2)
	{
		l->current_cam = l->cam1;
		l->current_cam_w = 1;
	}
	put_mousse2(keycode, x, y, l);
	return (0);
}

void	put_mousse2(int keycode, int x, int y, t_tri *l)
{
	if ((x >= 950 && x <= 1450) && (y >= 649 && y <= 1149) \
			&& l->true_split == 2)
	{
		l->current_cam = l->cam3;
		l->current_cam_w = 3;
	}
	if ((x >= 1450 && x <= 1950) && (y >= 149 && y <= 649) \
			&& l->true_split == 2)
	{
		l->current_cam = l->cam2;
		l->current_cam_w = 2;
	}
	if ((x >= 1450 && x <= 1950) && (y >= 649 && y <= 1149) \
			&& l->true_split == 2)
	{
		l->current_cam = l->cam4;
		l->current_cam_w = 4;
	}
	put_mousse_menu(keycode, x, y, l);
}

void	put_mousse_menu(int keycode, int x, int y, t_tri *l)
{
	if (l->sous_menu == 0)
		put_mousse_0(keycode, x, y, l);
	else if (l->sous_menu == 11)
		put_mousse_11(keycode, x, y, l);
	else if (l->sous_menu == 10)
		clique_on_file(l, x, y);
	else if (l->sous_menu >= 40 && l->sous_menu <= 49)
		put_mousse_40(keycode, x, y, l);
	else if (l->sous_menu >= 20 && l->sous_menu <= 29)
		put_mousse_20(keycode, x, y, l);
	else if (l->sous_menu >= 30 && l->sous_menu <= 39)
		clique_cam(l, x, y);
}

void	put_mousse_0(int keycode, int x, int y, t_tri *l)
{
	if ((x >= 150 && x <= 350) && (y >= 300 && y <= 500))
	{
		l->sous_menu = 10;
		erase_menu(l);
		menu_file(l);
	}
	if ((x >= 600 && x <= 800) && (y >= 300 && y <= 500))
	{
		l->sous_menu = 20;
		erase_menu(l);
		menu_form(l);
	}
	if ((x >= 150 && x <= 350) && (y >= 700 && y <= 900))
	{
		l->sous_menu = 30;
		erase_menu(l);
		menu_cam(l);
	}
	put_mousse_0_2(keycode, x, y, l);
}

void	put_mousse_20(int keycode, int x, int y, t_tri *l)
{
	event_form(l, x, y);
	if (l->sous_menu == 22)
		clique_add(l, x, y);
	if (l->sous_menu == 21)
		clique_modif(l, x, y);
	keycode = 0;
}
