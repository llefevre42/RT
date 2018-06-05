/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 16:12:22 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/21 19:19:42 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_object	*current_obj(t_tri *lst)
{
	int			i;
	t_object	*obj;

	i = 0;
	obj = lst->frame->scene.object_begin;
	while (obj && i < lst->modif_form_who)
	{
		if (obj->type == LIGHT)
			obj = obj->next;
		if (obj)
			obj = obj->next;
		i++;
	}
	if (obj == NULL)
		obj = lst->frame->scene.object_begin;
	return (obj);
}

void		count_liste(t_tri *lst)
{
	int			i;
	t_object	*obj;

	i = 0;
	obj = lst->frame->scene.object_begin;
	while (obj != NULL)
	{
		if (obj->type != LIGHT)
			i++;
		obj = obj->next;
	}
	lst->count_liste = i;
}

t_light		*l_current_obj(t_tri *lst)
{
	int		i;
	t_light *obj;

	i = 0;
	obj = lst->frame->scene.light_begin;
	while (obj && i < lst->l_add_form_who)
	{
		i++;
		obj = obj->next;
	}
	return (obj);
}

void		l_count_liste(t_tri *lst)
{
	int		i;
	t_light	*obj;

	i = 0;
	obj = lst->frame->scene.light_begin;
	while (obj != NULL)
	{
		i++;
		obj = obj->next;
	}
	lst->l_count_liste = i;
}
