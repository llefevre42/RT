/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 13:44:38 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/21 15:21:39 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

char			*ft_read_i(char *av, t_tri *lst)
{
	int		fd;
	char	buf[BUFSIZE + 1];
	char	*out;
	ssize_t	re;

	if ((strcmp(av, "Makefile") == 0) || (strcmp(av, "random") == 0))
		ft_error(0);
	fd = open(av, O_RDONLY);
	out = NULL;
	if (fd == -1)
		return (NULL);
	while ((re = read(fd, &buf, BUFSIZE)) > 0)
	{
		lst->re = re;
		out = ft_malloncat(out, buf, re);
	}
	return (out);
}

unsigned int	*tri_bmp(unsigned char *text, unsigned int *swap)
{
	int		i;
	int		j;
	t_bmp	*data;

	i = 0;
	j = 0;
	data = (t_bmp*)text;
	if (data->bpp == 32)
	{
		j = -1;
		data->tab32 = (unsigned int*)(text + data->offset);
		while (++j < data->height)
		{
			i = -1;
			while (++i < data->width)
				swap[((data->height - j - 1) * data->width) + i] = data->tab32\
				[(data->width * j) + i];
		}
	}
	else
		tri_bmp2(text, swap, data);
	return (swap);
}

void			tri_bmp2(unsigned char *text, unsigned int *swap, t_bmp *data)
{
	int		k;
	int		l;
	int		i;
	int		j;

	k = 0;
	l = 0;
	i = 0;
	j = 0;
	data->tab8 = (unsigned char*)(text + data->offset);
	j = -1;
	while (++j < data->height)
	{
		i = -1;
		k = 0;
		while (++i < data->width)
		{
			swap[((data->height - j - 1) * data->width) + i] = \
			(*((int*)&data->tab8[(data->width * k) + l])) & 0xFFFFFF;
			l += data->bpp / 8;
		}
		k += data->bpp / 8;
	}
}
