/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:14:02 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/21 14:35:25 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_loopiloop(t_frame *frame, t_pars *p, int i)
{
	if (i == 0)
		LIGHT_B->orig = ft_vec3(p);
	else if (i == 1)
		LIGHT_B->color = ft_vec3(p);
	else if (i == 2)
		LIGHT_B->i = ft_vec3(p);
	else if (i == 3 && (1 == (int)ft_one_double(p)))
	{
		add_light_object(&OBJECT_B, LIGHT_B->orig, LIGHT_B->color);
		LIGHT_B->obj = OBJECT_B;
	}
}

void		ft_light(t_frame *frame, t_pars *p)
{
	static char	*str[] = {"\"origine\"", "\"couleur\"", "\"lum\"",
		"\"affichage\""};
	static int	len[] = {9, 7, 5, 11};
	static int	depth[] = {3, 3, 3, 3};
	int			i;

	i = 4;
	if (p->type == 4)
	{
		add_light(frame);
		p->type = -4;
	}
	while (--i >= 0)
		if (!(ft_strncmp(&(p->f[p->i]), str[i], len[i])))
		{
			if (p->depth < depth[i])
				ft_error_txt("missing { or }\n");
			else
				ft_loopiloop(frame, p, i);
		}
}
