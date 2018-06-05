/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lum_limit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:12:37 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/21 14:44:32 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_lum(t_pars *p)
{
	if (!p->l->o)
		ft_error_txt("Bad lum parameter\n");
	ft_skiptobracket(p);
	p->l->o->ka = atof_custom(&p->f[p->i]);
	ft_comma(p);
	p->l->o->kd = atof_custom(&p->f[p->i]);
	ft_comma(p);
	p->l->o->ks = atof_custom(&p->f[p->i]);
	ft_endbracket(p);
}

void	ft_limit(t_pars *p)
{
	if (!p->l->o)
		ft_error_txt("Bad limit parameter\n");
	ft_skiptobracket(p);
	p->l->o->limit.x0 = atof_custom(&p->f[p->i]);
	ft_comma(p);
	p->l->o->limit.x1 = atof_custom(&p->f[p->i]);
	ft_comma(p);
	p->l->o->limit.y0 = atof_custom(&p->f[p->i]);
	ft_comma(p);
	p->l->o->limit.y1 = atof_custom(&p->f[p->i]);
	ft_comma(p);
	p->l->o->limit.z0 = atof_custom(&p->f[p->i]);
	ft_comma(p);
	p->l->o->limit.z1 = atof_custom(&p->f[p->i]);
	ft_endbracket(p);
}
