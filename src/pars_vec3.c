/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_vec3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 00:08:07 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/21 14:05:10 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		pars_vec3(char *str)
{
	int		i;
	t_vec	out;

	i = 0;
	out.x = atof_custom(str + i);
	i += ft_isdigispace(str, i);
	out.y = atof_custom(str + i);
	i += ft_isdigispace(str, i);
	out.z = atof_custom(str + i);
	i += ft_isfloat(str, i);
	return (i);
}
