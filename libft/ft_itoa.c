/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:04:27 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/30 13:14:24 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	itoa_neg(int *n, int *negative, size_t *len)
{
	*negative = 0;
	if (*n < 0)
	{
		*negative = 1;
		*n = -(*n);
	}
	*len = 1 + *negative;
}

char		*ft_itoa(int n)
{
	char	*s;
	size_t	len;
	int		tempn;
	int		negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	itoa_neg(&n, &negative, &len);
	tempn = n;
	while (n >= 10)
	{
		len++;
		n = n / 10;
	}
	s = ft_strnew(len);
	if (s == NULL)
		exit(0);
	while (len--)
	{
		s[len] = tempn % 10 + '0';
		tempn = tempn / 10;
	}
	if (negative == 1)
		s[0] = '-';
	return (s);
}
