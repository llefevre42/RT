/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:34:19 by rpinault          #+#    #+#             */
/*   Updated: 2017/05/29 18:03:57 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t lendst;
	size_t lensrc;

	i = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (n >= lendst + 1)
	{
		while ((dst[i] != '\0' && i < (n - 1)))
			i++;
		while (*src && i < (n - 1))
		{
			dst[i] = *src;
			i++;
			src++;
		}
		dst[i] = '\0';
		return (lensrc + lendst);
	}
	return (lensrc + n);
}
