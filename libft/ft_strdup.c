/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:28:58 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/30 13:14:40 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	l;
	char	*str;

	l = ft_strlen(s1);
	if (!(str = (char *)malloc(l + 1)))
		exit(0);
	return (ft_strcpy(str, s1));
}
