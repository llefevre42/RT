/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jsonator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:12:46 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/30 08:19:50 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	call_obj(t_frame *frame, t_pars *p)
{
	if (p->type == 3)
		ft_cam(frame, p);
	else if (p->type == 4 || p->type == -4)
		ft_light(frame, p);
	else if ((p->type >= 5 && p->type <= 8) || p->type == 30)
		ft_obj(frame, p);
	else if (p->type == 9)
		ft_transf(p);
}

/*
** size, ambiante, background
*/

void	paramator(t_frame *frame, t_pars *p)
{
	static int	depth[] = {2, 2, 2};
	static void	(*ft[])(t_frame*, t_pars *) = {ft_size, ft_ambiante, ft_back};
	int			i;

	i = -1;
	if (!(ft_strncmp(&(p->f[p->i]), "\"scene\"", 7)))
	{
		if (p->depth != 1)
			ft_error_txt("missing { at beggining of file\n");
		p->i += 7;
	}
	while (++i <= 2)
		if (!(ft_strncmp(&(p->f[p->i]), p->params[i], p->p_len[i])))
		{
			if (p->depth != depth[i])
				ft_error_txt("p0 - missing { or }\n");
			ft[i](frame, p);
		}
	if (p->type == 0)
		paramator2(frame, p);
	else
		call_obj(frame, p);
}

int		jsonator(t_frame *frame, t_pars *p)
{
	p->i = 0;
	p->last_type = 0;
	while (p->f[p->i] && p->depth >= 0)
	{
		if (p->f[p->i] == '{')
			p->depth++;
		else if (p->f[p->i] == '}')
		{
			p->depth--;
			if (p->type != 0)
				p->type = 0;
			if (p->last_type != 0)
				p->last_type = 0;
			if (p->depth < p->l->depth)
				rm_transf(p);
		}
		if (p->f[p->i] == '\"')
			paramator(frame, p);
		p->i++;
	}
	return (1);
}
