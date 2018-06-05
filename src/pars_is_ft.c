/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_is_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 03:04:03 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/11 00:31:56 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		ft_isdigispace(char *str, int i)
{
	int j;

	j = 0;
	while (str[i + j] != ',' && str[i + j] != '\0')
		j++;
	if (str[i + j] == ',')
		j++;
	if (str[i + j] == '\0')
		ft_error_txt("error digispace \\0\n");
	while (ft_isspace(str[i + j]))
		j++;
	return (j);
}

int		ft_isfloat(char *str, int i)
{
	int j;

	j = 0;
	if (str[i + j] == '-' || str[i + j] == '+')
		j++;
	while (ft_isdigit(str[i + j]))
		j++;
	if (str[i + j] == '.')
	{
		j++;
		while (ft_isdigit(str[i + j]))
			j++;
	}
	return (j);
}
