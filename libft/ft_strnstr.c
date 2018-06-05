/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:43:40 by rpinault          #+#    #+#             */
/*   Updated: 2017/05/29 17:13:59 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t j;
	size_t n;

	i = 0;
	j = 0;
	n = ft_strlen(to_find);
	if (n == 0)
		return ((char*)str);
	while (i < len && str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j] && j < n && (i + j) < len)
			{
				if (j == n - 1)
					return ((char*)str + i);
				j++;
			}
		}
		j = 0;
		i++;
	}
	return (NULL);
}
