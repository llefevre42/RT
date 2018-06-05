/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:12:14 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/16 23:02:45 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gnb.h>

static int		ft_block(t_gnb *var, char **line)
{
	int i;

	i = -1;
	if (!var->str && var->position == 0)
		return (-1);
	if (var->str[var->position] == '\0')
	{
		ft_strdel(&var->str);
		var->end = 1;
		return (0);
	}
	while (var->str[var->position + ++i] != '\0')
		if (var->str[var->position + i] == '\0')
			break ;
	if (var->str[var->position + i] != '\0')
		i++;
	if (var->str[var->position + i] == ',')
		i++;
	if ((*line = ft_strsub(var->str, var->position, i)) == NULL)
		return (-1);
	var->position += i;
	return (1);
}

int				gnb(const int fd, char **line)
{
	static t_gnb	var = {NULL, 0, 0};
	char			buf[BUFF_SIZE];
	ssize_t			qty;
	int				i;

	if (line == NULL || fd < 0)
		return (-1);
	ft_strdel(line);
	while ((qty = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		i = -1;
		while (++i < qty)
			if (buf[i] == 0)
				return (-1);
		var.str = ft_malloncat(var.str, buf, (size_t)qty);
	}
	if (var.end == 1)
		return (0);
	return (ft_block(&var, line));
}
