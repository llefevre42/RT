/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_modif_21.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:10:51 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/28 19:31:06 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	clique_modif(t_tri *lst, int x, int y)
{
	t_object	*obj;

	obj = current_obj(lst);
	lst->i = 1;
	lst->preview_in = 1;
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
		obj->data.x += 0.01 * lst->i;
	clique_modif2(lst, x, y, obj);
}

void	clique_modif2(t_tri *lst, int x, int y, t_object *obj)
{
	if ((x >= 565 && x <= 585) && (y >= 510 && y <= 530))
		obj->data.x -= 0.01 * lst->i;
	if ((x >= 665 && x <= 685) && (y >= 420 && y <= 440))
		obj->data.y += 0.01 * lst->i;
	if ((x >= 665 && x <= 685) && (y >= 510 && y <= 530))
		obj->data.y -= 0.01 * lst->i;
	if ((x >= 765 && x <= 785) && (y >= 420 && y <= 440))
		obj->data.z += 0.01 * lst->i;
	if ((x >= 765 && x <= 785) && (y >= 510 && y <= 530))
		obj->data.z -= 0.01 * lst->i;
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
	clique_modif3(lst, x, y, obj);
}

void	clique_modif3(t_tri *lst, int x, int y, t_object *obj)
{
	if ((x >= 165 && x <= 185) && (y >= 680 && y <= 700))
	{
		if (obj->type == 3)
			obj->r += 0.01 * lst->i;
		else
			obj->r += 1 * lst->i;
	}
	if ((x >= 165 && x <= 185) && (y >= 770 && y <= 790))
	{
		if (obj->type == 3)
			obj->r -= 0.01 * lst->i;
		else
			obj->r -= 1 * lst->i;
	}
	if ((x >= 265 && x <= 285) && (y >= 680 && y <= 700))
		obj->transp += 1 * lst->i;
	if ((x >= 265 && x <= 285) && (y >= 770 && y <= 790))
		obj->transp -= 1 * lst->i;
	if ((x >= 365 && x <= 385) && (y >= 680 && y <= 700))
		obj->matiere += 1 * lst->i;
	if ((x >= 365 && x <= 385) && (y >= 770 && y <= 790))
		obj->matiere -= 1 * lst->i;
	if ((x >= 465 && x <= 485) && (y >= 680 && y <= 700))
		obj->indice += 0.01 * lst->i;
	clique_modif4(lst, x, y, obj);
}

void	clique_modif4(t_tri *lst, int x, int y, t_object *obj)
{
	if ((x >= 465 && x <= 485) && (y >= 770 && y <= 790))
		obj->indice -= 0.01 * lst->i;
	if ((x >= 565 && x <= 585) && (y >= 680 && y <= 700))
		obj->rug += 0.01 * lst->i;
	if ((x >= 565 && x <= 585) && (y >= 770 && y <= 790))
		obj->rug -= 0.01 * lst->i;
	if ((x >= 665 && x <= 685) && (y >= 680 && y <= 700))
		obj->ks += 0.01 * lst->i;
	if ((x >= 665 && x <= 685) && (y >= 770 && y <= 790))
		obj->ks -= 0.01 * lst->i;
	if ((x >= 765 && x <= 785) && (y >= 680 && y <= 700))
		obj->reflec += 0.01 * lst->i;
	if ((x >= 765 && x <= 785) && (y >= 770 && y <= 790))
		obj->reflec -= 0.01 * lst->i;
	obj->data = ft_normalize(obj->data);
	clique_modif5(lst, x, y, obj);
}

void	clique_modif5(t_tri *lst, int x, int y, t_object *obj)
{
	if (obj->transp > 100)
		obj->transp = 100;
	if (obj->transp < 0)
		obj->transp = 0;
	if (obj->matiere > 2)
		obj->matiere = 2;
	if (obj->matiere < 0)
		obj->matiere = 0;
	if (obj->color.x > 1)
		obj->color.x = 1;
	if (obj->color.x < 0)
		obj->color.x = 0;
	if (obj->color.y > 1)
		obj->color.y = 1;
	if (obj->color.y < 0)
		obj->color.y = 0;
	if (obj->color.z > 1)
		obj->color.z = 1;
	if (obj->color.z < 0)
		obj->color.z = 0;
	if (obj->rug > 1)
		obj->rug = 1;
	if (obj->rug < 0)
		obj->rug = 0;
	clique_modif6(lst, x, y, obj);
}
