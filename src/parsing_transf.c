/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_transf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:43:02 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/17 14:17:43 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			parsing_transf(t_frame *frame, t_object **dst, char *line)
{
	char		*tmp;

	if (dst == NULL)
		exit(1);
	if ((tmp = ft_strstr(line, "BLANK")))
		add_blank(dst, 1);
	if ((tmp = ft_strstr(line, "PLAN")))
		add_plan(dst, 1);
	if ((tmp = ft_strstr(line, "SPHERE")))
		add_sphere(dst, 1);
	if ((tmp = ft_strstr(line, "CONE")))
		add_cone(dst, 1);
	if ((tmp = ft_strstr(line, "CYLINDRE")))
		add_cylindre(dst, 1);
	parsing_transf2(frame, dst, line, tmp);
}

void			parsing_transf2(t_frame *frame, \
		t_object **dst, char *line, char *tmp)
{
	t_object	*tobj;

	tobj = OBJECT_B;
	OBJECT_B = dst[0]->transf;
	dst[0] = OBJECT_B;
	parsing_colb(frame, line);
	if ((tmp = ft_strstr(line, "rayon")))
		dst[0]->r = ft_atoi_d(&tmp);
	if ((tmp = ft_strstr(line, "angle")))
		dst[0]->r = pow(tan(ft_atoi_d(&tmp) * M_PI / 180.), 2);
	if ((tmp = ft_strstr(line, "EXTR ")))
		dst[0]->transf_type = EXTRUSION;
	else if ((tmp = ft_strstr(line, "UNION")))
		dst[0]->transf_type = UNION;
	else if ((tmp = ft_strstr(line, "INTER")))
		dst[0]->transf_type = INTERSECTION;
	else if ((tmp = ft_strstr(line, "EXTR_INV")))
		dst[0]->transf_type = EXTRUSION_INV;
	OBJECT_B = tobj;
}
