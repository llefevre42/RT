/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:30:07 by rpinault          #+#    #+#             */
/*   Updated: 2017/05/29 17:13:50 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	n = ft_strlen(to_find);
	if (n == 0)
		return ((char*)str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j] && j < n)
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
