/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brackets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:08:42 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/21 13:59:25 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_comma(t_pars *p)
{
	while (p->f[p->i] != ',')
		p->i++;
	p->i++;
	while (ft_isspace(p->f[p->i]))
		p->i++;
}

void	ft_skiptobracket(t_pars *p)
{
	while (p->f[p->i] != '[')
		p->i++;
	if (p->f[p->i] == '[')
		p->i++;
}

void	ft_endbracket(t_pars *p)
{
	while (p->f[p->i] != ']')
		p->i++;
}
