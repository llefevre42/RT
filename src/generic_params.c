/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:11:46 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/21 14:36:08 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	**ft_voidstar(t_pars *p)
{
	void	**var;

	var = ft_memalloc(sizeof(void*) * 11);
	var[0] = &(p->l->o->orig);
	var[1] = &(p->l->o->color);
	var[2] = &(p->l->o->data);
	var[3] = &(p->l->o->reflec);
	var[4] = &(p->l->o->r);
	var[5] = &(p->l->o->rug);
	var[6] = &(p->l->o->transp);
	var[7] = &(p->l->o->alpha);
	var[8] = &(p->l->o->indice);
	var[9] = &(p->l->o->matiere);
	var[10] = &(p->l->o->volume);
	return (var);
}

t_vec	ft_vec3(t_pars *p)
{
	t_vec	vec;

	ft_skiptobracket(p);
	vec.x = atof_custom(&p->f[p->i]);
	ft_comma(p);
	vec.y = atof_custom(&p->f[p->i]);
	ft_comma(p);
	vec.z = atof_custom(&p->f[p->i]);
	ft_endbracket(p);
	return (vec);
}

double	ft_one_double(t_pars *p)
{
	double out;

	ft_skiptobracket(p);
	out = atof_custom(&p->f[p->i]);
	ft_endbracket(p);
	return (out);
}
