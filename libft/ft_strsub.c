/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:22:41 by rpinault          #+#    #+#             */
/*   Updated: 2017/05/19 18:20:57 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	i = 0;
	if (!(new = ft_strnew(len)))
		return (NULL);
	if (s)
	{
		while (len--)
		{
			new[i] = s[i + start];
			i++;
		}
	}
	return (new);
}
