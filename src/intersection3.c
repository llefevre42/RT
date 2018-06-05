/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:20:03 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/16 18:20:27 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_vec	surf_transf(t_ray *ray, t_object *obj, t_vec t12)
{
	t_vec		t34;

	t34 = intersect_shape(ray, obj);
	if (obj->transf_type == EXTRUSION)
		t12 = surf_extrude(ray, obj, t12, t34);
	else if (obj->transf_type == INTERSECTION)
		t12 = surf_extrude_inv(obj, t12, t34);
	if (obj->transf != NULL)
		t12 = surf_transf(ray, obj, t12);
	return (t12);
}
