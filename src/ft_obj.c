/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:02:46 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/21 14:18:38 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_ifs(int type, t_object ***new, int transf)
{
	if (type == 5)
		add_plan(*new, transf);
	if (type == 6)
		add_cone(*new, transf);
	if (type == 7)
		add_sphere(*new, transf);
	if (type == 8)
		add_cylindre(*new, transf);
	if (type == 30)
		add_blank(*new, transf);
}

void		ft_obj(t_frame *frame, t_pars *p)
{
	t_object	**new;
	int			transf;

	if (p->depth == 2)
		new = &OBJECT_B;
	else if (p->depth > 2)
		new = &p->l->next->o;
	transf = 0;
	if (p->l && p->l->next && (*new)->transf == NULL)
		transf = 1;
	else if (p->l && p->l->next && (*new)->transf != NULL)
		transf = 1;
	ft_ifs(p->type, &new, transf);
	p->last_type = p->type;
	p->type = 0;
	if (transf == 0)
		p->l->o = *new;
	else if (transf == 1)
		p->l->o = (*new)->transf;
	p->l->depth = p->depth;
}
