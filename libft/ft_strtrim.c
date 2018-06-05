/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:43:52 by rpinault          #+#    #+#             */
/*   Updated: 2017/05/12 19:18:15 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		j;
	int		nlen;

	i = -1;
	if (s == NULL)
		return (NULL);
	nlen = ft_strlen(s);
	j = nlen;
	while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
		nlen--;
	while (s[--j] == ' ' || s[j] == '\n' || s[j] == '\t')
		nlen--;
	if (nlen <= 0)
		nlen = 0;
	new = ft_strnew(nlen);
	if (new == NULL)
		return (NULL);
	j = 0;
	while (nlen--)
		new[j++] = s[i++];
	return (new);
}
