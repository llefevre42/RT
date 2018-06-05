/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 00:54:53 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/28 19:04:39 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stddef.h>

void	screenshoot(unsigned int *tab, t_tri *lst)
{
	static t_bmp	h[] = {{0x4d42, 0, 0, 0, 0, 40, 0, 0,
		1, 32, 0, 0, 2835, 2835, 0, 0, 0, 0}};
	int				fd;
	char			*filename;
	char			*str;

	h->offset = offsetof(t_bmp, tab32);
	h->width = lst->WIDTH;
	h->height = -lst->HEIGHT;
	h->raw_bmp_size = lst->WIDTH * lst->HEIGHT * 4;
	h->file_size = h->offset + h->raw_bmp_size;
	str = ft_itoa(time(NULL));
	filename = ft_strjoin(str, ".bmp");
	fd = open(filename, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	free(filename);
	free(str);
	write(fd, &h, h->offset);
	write(fd, (unsigned char *)tab, lst->WIDTH * lst->HEIGHT * 4);
}
