/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:38:46 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/21 21:47:53 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	menu_file(t_tri *l)
{
	int i;
	int c;

	c = 0XFFFFFF;
	ls(l, 99);
	i = l->number_file;
	mlx_put_image_to_window(l->mlx, l->win, l->pt_p_menu_file, 0, 0);
	if (i > 12 + l->page)
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_fleched, 750, 200);
	if (l->page > 11)
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_flecheg, 150, 200);
	mlx_string_put(l->mlx, l->win, 425, 170, c, "Choose your file");
	if (i > 0 + l->page)
	{
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_mini_file, 250, 300);
		mlx_string_put(l->mlx, l->win, 260, 410, c, afich(ls(l, 1 + l->page)));
	}
	if (i > 1 + l->page)
	{
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_mini_file, 450, 300);
		mlx_string_put(l->mlx, l->win, 460, 410, c, afich(ls(l, 2 + l->page)));
	}
	menu_file2(l, c, i);
}

void	menu_file2(t_tri *l, int c, int i)
{
	if (i > 2 + l->page)
	{
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_mini_file, 650, 300);
		mlx_string_put(l->mlx, l->win, 660, 410, c, afich(ls(l, 3 + l->page)));
	}
	if (i > 3 + l->page)
	{
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_mini_file, 250, 500);
		mlx_string_put(l->mlx, l->win, 260, 610, c, afich(ls(l, 4 + l->page)));
	}
	if (i > 4 + l->page)
	{
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_mini_file, 450, 500);
		mlx_string_put(l->mlx, l->win, 460, 610, c, afich(ls(l, 5 + l->page)));
	}
	if (i > 5 + l->page)
	{
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_mini_file, 650, 500);
		mlx_string_put(l->mlx, l->win, 660, 610, c, afich(ls(l, 6 + l->page)));
	}
	menu_file3(l, c, i);
}

void	menu_file3(t_tri *l, int c, int i)
{
	if (i > 6 + l->page)
	{
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_mini_file, 250, 700);
		mlx_string_put(l->mlx, l->win, 260, 810, c, afich(ls(l, 7 + l->page)));
	}
	if (i > 7 + l->page)
	{
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_mini_file, 450, 700);
		mlx_string_put(l->mlx, l->win, 460, 810, c, afich(ls(l, 8 + l->page)));
	}
	if (i > 8 + l->page)
	{
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_mini_file, 650, 700);
		mlx_string_put(l->mlx, l->win, 660, 810, c, afich(ls(l, 9 + l->page)));
	}
	if (i > 9 + l->page)
	{
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_mini_file, 250, 900);
		mlx_string_put(l->mlx, l->win, 260, 1010, c, \
				afich(ls(l, 10 + l->page)));
	}
	menu_file4(l, c, i);
}

void	menu_file4(t_tri *l, int c, int i)
{
	if (i > 10 + l->page)
	{
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_mini_file, 450, 900);
		mlx_string_put(l->mlx, l->win, 460, 1010, c, \
				afich(ls(l, 11 + l->page)));
	}
	if (i > 11 + l->page)
	{
		mlx_put_image_to_window(l->mlx, l->win, l->pt_p_mini_file, 650, 900);
		mlx_string_put(l->mlx, l->win, 660, 1010, c, \
				afich(ls(l, 12 + l->page)));
	}
}
