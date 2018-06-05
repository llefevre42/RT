/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:01:38 by rpinault          #+#    #+#             */
/*   Updated: 2017/11/08 18:04:04 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fill_new(t_list *new, void const *content, size_t content_size)
{
	new->content = ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
}

static void		empty_new(t_list *new)
{
	new->content = NULL;
	new->content_size = 0;
}

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		if (content)
		{
			new->content = (void*)malloc(content_size);
			if (new->content)
				fill_new(new, content, content_size);
			else
			{
				free((void*)new);
				return (NULL);
			}
		}
		else
			empty_new(new);
		new->next = NULL;
	}
	return (new);
}
