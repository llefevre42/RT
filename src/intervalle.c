/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intervalle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:25:25 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/22 15:15:02 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_material		*mate_inter_mate(t_material *src, \
		t_material *extr, t_material **begin)
{
	if (src == NULL)
		return (src);
	else if (extr == NULL || (extr->t1 <= src->t1 && extr->t2 >= src->t2))
		return (src->next);
	else if (extr->t1 > src->t1 && extr->t2 < src->t2)
	{
		src->t1 = extr->t1;
		src->obj1 = extr->obj1;
		src->t2 = extr->t2;
		src->obj2 = extr->obj2;
	}
	else if (extr->t1 <= src->t1 && extr->t2 >= src->t1 && extr->t2 <= src->t2)
	{
		src->t2 = extr->t2;
		src->obj2 = extr->obj2;
	}
	else if (extr->t1 >= src->t1 && extr->t1 <= src->t2 && extr->t2 > src->t2)
	{
		src->t1 = extr->t1;
		src->obj1 = extr->obj1;
	}
	else if (extr->t1 >= src->t2 || extr->t2 < src->t1)
		return (remove_mate(src, begin));
	return (src->next);
}

t_material		*mate_extr_mate(t_material *src, \
		t_material *extr, t_material **begin)
{
	float		tmp;
	t_object	*tobj;

	tmp = 0.;
	tobj = NULL;
	if (src == NULL)
		return (src);
	else if (extr == NULL)
		return (src->next);
	else if ((extr->t1 <= src->t1 && extr->t2 >= src->t2) \
			|| (src->t1 == src->t2) || (src->t1 < 0. && src->t2 < 0.))
		return (remove_mate(src, begin));
	else if (extr->t1 > src->t1 && extr->t2 < src->t2)
	{
		tmp = src->t2;
		tobj = src->obj2;
		src->obj2 = extr->obj1;
		src->t2 = extr->t1;
		add_mate(create_mate(extr->t2, tmp, extr->obj2, tobj), &src);
	}
	mate_extr_mate2(src, extr);
	return (src->next);
}

t_material		*s_mate_extr_mate(t_material *src, \
		t_material *extr, t_material **begin)
{
	if (src == NULL)
		return (src);
	else if (extr == NULL)
		return (src->next);
	if (src->t1 >= extr->t1 && src->t1 <= extr->t2)
		src->t1 = INT_MAX;
	if (src->t2 >= extr->t1 && src->t2 <= extr->t2)
		src->t2 = INT_MAX;
	if (src->t1 == src->t2 && src->t1 == INT_MAX)
		return (remove_mate(src, begin));
	return (src->next);
}

t_material		*obj_extr(t_material *src, t_material *extr, int volume)
{
	t_material	*begin;
	t_material	*begin2;

	begin = src;
	begin2 = extr;
	while (extr != NULL && src != NULL)
	{
		while (src != NULL)
		{
			if (volume == 1)
				src = mate_extr_mate(src, extr, &begin);
			else
				src = s_mate_extr_mate(src, extr, &begin);
		}
		src = begin;
		extr = extr->next;
	}
	extr = begin2;
	if (extr != NULL)
		remove_all_mate(extr);
	src = begin;
	return (src);
}

t_material		*obj_inter_volume(t_material *src, t_material *extr)
{
	t_material	*begin;
	t_material	*begin2;

	begin = src;
	begin2 = extr;
	while (extr != NULL && src != NULL)
	{
		while (src != NULL)
			src = mate_inter_mate(src, extr, &begin);
		src = begin;
		extr = extr->next;
	}
	extr = begin2;
	if (extr != NULL)
		remove_all_mate(extr);
	src = begin;
	return (src);
}
