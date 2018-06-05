/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_choice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 20:07:21 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/17 14:10:14 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		ft_ext_check(char *str, char *ext)
{
	int i;
	int len[2];

	i = 0;
	len[0] = ft_strlen(str) - 1;
	len[1] = ft_strlen(ext) - 1;
	while (len[0] >= 0 && len[1] >= 0 && str[len[0]] == ext[len[1]])
	{
		len[0]--;
		len[1]--;
	}
	if (len[1] < 0)
		return (1);
	return (0);
}

void	parsing_choice(t_frame *frame, char **argv)
{
	int			fd;
	t_object	*tmp;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		my_error(1);
	if (ft_ext_check(argv[1], ".txt") != 0)
		parsing_txt(frame, fd);
	else if (ft_ext_check(argv[1], ".json") != 0)
		parsing_json(frame, fd);
	else
		ft_error_txt("Not a valid txt nor json scene file\n");
	if (!OBJECT_B)
		ft_error_txt("Invalid parsed file\n");
	tmp = OBJECT_B->transf;
	while (tmp)
		tmp = tmp->next_transf;
}
