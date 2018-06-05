/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:05:32 by rpinault          #+#    #+#             */
/*   Updated: 2017/05/30 16:48:43 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	*list;

	list = *alst;
	while (list != NULL)
	{
		tmp = list->next;
		del(list->content, list->content_size);
		free(list);
		list = tmp;
	}
	*alst = NULL;
}
