/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intervalle3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:02:34 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/22 15:08:17 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_material		*remove_mate2(t_material *mate, t_material **begin)
{
	t_material	*tmp;

	tmp = NULL;
	tmp = mate->next;
	if (mate->before != NULL)
	{
		mate->before->next = mate->next;
		mate->next->before = mate->before;
	}
	else
	{
		mate->next->before = NULL;
		*begin = mate->next;
	}
	free(mate);
	return (tmp);
}

t_material		*remove_mate(t_material *mate, t_material **begin)
{
	t_material	*tmp;

	tmp = NULL;
	if (mate == NULL)
		return (NULL);
	if (mate->next == NULL)
	{
		if (mate->before == NULL)
			*begin = NULL;
		else
			mate->before->next = NULL;
		free(mate);
		mate = NULL;
		return (NULL);
	}
	else
		return (remove_mate2(mate, begin));
}

void			remove_all_mate(t_material *src)
{
	t_material	*tmp;

	if (src == NULL)
		return ;
	tmp = NULL;
	while (src != NULL)
	{
		if (src->next)
			tmp = src->next;
		else
			tmp = NULL;
		free(src);
		src = tmp;
	}
	return ;
}

t_material		*create_mate(double t1, double t2, \
		t_object *obj1, t_object *obj2)
{
	t_material	*mate;

	if (t1 == t2 || t1 > t2)
		return (NULL);
	if (!(mate = (t_material*)malloc(sizeof(t_material))))
		exit(1);
	mate->t1 = t1;
	mate->t2 = t2;
	mate->obj1 = obj1;
	mate->obj2 = obj2;
	mate->before = NULL;
	mate->next = NULL;
	return (mate);
}

void			add_mate(t_material *new, t_material **src)
{
	t_material	*tmp;

	if (new == NULL)
		return ;
	else if (*src == NULL)
		*src = new;
	else
	{
		tmp = *src;
		while ((*src)->next)
			*src = (*src)->next;
		(*src)->next = new;
		new->before = *src;
		*src = tmp;
	}
}
