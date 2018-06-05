/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 19:46:03 by rpinault          #+#    #+#             */
/*   Updated: 2017/05/12 16:45:25 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*d;
	int				i;

	i = 0;
	d = (unsigned char*)s;
	while (n--)
	{
		if (d[i] == (unsigned const char)c)
			return (d + i);
		i++;
	}
	return (NULL);
}
