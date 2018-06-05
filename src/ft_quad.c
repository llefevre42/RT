/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:22:06 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/21 17:06:17 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static t_quad	ft_quad_bis(t_pars *p, t_quad *out)
{
	ft_comma(p);
	out->q.i = atof_custom(&p->f[p->i]);
	ft_comma(p);
	out->u.x = atof_custom(&p->f[p->i]);
	ft_comma(p);
	out->u.y = atof_custom(&p->f[p->i]);
	ft_comma(p);
	out->u.z = atof_custom(&p->f[p->i]);
	ft_comma(p);
	out->k = atof_custom(&p->f[p->i]);
	ft_endbracket(p);
	return (*out);
}

t_quad			ft_quad(t_pars *p)
{
	t_quad	out;
	int		i;

	i = 0;
	ft_skiptobracket(p);
	out.q.a = atof_custom(&p->f[p->i]);
	ft_comma(p);
	out.q.b = atof_custom(&p->f[p->i]);
	ft_comma(p);
	out.q.c = atof_custom(&p->f[p->i]);
	ft_comma(p);
	out.q.d = atof_custom(&p->f[p->i]);
	ft_comma(p);
	out.q.e = atof_custom(&p->f[p->i]);
	ft_comma(p);
	out.q.f = atof_custom(&p->f[p->i]);
	ft_comma(p);
	out.q.g = atof_custom(&p->f[p->i]);
	ft_comma(p);
	out.q.h = atof_custom(&p->f[p->i]);
	return (ft_quad_bis(p, &out));
}

void			ft_quad_obj(t_pars *p)
{
	p->l->o->type = QUAD;
	p->l->o->quad = ft_quad(p);
}
