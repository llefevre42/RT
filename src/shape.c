/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:58:39 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/28 16:19:47 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void			add_object_2(t_object **dst, t_object *p_object, int type)
{
	t_object		tmp2;

	if (type >= 1)
	{
		tmp2 = *p_object;
		*p_object = **dst;
		p_object->transf = NULL;
		if (dst[0]->transf)
			p_object->next_transf = dst[0]->transf;
		else
			p_object->next_transf = NULL;
		p_object->type = tmp2.type;
		p_object->orig = tmp2.orig;
		p_object->data = tmp2.data;
		p_object->transp = 0.;
		p_object->matiere = tmp2.matiere;
		p_object->r = tmp2.r;
		(*dst)->transf = p_object;
	}
}

void				add_object(t_object **dst, t_object *p_object, int type)
{
	t_object		*tmp;

	if (type == 0)
	{
		if (dst == NULL)
		{
			*dst = p_object;
		}
		else
		{
			tmp = *dst;
			p_object->next = tmp;
			*dst = p_object;
		}
		return ;
	}
	add_object_2(dst, p_object, type);
}
