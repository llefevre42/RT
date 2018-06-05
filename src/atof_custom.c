/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof_custom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:08:11 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/21 13:57:32 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double	atof_custom(char *str)
{
	int		i;
	double	res;
	double	div;
	int		tmp;

	i = 0;
	res = 0;
	div = 10;
	tmp = 0;
	if (str[i] == '-' && ++i)
		tmp = 1;
	while (ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i++] - '0';
	}
	if (str[i] == '.' && ++i)
		while (ft_isdigit(str[i]))
		{
			res += ((str[i] - '0') / div);
			div *= 10;
			i++;
		}
	return ((tmp == 1 ? res * -1 : res));
}
