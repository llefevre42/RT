/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 20:39:24 by rpinault          #+#    #+#             */
/*   Updated: 2017/04/22 19:44:44 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t n)
{
	unsigned char	*s;
	int				i;

	i = 0;
	s = (unsigned char*)ptr;
	while (n--)
	{
		s[i] = (unsigned char)value;
		i++;
	}
	return (s);
}
