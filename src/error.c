/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:32:35 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/15 16:35:47 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	my_error(int i)
{
	if (i == 1)
		ft_putstr("No file\n");
	else if (i == 2)
		ft_putstr("Parsing 'transf' error.\n");
	exit(1);
}

void	error_texture_load(char *name)
{
	ft_putstr("ERROR : Can't load texture ");
	ft_putstr(name);
	ft_putstr(" pls make sure the file is in the textures folder with");
	ft_putendl(" the good name and try again");
	exit(0);
}
