/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:56:15 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/30 13:04:01 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void		parsing_ld(t_frame *frame, char *line)
{
	char		*tmp;

	if ((tmp = ft_strstr(line, "direction")))
	{
		OBJECT_B->data.x = ft_atoi_d(&tmp);
		OBJECT_B->data.y = ft_atoi_d(&tmp);
		OBJECT_B->data.z = ft_atoi_d(&tmp);
		OBJECT_B->data = ft_normalize(OBJECT_B->data);
	}
}

void			parsing_colb(t_frame *frame, char *line)
{
	char		*tmp;

	if ((tmp = ft_strstr(line, "couleur")))
	{
		OBJECT_B->color.x = ft_atoi_d(&tmp);
		OBJECT_B->color.y = ft_atoi_d(&tmp);
		OBJECT_B->color.z = ft_atoi_d(&tmp);
	}
	if ((tmp = ft_strstr(line, "origine")))
	{
		OBJECT_B->orig.x = ft_atoi_d(&tmp);
		OBJECT_B->orig.y = ft_atoi_d(&tmp);
		OBJECT_B->orig.z = ft_atoi_d(&tmp);
	}
	if ((tmp = ft_strstr(line, "lum ")))
	{
		OBJECT_B->ka = ft_atoi_d(&tmp);
		OBJECT_B->kd = ft_atoi_d(&tmp);
		OBJECT_B->ks = ft_atoi_d(&tmp);
	}
	parsing_colb2(frame, line, tmp);
}

void			parsing_colb2(t_frame *frame, char *line, char *tmp)
{
	if ((tmp = ft_strstr(line, "brillance")))
		OBJECT_B->alpha = ft_atoi_d(&tmp);
	if ((tmp = ft_strstr(line, "transp")))
		OBJECT_B->transp = ft_atoi_d(&tmp);
	if ((tmp = ft_strstr(line, "reflec")))
		OBJECT_B->reflec = ft_atoi_d(&tmp) / 100.;
	if ((tmp = ft_strstr(line, "indice")))
		OBJECT_B->indice = ft_atoi_d(&tmp);
	if ((tmp = ft_strstr(line, "matiere")))
		OBJECT_B->matiere = (int)ft_atoi_d(&tmp);
	if ((tmp = ft_strstr(line, "rug")))
		OBJECT_B->rug = ft_atoi_d(&tmp);
	if ((tmp = ft_strstr(line, "volume")))
		OBJECT_B->volume = (int)ft_atoi_d(&tmp);
	parsing_ld(frame, line);
}

void			parsing_object2(t_frame *frame, char *line)
{
	char		*tmp;

	if ((tmp = ft_strstr(line, "SPHERE")))
	{
		add_sphere(&OBJECT_B, 0);
		if ((tmp = ft_strstr(line, "rayon")))
			OBJECT_B->r = ft_atoi_d(&tmp);
		parsing_colb(frame, line);
	}
}

void			parsing_object3(t_frame *frame, char *line)
{
	char		*tmp;

	if ((tmp = ft_strstr(line, "QUAD")))
	{
		add_quad(&OBJECT_B, 0);
		parsing_colb(frame, line);
		if ((tmp = ft_strstr(line, "equ")))
		{
			OBJECT_B->quad.q.a = ft_atoi_d(&tmp);
			OBJECT_B->quad.q.b = ft_atoi_d(&tmp);
			OBJECT_B->quad.q.c = ft_atoi_d(&tmp);
			OBJECT_B->quad.q.d = ft_atoi_d(&tmp);
			OBJECT_B->quad.q.e = ft_atoi_d(&tmp);
			OBJECT_B->quad.q.f = ft_atoi_d(&tmp);
			OBJECT_B->quad.q.g = ft_atoi_d(&tmp);
			OBJECT_B->quad.q.h = ft_atoi_d(&tmp);
			OBJECT_B->quad.q.i = ft_atoi_d(&tmp);
			OBJECT_B->quad.u.x = ft_atoi_d(&tmp);
			OBJECT_B->quad.u.y = ft_atoi_d(&tmp);
			OBJECT_B->quad.u.z = ft_atoi_d(&tmp);
			OBJECT_B->quad.k = ft_atoi_d(&tmp);
		}
		parsing_ld(frame, line);
	}
}
