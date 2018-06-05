/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 21:43:52 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/11 02:12:29 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	int				i;

	i = 0;
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	while (n--)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
