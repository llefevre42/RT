/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:25:00 by yhemme            #+#    #+#             */
/*   Updated: 2018/05/30 13:06:47 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		new_text(t_frame *frame, char *name)
{
	t_texture	*new;
	t_texture	*list;

	list = frame->tex;
	if (!(new = malloc(sizeof(t_texture))))
		ft_error(0);
	new->next = NULL;
	if (!(new->image = mlx_xpm_file_to_image(frame->video.mlx,
					name, &new->w, &new->h)))
		error_texture_load(name);
	new->name = name;
	new->img = mlx_get_data_addr(new->image, &new->bpp, &new->sl, &new->e);
	if (!list)
		frame->tex = new;
	else
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
}

t_texture	*get_tex(t_frame *frame, char *name)
{
	t_texture	*current;

	current = frame->tex;
	while (current && strcmp(current->name, name))
		current = current->next;
	return (current);
}

void		check_tex(t_frame *frame)
{
	t_object	*obj;
	t_texture	*tex;

	obj = frame->scene.object_begin;
	tex = frame->tex;
	while (obj)
	{
		while (tex)
			tex = tex->next;
		tex = frame->tex;
		obj = obj->next;
	}
}

void		init_textures(t_frame *frame)
{
	new_text(frame, "./textures/test.xpm");
	new_text(frame, "./textures/pierre.xpm");
}
