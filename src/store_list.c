/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:14:11 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/28 17:14:43 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static t_list	*ft_new_store(void **content)
{
	t_list	*new;

	if (!(new = ft_memalloc(sizeof(*new))))
		ft_error_txt("OOM\n");
	new->content = *content;
	return (new);
}

void			ft_store_list(t_frame *frame)
{
	static t_list	*garbage = NULL;
	t_list			*tmp;

	tmp = ft_new_store((void **)(&frame->scene.object_begin));
	tmp->next = garbage;
	garbage = tmp;
	tmp = ft_new_store((void **)(&frame->scene.light_begin));
	tmp->next = garbage;
	garbage = tmp;
	tmp = ft_new_store((void **)(&frame->tex));
	tmp->next = garbage;
	garbage = tmp;
}
