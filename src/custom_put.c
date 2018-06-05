/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:26:15 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/28 19:04:09 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

char	converte_value(int c)
{
	if (c == 82)
		return ('0');
	if (c == 83)
		return ('1');
	if (c == 84)
		return ('2');
	if (c == 85)
		return ('3');
	if (c == 86)
		return ('4');
	if (c == 87)
		return ('5');
	if (c == 88)
		return ('6');
	if (c == 89)
		return ('7');
	if (c == 91)
		return ('8');
	if (c == 92)
		return ('9');
	if (c == 51)
		return ('x');
	return ('o');
}

void	what_a_value(int max, char **tab, char c)
{
	if (c >= 48 && c <= 57)
	{
		if ((*tab)[1] != 32)
			(*tab)[2] = c;
		else if ((*tab)[0] != 32)
			(*tab)[1] = c;
		else
			(*tab)[0] = c;
	}
	if (c == 'x')
	{
		if ((*tab)[2] != 32)
			(*tab)[2] = ' ';
		else if ((*tab)[1] != 32)
			(*tab)[1] = ' ';
		else
			(*tab)[0] = ' ';
	}
	tab = freetoa(max, tab);
}

char	**freetoa(int max, char **tab)
{
	char *tmp;

	if (ft_atoi((*tab)) > max)
	{
		tmp = ft_itoa(max);
		free(*tab);
		(*tab) = tmp;
	}
	else
		tmp = NULL;
	return (tab);
}
