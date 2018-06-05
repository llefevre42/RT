/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 19:28:04 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/16 23:22:24 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		rotate_obj(t_vec r, t_object *obj, t_vec orig)
{
	t_vec	tmp;

	tmp = obj->orig;
	obj->orig = ft_vec_linear(1., obj->orig, -1., orig);
	if (r.x != 0.)
	{
		obj->orig = chg_rep_vec(mat_rot_x(r.x), obj->orig);
		obj->data = chg_rep_vec(mat_rot_x(r.x), obj->data);
	}
	if (r.y != 0.)
	{
		obj->orig = chg_rep_vec(mat_rot_y(r.y), obj->orig);
		obj->data = chg_rep_vec(mat_rot_y(r.y), obj->data);
	}
	if (r.z != 0.)
	{
		obj->orig = chg_rep_vec(mat_rot_z(r.z), obj->orig);
		obj->data = chg_rep_vec(mat_rot_z(r.z), obj->data);
	}
	obj->orig = ft_vec_linear(1., obj->orig, 1., orig);
	if (obj->transf != NULL)
		rotate_obj(r, obj->transf, orig);
	if (obj->next_transf != NULL)
		rotate_obj(r, obj->next_transf, orig);
}
