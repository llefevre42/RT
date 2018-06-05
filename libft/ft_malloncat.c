/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallobufcat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:06:17 by thvocans          #+#    #+#             */
/*   Updated: 2018/04/03 17:49:30 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_malloncat(char *in, char *buf, size_t n)
{
	size_t	i;
	ssize_t	j;
	size_t	k;
	char	*out;

	j = -1;
	k = 0;
	i = ft_strlen(in);
	if (!(out = ft_memalloc(i + n + 1)))
		return (NULL);
	if (in)
		while (in[++j])
			out[j] = in[j];
	else
		j++;
	while (n-- > 0)
		out[j++] = buf[k++];
	out[j] = '\0';
	ft_strclr(in);
	ft_strdel(&in);
	return (out);
}
