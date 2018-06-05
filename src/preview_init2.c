/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preview_init2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:30:53 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/17 16:31:59 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	preview_add2(t_tri *lst, t_object *tmp)
{
	tmp->orig.x = 0;
	tmp->orig.y = 0;
	tmp->orig.z = -500;
	if (tmp->type != 0)
	{
		tmp->data.x = ft_atoi(lst->tab_dir_x);
		tmp->data.y = ft_atoi(lst->tab_dir_y);
		tmp->data.z = ft_atoi(lst->tab_dir_z);
		tmp->data = ft_normalize(tmp->data);
	}
	else
	{
		tmp->data.x = 0;
		tmp->data.y = 0;
		tmp->data.z = 1;
	}
	tmp->color.x = (atof_custom(lst->tab_color_r) / 255.);
	tmp->color.y = (atof_custom(lst->tab_color_g) / 255.);
	tmp->color.z = (atof_custom(lst->tab_color_b) / 255.);
	tmp->indice = (atof_custom(lst->tab_refra) / 100.);
	preview_add3(lst, tmp);
}

void	preview_add3(t_tri *lst, t_object *tmp)
{
	if (tmp->type == 3)
		tmp->r = atof_custom(lst->tab_ray) / 100.;
	else
		tmp->r = ft_atoi(lst->tab_ray);
	tmp->matiere = ft_atoi(lst->tab_matiere);
	tmp->transp = ft_atoi(lst->tab_transp);
	tmp->rug = atof_custom(lst->tab_rug) / 100.;
	tmp->ks = atof_custom(lst->tab_shine) / 100.;
	tmp->reflec = atof_custom(lst->tab_reflec) / 100.;
}
