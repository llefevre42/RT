/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 20:21:02 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/30 13:11:53 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			init_light(t_light *l)
{
	l->orig = ft_vec_create(0., 0., 0.);
	l->i = ft_vec_create(1., 1., 1.);
	l->color = ft_vec_create(1., 1., 1.);
	l->next = NULL;
	l->obj = NULL;
}

void			add_light_object(t_object **dst, t_vec orig, t_vec c)
{
	t_object	*p_object;

	p_object = (t_object*)ft_memalloc(sizeof(t_object));
	init_object(p_object);
	p_object->type = LIGHT;
	p_object->orig = orig;
	p_object->data.x = 1;
	p_object->color = c;
	p_object->ka = 10.;
	p_object->kd = 10.;
	p_object->ks = 10.;
	add_object(dst, p_object, 0);
	return ;
}

void			add_light(t_frame *frame)
{
	t_light		*p_light;
	t_light		*tmp;

	p_light = (t_light*)ft_memalloc(sizeof(t_light));
	init_light(p_light);
	tmp = LIGHT_B;
	p_light->next = tmp;
	LIGHT_B = p_light;
	return ;
}
