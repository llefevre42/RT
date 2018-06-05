/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:52:49 by rpinault          #+#    #+#             */
/*   Updated: 2017/05/03 16:28:25 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
	{
		i++;
	}
	return ((const unsigned char)(s1[i]) - (const unsigned char)(s2[i]));
}
