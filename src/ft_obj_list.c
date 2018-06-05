/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:06:49 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/30 13:12:41 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_transf(t_pars *p)
{
	t_trans	*new;
	int		i;

	i = 0;
	new = ft_memalloc(sizeof(*new));
	new->o = NULL;
	while (i < 21)
		new->read[i++] = 0;
	new->depth = p->depth;
	new->next = p->l;
	p->l = new;
	p->type = 0;
	if (p->i != 0)
		p->extr++;
}

void	rm_transf(t_pars *p)
{
	t_trans	*tmp;

	if (p->l && p->l->next)
	{
		tmp = p->l->next;
		free(p->l);
		p->l = NULL;
		p->l = tmp;
		p->extr--;
	}
}
