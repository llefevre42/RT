/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:47:47 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/24 20:21:47 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	load_block(t_tri *lst)
{
	lst->lsize = 20;
	lst->h = 20;
	lst->l = 20;
	lst->color = 0X000000;
	lst->cube_xxs_black = put_in_img(0, 0, lst->cube_xxs_black, lst);
	lst->lsize = 50;
	lst->h = 50;
	lst->l = 50;
	lst->back = put_in_img(0, 0, lst->back, lst);
	lst->color = 0X6D0863;
	lst->cube_xs_purple = put_in_img(0, 0, lst->cube_xs_purple, lst);
	lst->color = 0XFFFFFF;
	lst->cube_xs_white = put_in_img(0, 0, lst->cube_xs_white, lst);
	lst->color = 0X808080;
	lst->cube_xs_grey = put_in_img(0, 0, lst->cube_xs_grey, lst);
	lst->lsize = 100;
	lst->h = 100;
	lst->l = 100;
	lst->color = 0XFFFFFF;
	lst->cube_s_white = put_in_img(0, 0, lst->cube_s_white, lst);
	load_block2(lst);
}

void	load_block2(t_tri *lst)
{
	lst->lsize = 2000;
	lst->l = LARG;
	lst->h = HAUT;
	lst->color = 0XC2C2C2;
	lst->inter_g = put_in_img(0, 0, lst->inter_g, lst);
	lst->h = 1000;
	lst->l = 850;
	lst->color = 0X0E5207;
	lst->inter_g = put_in_img(50, 150, lst->inter_g, lst);
	lst->l = 1000;
	lst->inter_g = put_in_img(950, 150, lst->inter_g, lst);
	lst->lsize = 850;
	lst->l = 850;
	lst->block_xl_red = put_in_img(0, 0, lst->block_xl_red, lst);
	text_form(lst);
	mlx_put_image_to_window(lst->mlx, lst->win, lst->pt_p_home, 0, 0);
	mlx_put_image_to_window(lst->mlx, lst->win, lst->pt_p_render, 923, 0);
}

char	*str_itoa_b(t_tri *lst, int x, int y, double nb)
{
	char *tmp;

	tmp = ft_itoa(nb);
	mlx_string_put(lst->mlx, lst->win, x, y, 0, tmp);
	return (tmp);
}

char	*str_itoa_w(t_tri *lst, int x, int y, double nb)
{
	char *tmp;

	tmp = ft_itoa(nb);
	mlx_string_put(lst->mlx, lst->win, x, y, 0XFFFFFF, tmp);
	return (tmp);
}
