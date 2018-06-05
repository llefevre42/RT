/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_modif_30.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:10:46 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/11 01:47:45 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	clique_cam(t_tri *lst, int x, int y)
{
	if ((x >= 50 && x <= 100) && (y >= 150 && y <= 200))
	{
		lst->sous_menu = 0;
		erase_menu(lst);
		main_menu(lst);
	}
	if ((x >= 350 && x <= 400) && (y >= 600 && y <= 650))
		my_key_funct1(123, lst->frame);
	if ((x >= 550 && x <= 600) && (y >= 600 && y <= 650))
		my_key_funct1(124, lst->frame);
	if ((x >= 450 && x <= 500) && (y >= 500 && y <= 550))
		my_key_funct1(126, lst->frame);
	if ((x >= 450 && x <= 500) && (y >= 700 && y <= 750))
		my_key_funct1(125, lst->frame);
	if ((x >= 450 && x <= 500) && (y >= 570 && y <= 620))
		my_key_funct1(269, lst->frame);
	if ((x >= 450 && x <= 500) && (y >= 630 && y <= 680))
		my_key_funct1(258, lst->frame);
	if ((x >= 250 && x <= 300) && (y >= 600 && y <= 650))
		my_key_funct1(0, lst->frame);
	if ((x >= 650 && x <= 700) && (y >= 600 && y <= 650))
		my_key_funct1(2, lst->frame);
	if ((x >= 450 && x <= 500) && (y >= 400 && y <= 450))
		my_key_funct1(13, lst->frame);
	clique_cam2(lst, x, y);
}

void	clique_cam2(t_tri *lst, int x, int y)
{
	if ((x >= 450 && x <= 500) && (y >= 800 && y <= 850))
		my_key_funct1(1, lst->frame);
	if ((x >= 300 && x <= 350) && (y >= 470 && y <= 520))
		my_key_funct1(14, lst->frame);
	if ((x >= 600 && x <= 650) && (y >= 470 && y <= 520))
		my_key_funct1(12, lst->frame);
	if ((x >= 200 && x <= 250) && (y >= 900 && y <= 950))
		my_key_funct1(67, lst->frame);
	if ((x >= 200 && x <= 250) && (y >= 1000 && y <= 1050))
		my_key_funct1(75, lst->frame);
	if ((x >= 350 && x <= 400) && (y >= 900 && y <= 950))
		my_key_funct1(116, lst->frame);
	if ((x >= 350 && x <= 400) && (y >= 1000 && y <= 1050))
		my_key_funct1(121, lst->frame);
	if ((x >= 650 && x <= 700) && (y >= 950 && y <= 1000))
		my_key_funct1(28, lst->frame);
	if ((x >= 651 && x <= 701) && (y >= 1001 && y <= 1051))
		my_key_funct1(26, lst->frame);
	if ((x >= 701 && x <= 751) && (y >= 1001 && y <= 1051))
		my_key_funct1(25, lst->frame);
	if ((x >= 751 && x <= 801) && (y >= 1001 && y <= 1051))
		my_key_funct1(51, lst->frame);
	clique_cam3(lst, x, y);
}

void	clique_cam3(t_tri *lst, int x, int y)
{
	if ((x >= 581 && x <= 631) && (y >= 950 && y <= 1000))
		my_key_funct1(33, lst->frame);
	if ((x >= 530 && x <= 580) && (y >= 950 && y <= 1000))
		my_key_funct1(35, lst->frame);
	if ((x >= 465 && x <= 485) && (y >= 930 && y <= 950))
	{
		lst->SCENE.lum_amb += 0.1;
		expose_hook(lst->frame);
	}
	if ((x >= 465 && x <= 485) && (y >= 1020 && y <= 1040))
	{
		if (lst->SCENE.lum_amb > 0.1)
		{
			lst->SCENE.lum_amb -= 0.1;
			expose_hook(lst->frame);
		}
	}
	if ((x >= 200 && x <= 800) && (y >= 300 && y <= 1200))
	{
		erase_menu(lst);
		menu_cam(lst);
	}
}
