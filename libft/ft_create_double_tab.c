/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_double_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:52:19 by rpinault          #+#    #+#             */
/*   Updated: 2017/12/06 18:03:23 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		**ft_create_double_tab(int n, int m)
{
	int		i;
	double	**tab;

	i = 0;
	if (!(tab = (double **)malloc(sizeof(double*) * n)))
		return (NULL);
	while (i < n)
	{
		if (!(tab[i] = (double *)malloc((sizeof(double) * m))))
			return (NULL);
		i++;
	}
	return (tab);
}
