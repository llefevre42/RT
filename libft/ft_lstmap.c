/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:09:42 by rpinault          #+#    #+#             */
/*   Updated: 2017/05/29 18:46:08 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new = f(lst);
	begin = new;
	while (lst->next)
	{
		if (!(new->next = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		lst = lst->next;
		new->next = f(lst);
		new = new->next;
	}
	return (begin);
}
