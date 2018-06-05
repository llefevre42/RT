/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_keycode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 23:40:29 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/24 20:06:21 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		my_key_funct(int keycode, void *param)
{
	t_tri *lst;

	lst = ((t_tri *)param);
	if (keycode == 53)
		exit(0);
	if (lst->input == 1)
	{
		what_a_value(lst->max_u, lst->current_tab, converte_value(keycode));
		add_form(lst);
		lst->preview_in = 1;
		preview_add(lst);
		expose_hook(lst->frame);
		lst->preview_in = 0;
		return (1);
	}
	if (lst->input == 2)
	{
		what_a_value(lst->max_u, lst->current_tab, converte_value(keycode));
		add_light_i(lst);
		return (1);
	}
	return (0);
}
