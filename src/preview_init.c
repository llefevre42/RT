/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preview_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:09:28 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/17 16:31:30 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	preview_build(t_tri *lst, t_object *obj, int type)
{
	t_object *tmp;
	t_object *trash;

	tmp = lst->preview->scene.object_begin;
	while (tmp && (tmp->type != type || tmp->type > 3))
		tmp = tmp->next;
	if (tmp)
		preview_build2(obj, tmp);
	trash = lst->preview->scene.object_begin;
	while (trash)
	{
		if (trash->type != type)
			trash_reset(trash);
		trash = trash->next;
	}
}

void	preview_build2(t_object *obj, t_object *tmp)
{
	tmp->orig.x = 0;
	tmp->orig.y = 0;
	tmp->orig.z = -500;
	if (tmp->type != 0)
	{
		tmp->data.x = obj->data.x;
		tmp->data.y = obj->data.y;
		tmp->data.z = obj->data.z;
		tmp->data = ft_normalize(tmp->data);
	}
	else
	{
		tmp->data.x = 0;
		tmp->data.y = 0;
		tmp->data.z = 1;
	}
	preview_build3(obj, tmp);
}

void	preview_build3(t_object *obj, t_object *tmp)
{
	tmp->color.x = obj->color.x;
	tmp->color.y = obj->color.y;
	tmp->color.z = obj->color.z;
	tmp->r = obj->r;
	tmp->matiere = obj->matiere;
	tmp->transp = obj->transp;
	tmp->indice = obj->indice;
	tmp->rug = obj->rug;
	tmp->ks = obj->ks;
	tmp->reflec = obj->reflec;
}

void	preview_add(t_tri *lst)
{
	t_object *tmp;
	t_object *trash;

	tmp = lst->preview->scene.object_begin;
	while (tmp && (tmp->type != lst->add_form_who || tmp->type > 3))
		tmp = tmp->next;
	if (tmp)
		preview_add2(lst, tmp);
	trash = lst->preview->scene.object_begin;
	while (trash)
	{
		if (trash->type != lst->add_form_who)
			trash_reset(trash);
		trash = trash->next;
	}
}

void	trash_reset(t_object *trash)
{
	trash->orig.x = 0;
	trash->orig.y = 0;
	trash->orig.z = 0;
	trash->data.x = 0;
	trash->data.y = 1;
	trash->data.z = 0;
	trash->color.x = 0;
	trash->color.y = 0;
	trash->color.z = 0;
	trash->r = 0;
	trash->matiere = 0;
	trash->transp = 0;
	trash->rug = 0;
	trash->ks = 0;
	trash->reflec = 0;
}
