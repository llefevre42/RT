/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:19:09 by rpinault          #+#    #+#             */
/*   Updated: 2017/05/30 16:27:50 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	r;
	int i;
	int negatif;

	r = 0;
	negatif = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
	str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			negatif = 1;
		i++;
	}
	while (str[i] != '\0' && str[i] <= 57 && str[i] >= 48)
	{
		r = ((r * 10) + str[i] - 48);
		i++;
	}
	if (negatif == 1)
		r = -r;
	return (r);
}
