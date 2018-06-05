/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:38:23 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/16 22:38:11 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void		my_exit(t_frame *frame)
{
	(void)frame;
	exit(1);
}

int				my_key_funct1(int keycode, t_frame *frame)
{
	frame->lst->CAM = frame->lst->current_cam;
	if (keycode == 53)
		my_exit(frame);
	if (keycode == 67)
		FOV += 5;
	if (keycode == 75)
		FOV -= 5;
	if (keycode == 8)
	{
		CAM.type = (CAM.type + 1) % 2;
		if (CAM.type == SPHERE)
			mlx_string_put(MLX, WIN, 0, 0, 0x000000, "COORD SPHERIQUES");
		if (CAM.type == PLAN)
			mlx_string_put(MLX, WIN, 0, 0, 0x000000, "COORD CARTESIENNES");
	}
	if (keycode == 116)
		CAM.orig = ft_vec_linear(1., CAM.orig, 1000.,
				chg_rep_vec(CAM.vue, ft_vec_create(0., 0., -1.)));
	if (keycode == 121)
		CAM.orig = ft_vec_linear(1., CAM.orig, 1000.,
				chg_rep_vec(CAM.vue, ft_vec_create(0., 0., 1.)));
	return (my_key_funct2(keycode, frame));
}
