/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 18:03:24 by rpinault          #+#    #+#             */
/*   Updated: 2018/01/24 20:15:31 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_signe(double a)
{
	if (a == 0)
		return (0);
	if (a / fabs(a) >= 0)
		return (1);
	else
		return (-1);
}

int			ft_meme_signe(double a, double b)
{
	if (ft_signe(a) == 0 || ft_signe(b) == 0 || ft_signe(a) == ft_signe(b))
		return (1);
	else
		return (0);
}
