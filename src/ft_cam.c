/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:13:21 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/21 14:00:32 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_cam(t_frame *frame, t_pars *p)
{
	static char		*str[] = {"\"rotation\"", "\"point\""};
	static int		len[] = {10, 7};
	static int		depth[] = {3, 3};
	static t_mat	(*ft[])(t_frame*, t_pars *) = {ft_rotation, ft_point};
	int				i;

	i = 2;
	if (!(ft_strncmp(&(p->f[p->i]), "\"origine\"", 9)))
	{
		if (p->depth != 3)
			ft_error_txt("missing { or }\n");
		else
			CAM.orig = ft_vec3(p);
	}
	while (--i >= 0)
		if (!(ft_strncmp(&(p->f[p->i]), str[i], len[i])))
		{
			if (p->depth != depth[i])
				ft_error_txt("missing { or }\n");
			else
				CAM.vue = ft[i](frame, p);
		}
}
