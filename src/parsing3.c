/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:37:58 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/17 14:38:31 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			parsing_object(t_frame *frame, char *line)
{
	char		*tmp;
	t_object	*begin;

	if ((tmp = ft_strstr(line, "TRANSF")))
	{
		if (OBJECT_B == NULL)
			my_error(2);
		begin = OBJECT_B;
		tmp++;
		while ((tmp = ft_strstr(tmp, "TRANSF")))
		{
			if (begin->transf == NULL)
				my_error(2);
			begin = begin->transf;
			tmp++;
		}
		return (parsing_transf(frame, &begin, line));
	}
	parsing_object2(frame, line);
	parsing_object3(frame, line);
	parsing_object4(frame, line, tmp);
}

void			parsing_object4(t_frame *frame, char *line, char *tmp)
{
	if ((tmp = ft_strstr(line, "CYLINDRE")))
	{
		add_cylindre(&OBJECT_B, 0);
		parsing_colb(frame, line);
		if ((tmp = ft_strstr(line, "rayon")))
			OBJECT_B->r = ft_atoi_d(&tmp);
	}
	if ((tmp = ft_strstr(line, "CONE")))
	{
		add_cone(&OBJECT_B, 0);
		parsing_colb(frame, line);
		if ((tmp = ft_strstr(line, "angle")))
			OBJECT_B->r = pow(tan(ft_atoi_d(&tmp) * M_PI / 180.), 2);
	}
	if ((tmp = ft_strstr(line, "PLAN")))
	{
		add_plan(&OBJECT_B, 0);
		parsing_colb(frame, line);
	}
	if ((tmp = ft_strstr(line, "BLANK")))
	{
		add_blank(&OBJECT_B, 0);
		parsing_colb(frame, line);
	}
}
