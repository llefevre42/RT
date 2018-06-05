/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:47:55 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/30 13:16:52 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void				add_blank(t_object **dst, int type)
{
	t_object		*p_object;

	if (!(p_object = (t_object*)malloc(sizeof(t_object))))
		ft_error(0);
	init_object(p_object);
	p_object->type = BLANK;
	add_object(dst, p_object, type);
	return ;
}

void				add_plan(t_object **dst, int type)
{
	t_object		*p_object;

	if (!(p_object = (t_object*)malloc(sizeof(t_object))))
		ft_error(0);
	init_object(p_object);
	p_object->type = PLAN;
	add_object(dst, p_object, type);
	return ;
}

void				add_sphere(t_object **dst, int type)
{
	t_object		*p_object;

	if (!(p_object = (t_object*)malloc(sizeof(t_object))))
		ft_error(0);
	init_object(p_object);
	p_object->type = SPHERE;
	add_object(dst, p_object, type);
	return ;
}

void				add_cylindre(t_object **dst, int type)
{
	t_object		*p_object;

	if (!(p_object = (t_object*)malloc(sizeof(t_object))))
		ft_error(0);
	init_object(p_object);
	p_object->type = CYLINDRE;
	add_object(dst, p_object, type);
	return ;
}

void				add_cone(t_object **dst, int type)
{
	t_object		*p_object;

	if (!(p_object = (t_object*)malloc(sizeof(t_object))))
		ft_error(0);
	init_object(p_object);
	p_object->type = CONE;
	add_object(dst, p_object, type);
	return ;
}
