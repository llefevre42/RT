/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_modif_21_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:52:23 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/15 17:53:39 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	clique_modif6(t_tri *lst, int x, int y, t_object *obj)
{
	if (obj->ks > 1)
		obj->ks = 1;
	if (obj->ks < 0)
		obj->ks = 0;
	if (obj->reflec > 1)
		obj->reflec = 1;
	if (obj->reflec < 0)
		obj->reflec = 0;
	if (obj->indice > 2)
		obj->indice = 2;
	if (obj->indice < 0)
		obj->indice = 0;
	modif_form(lst);
	if (obj->type >= 0 && obj->type <= 3)
		preview_build(lst, obj, obj->type);
	expose_hook(lst->frame);
	lst->preview_in = 0;
	if ((x >= 460 && x <= 510) && (y >= 950 && y <= 1000))
		expose_hook(lst->frame);
}
