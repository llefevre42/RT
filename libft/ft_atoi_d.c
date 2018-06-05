/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:19:09 by rpinault          #+#    #+#             */
/*   Updated: 2018/02/12 18:38:09 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_atoi_d_2(char ***str, int *i, double *r, double *negatif)
{
	*i = 0;
	*r = 0;
	*negatif = 0;
	while ((**str)[*i] != '\0' && ((**str)[*i] > 57 || (**str)[*i] < 48)
			&& (**str)[*i] != 43 && (**str)[*i] != 45)
		(*i)++;
	if ((**str)[*i] == 43 || (**str)[*i] == 45)
	{
		if ((**str)[*i] == 45)
			*negatif = 1;
		(*i)++;
	}
	while ((**str)[*i] != '\0' && (**str)[*i] <= 57 && (**str)[*i] >= 48)
	{
		*r = ((*r * 10.) + (**str)[*i] - 48);
		(*i)++;
	}
}

double		ft_atoi_d(char **str)
{
	double	r;
	int		i;
	int		j;
	double	negatif;

	r = 0;
	j = 1;
	ft_atoi_d_2(&str, &i, &r, &negatif);
	if ((*str)[i] == '.')
	{
		i++;
		while ((*str)[i] != '\0' && (*str)[i] <= 57 && (*str)[i] >= 48)
		{
			r = r + ((*str)[i] - 48) / pow(10., j);
			i++;
			j++;
		}
	}
	if (negatif == 1)
		r = -r;
	str[0] = &(str[0][i]);
	return (r);
}
