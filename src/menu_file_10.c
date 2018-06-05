/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_file_10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 18:30:12 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/22 13:38:27 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	file_manag(t_tri *lst, char *str)
{
	mlx_put_image_to_window(lst->mlx, lst->win, lst->pt_p_menu_file, 0, 0);
	mlx_string_put(lst->mlx, lst->win, 450, 330, 0XFFFFFF, str);
	mlx_put_image_to_window(lst->mlx, lst->win, lst->pt_cube_s_white, 200, 800);
	mlx_string_put(lst->mlx, lst->win, 255, 830, 0X000000, "add");
	mlx_put_image_to_window(lst->mlx, lst->win, lst->pt_cube_s_white, 650, 800);
	mlx_string_put(lst->mlx, lst->win, 675, 830, 0X000000, "fusion");
}

void	go_to_file(t_tri *lst, int i)
{
	erase_menu(lst);
	lst->sous_menu = 11;
	lst->file_load = i + lst->page;
	file_manag(lst, ls(lst, i + lst->page));
}

void	clique_on_file(t_tri *lst, int x, int y)
{
	ls(lst, 99);
	if ((x >= 150 && x <= 200) && (y >= 200 && y <= 250))
	{
		if (lst->page > 0)
			lst->page -= 12;
		erase_menu(lst);
		menu_file(lst);
	}
	if ((x >= 750 && x <= 800) && (y >= 200 && y <= 250)\
			&& lst->number_file - 12 > lst->page)
	{
		lst->page += 12;
		erase_menu(lst);
		menu_file(lst);
	}
	if ((x >= 50 && x <= 100) && (y >= 150 && y <= 200))
	{
		erase_menu(lst);
		lst->sous_menu = 0;
		main_menu(lst);
	}
	clique_on_file2(lst, x, y);
}

void	clique_on_file2(t_tri *lst, int x, int y)
{
	int i;

	i = lst->number_file;
	if ((x >= 250 && x <= 350) && (y >= 300 && y <= 400) && i >= 1 + lst->page)
		go_to_file(lst, 1);
	if ((x >= 450 && x <= 550) && (y >= 300 && y <= 400) && i >= 2 + lst->page)
		go_to_file(lst, 2);
	if ((x >= 650 && x <= 750) && (y >= 300 && y <= 400) && i >= 3 + lst->page)
		go_to_file(lst, 3);
	if ((x >= 250 && x <= 350) && (y >= 500 && y <= 600) && i >= 4 + lst->page)
		go_to_file(lst, 4);
	if ((x >= 450 && x <= 550) && (y >= 500 && y <= 600) && i >= 5 + lst->page)
		go_to_file(lst, 5);
	if ((x >= 650 && x <= 750) && (y >= 500 && y <= 600) && i >= 6 + lst->page)
		go_to_file(lst, 6);
	clique_on_file3(lst, x, y, i);
}

void	clique_on_file3(t_tri *l, int x, int y, int i)
{
	if ((x >= 250 && x <= 350) && (y >= 700 && y <= 800) && i >= 7 + l->page)
		go_to_file(l, 7);
	if ((x >= 450 && x <= 550) && (y >= 700 && y <= 800) && i >= 8 + l->page)
		go_to_file(l, 8);
	if ((x >= 650 && x <= 750) && (y >= 700 && y <= 800) && i >= 9 + l->page)
		go_to_file(l, 9);
	if ((x >= 250 && x <= 350) && (y >= 900 && y <= 1000) && i >= 10 + l->page)
		go_to_file(l, 10);
	if ((x >= 450 && x <= 550) && (y >= 900 && y <= 1000) && i >= 11 + l->page)
		go_to_file(l, 11);
	if ((x >= 650 && x <= 750) && (y >= 900 && y <= 1000) && i >= 12 + l->page)
		go_to_file(l, 12);
}
