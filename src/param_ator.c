/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_ator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:42:01 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/21 16:42:22 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

/*
** extrude, blank, direct, direct_dir
*/

void	paramator6(t_frame *frame, t_pars *p)
{
	if (!(ft_strncmp(&(p->f[p->i]), "\"extrude\"", 9)))
	{
		if (p->depth < 4 || !p->l->o)
			ft_error_txt("bad extrude parameter\n");
		p->l->o->transf_type = (int)ft_one_double(p);
	}
	if (!(ft_strncmp(&(p->f[p->i]), "\"blank\"", 7)))
	{
		if (p->depth < 3)
			ft_error_txt("bad blank parameter\n");
		p->type = 30;
	}
	if (!(ft_strncmp(&(p->f[p->i]), "\"direct\"", 16)))
	{
		if (p->depth < 3)
			ft_error_txt("bad directional parameter\n");
		frame->scene.lumvec = ft_one_double(p);
		frame->scene.lumvec_dir = ft_vec3(p);
	}
	if (!(ft_strncmp(&(p->f[p->i]), "\"direct_dir\"", 16)))
	{
		if (p->depth < 3)
			ft_error_txt("bad directional dir parameter\n");
		frame->scene.lumvec_dir = ft_vec3(p);
	}
}

/*
** limit, lum, angle
*/

void	paramator5(t_pars *p)
{
	if (!(ft_strncmp(&(p->f[p->i]), "\"limit\"", 7)))
	{
		if (p->depth < 3)
			ft_error_txt("Bad limit parameter\n");
		ft_limit(p);
	}
	if (!(ft_strncmp(&(p->f[p->i]), "\"lum\"", 5)))
	{
		if (p->depth < 3)
			ft_error_txt("Bad lum parameter\n");
		ft_lum(p);
	}
	if (!(ft_strncmp(&(p->f[p->i]), "\"angle\"", 7)))
	{
		if (p->depth < 3 || !p->l->o)
			ft_error_txt("bad angle parameter\n");
		p->l->o->r = pow(tan(ft_one_double(p) * M_PI / 180.), 2);
	}
}

/*
** reflec, rayon, rug, transp, brillance, indice, matiere, volume quad
*/

void	paramator4(t_pars *p, void **var)
{
	int			i;
	double		*db;
	int			*integer;

	i = 12;
	while (++i <= 20)
		if (i <= 18 && !(ft_strncmp(&(p->f[p->i]), p->params[i], p->p_len[i]))
			&& p->depth == p->l->depth + 1)
		{
			db = var[i - 10];
			if (db == NULL)
				ft_error_txt("check double value parameter\n");
			*db = ft_one_double(p);
		}
		else if (!(ft_strncmp(&(p->f[p->i]), p->params[i], p->p_len[i])))
			if (p->depth == p->l->depth + 1)
			{
				integer = var[i - 10];
				if (integer == NULL)
					ft_error_txt("check integer value parameter\n");
				*integer = (int)ft_one_double(p);
			}
	if (!(ft_strncmp(&(p->f[p->i]), p->params[21], p->p_len[21]))
			&& p->depth == p->l->depth + 1)
		ft_quad_obj(p);
}

/*
** origine, couleur, direction
*/

void	paramator3(t_pars *p)
{
	void		**var;
	int			i;
	t_vec		*vec;

	i = 9;
	if (p->last_type < 3)
		ft_error_txt("p->last_type < 3\n");
	if (p->l->o == NULL)
		return ;
	var = ft_voidstar(p);
	while (++i <= 12)
		if (!(ft_strncmp(&(p->f[p->i]), p->params[i], p->p_len[i])))
			if (p->depth == p->l->depth + 1)
			{
				if ((vec = var[i - 10]) == NULL)
					ft_error_txt("Error with origin color or direction\n");
				*vec = ft_vec3(p);
				if (i == 12)
					*vec = ft_normalize(*vec);
			}
	paramator4(p, var);
	paramator5(p);
	free(var);
}

/*
** cam, light, plan, cone, sphere, cylindre, transf
*/

void	paramator2(t_frame *frame, t_pars *p)
{
	static int	depth[] = {0, 0, 0, 2, 2, 2, 2, 2, 2, 3};
	int			i;

	i = 2;
	while (++i <= 9)
		if (!(ft_strncmp(&(p->f[p->i]), p->params[i], p->p_len[i])))
		{
			if (p->depth < depth[i])
				ft_error_txt("p2 - missing { or }\n");
			if (i < 9 && (p->depth != depth[i] + (2 * p->extr)))
				ft_error_txt("transf error\n");
			p->type = i;
			return ;
		}
	if (p->depth > 2)
		paramator3(p);
	if (p->depth > 2)
		paramator6(frame, p);
}
