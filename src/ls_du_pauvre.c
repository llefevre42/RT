/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_du_pauvre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:47:25 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/21 21:46:40 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <sys/types.h>
#include <dirent.h>

char	*ls(t_tri *lst, int nb)
{
	DIR					*dirp;
	struct dirent		*file;
	int					i;

	i = 0;
	lst->number_file = 0;
	lst->l = lst->l;
	if (!(dirp = opendir("./map")))
		ft_error(1);
	while ((file = readdir(dirp)))
	{
		if ((file->d_name)[0] != '.')
		{
			lst->number_file++;
			i++;
		}
		if (i == nb)
		{
			(void)closedir(dirp);
			return (file->d_name);
		}
	}
	(void)closedir(dirp);
	return (file->d_name);
}

char	*afich(char *str)
{
	int i;

	i = 6;
	if (str[6])
	{
		while (str[i] != '\0')
		{
			if (i == 6 || i == 7 || i == 8)
				str[i] = '.';
			else
				str[i] = ' ';
			i++;
		}
	}
	return (str);
}
