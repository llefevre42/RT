/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:19:15 by rpinault          #+#    #+#             */
/*   Updated: 2017/12/12 17:57:16 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 5000
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

struct	s_gnl
{
	char			*str;
	int				itm;
	int				fd;
	int				read;
	struct s_gnl	*next;
};
typedef struct s_gnl	t_gnl;

#endif
