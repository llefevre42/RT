/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_light_42.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 21:58:39 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/17 14:12:41 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	clique_modif_light(t_tri *lst, int x, int y)
{
	t_light *obj;

	if (!(obj = l_current_obj(lst)))
		return ;
	lst->i = 1;
	if (lst->key == 2)
		lst->i = 10;
	if ((x >= 165 && x <= 185) && (y >= 420 && y <= 440))
		obj->orig.x += 1 * lst->i;
	if ((x >= 165 && x <= 185) && (y >= 510 && y <= 530))
		obj->orig.x -= 1 * lst->i;
	if ((x >= 265 && x <= 285) && (y >= 420 && y <= 440))
		obj->orig.y += 1 * lst->i;
	if ((x >= 265 && x <= 285) && (y >= 510 && y <= 530))
		obj->orig.y -= 1 * lst->i;
	if ((x >= 365 && x <= 385) && (y >= 420 && y <= 440))
		obj->orig.z += 1 * lst->i;
	if ((x >= 365 && x <= 385) && (y >= 510 && y <= 530))
		obj->orig.z -= 1 * lst->i;
	if ((x >= 565 && x <= 585) && (y >= 420 && y <= 440))
		obj->i.x += 0.01 * lst->i;
	if ((x >= 565 && x <= 585) && (y >= 510 && y <= 530))
		obj->i.x -= 0.01 * lst->i;
	clique_modif_light2(lst, x, y, obj);
}

void	clique_modif_light2(t_tri *lst, int x, int y, t_light *obj)
{
	if ((x >= 665 && x <= 685) && (y >= 420 && y <= 440))
		obj->i.y += 0.01 * lst->i;
	if ((x >= 665 && x <= 685) && (y >= 510 && y <= 530))
		obj->i.y -= 0.01 * lst->i;
	if ((x >= 765 && x <= 785) && (y >= 420 && y <= 440))
		obj->i.z += 0.01 * lst->i;
	if ((x >= 765 && x <= 785) && (y >= 510 && y <= 530))
		obj->i.z -= 0.01 * lst->i;
	if ((x >= 365 && x <= 385) && (y >= 540 && y <= 560))
		obj->color.x += 0.003 * lst->i;
	if ((x >= 365 && x <= 385) && (y >= 630 && y <= 650))
		obj->color.x -= 0.003 * lst->i;
	if ((x >= 465 && x <= 485) && (y >= 540 && y <= 560))
		obj->color.y += 0.003 * lst->i;
	if ((x >= 465 && x <= 485) && (y >= 630 && y <= 650))
		obj->color.y -= 0.003 * lst->i;
	if ((x >= 565 && x <= 585) && (y >= 540 && y <= 560))
		obj->color.z += 0.003 * lst->i;
	if ((x >= 565 && x <= 585) && (y >= 630 && y <= 650))
		obj->color.z -= 0.003 * lst->i;
	if ((x >= 460 && x <= 510) && (y >= 970 && y <= 1020))
		expose_hook(lst->frame);
	limitation(obj);
	modif_light(lst);
}
