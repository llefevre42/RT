/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:51:50 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/30 13:03:49 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

/*
** 26 params
*/

void	params_list(t_pars *p)
{
	static char	*str[] = {"\"size\"", "\"ambiante\"", "\"background\"",
	"\"cam\"", "\"light\"", "\"plan\"", "\"cone\"", "\"sphere\"",
	"\"cylindre\"", "\"transf\"",
	"\"origine\"", "\"couleur\"", "\"direction\"",
	"\"reflec\"", "\"rayon\"", "\"rug\"", "\"transp\"", "\"brillance\"",
	"\"indice\"", "\"matiere\"", "\"volume\"",
	"\"quad\""};
	static int	len[] = {6, 10, 12, 5, 7, 6, 6, 8, 10, 8, 9, 9, 11, 8, 7, 5, 8,
	11, 8, 9, 8, 6};

	p->params = str;
	p->p_len = len;
}

void	parsing_json(t_frame *frame, int fd)
{
	char	*file;
	t_pars	p;

	file = NULL;
	p.depth = 0;
	p.i = 0;
	p.type = 0;
	p.l = NULL;
	gnb(fd, &file);
	if (file == NULL)
		ft_error_txt("Invalid json file\n");
	p.f = file;
	p.extr = 0;
	ft_transf(&p);
	params_list(&p);
	jsonator(frame, &p);
	if (WIDTH < 5 || HEIGHT < 5 || WIDTH > 1000 || HEIGHT > 1000)
		ft_error_txt("Invalid scene size\n");
	ft_strclr(file);
	ft_strdel(&file);
	ft_memdel((void**)&p.l);
}
