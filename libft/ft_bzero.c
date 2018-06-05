/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 21:07:26 by rpinault          #+#    #+#             */
/*   Updated: 2017/11/21 18:00:43 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tab;
	int				i;

	i = 0;
	tab = (unsigned char*)s;
	while (n--)
	{
		tab[i] = (unsigned char)0;
		i++;
	}
}
