/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:44:40 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/21 18:28:26 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static int		my_key_funct6(int keycode, t_frame *frame)
{
	if (keycode == 25 || keycode == 28 || keycode == 26 || keycode == 51)
	{
		reset_filters(frame);
		keycode == 25 ? frame->scene.bw++ : 0;
		keycode == 28 ? frame->scene.sepia++ : 0;
		keycode == 26 ? frame->scene.cartoon++ : 0;
	}
	frame->lst->current_cam = frame->lst->CAM;
	if (frame->lst->current_cam_w == 1)
		frame->lst->cam1 = frame->lst->CAM;
	if (frame->lst->current_cam_w == 2)
		frame->lst->cam2 = frame->lst->CAM;
	if (frame->lst->current_cam_w == 3)
		frame->lst->cam3 = frame->lst->CAM;
	if (frame->lst->current_cam_w == 4)
		frame->lst->cam4 = frame->lst->CAM;
	keycode == 34 ? frame->move_z_tex += 10 : 0;
	keycode == 40 ? frame->move_z_tex -= 10 : 0;
	keycode == 37 ? frame->move_x_tex -= 10 : 0;
	keycode == 38 ? frame->move_x_tex += 10 : 0;
	keycode == 31 ? frame->stretch_tex += 10 : 0;
	keycode == 32 ? frame->stretch_tex -= 10 : 0;
	if (0 == my_key_funct(keycode, frame->lst))
		expose_hook(frame);
	return (0);
}

static int		my_key_funct5(int keycode, t_frame *frame)
{
	t_object	*current;

	current = current_obj(frame->lst);
	if (keycode == 89 && frame->lst->input == 0)
		rotate_obj(ft_vec_create(0, 0, M_PI / 12.), current, current->orig);
	else if (keycode == 92 && frame->lst->input == 0)
		rotate_obj(ft_vec_create(0, 0, -M_PI / 12.), current, current->orig);
	else if (keycode == 91 && frame->lst->input == 0)
		rotate_obj(ft_vec_create(-M_PI / 12., 0, 0), current, current->orig);
	else if (keycode == 87 && frame->lst->input == 0)
		rotate_obj(ft_vec_create(M_PI / 12., 0, 0), current, current->orig);
	else if (keycode == 86 && frame->lst->input == 0)
		rotate_obj(ft_vec_create(0, M_PI / 12., 0), current, current->orig);
	else if (keycode == 88 && frame->lst->input == 0)
		rotate_obj(ft_vec_create(0, -M_PI / 12., 0), current, current->orig);
	return (my_key_funct6(keycode, frame));
}

static int		my_key_funct4(int keycode, t_frame *frame)
{
	t_object *obj;

	obj = frame->scene.object_begin;
	if (keycode == 35)
	{
		ft_bzero(frame->video.map, HEIGHT * WIDTH * 4);
		frame->scene.px++;
	}
	if (keycode == 29)
	{
		while (obj)
		{
			if (frame->scene.check)
				obj->color = obj->color_save;
			else
				obj->color_save = obj->color;
			obj = obj->next;
		}
		frame->scene.check++;
	}
	keycode == 46 ? frame->repeat_tex++ : 0;
	return (my_key_funct5(keycode, frame));
}

static int		my_key_funct3(int keycode, t_frame *frame)
{
	if (keycode == 258)
		CAM.orig = ft_vec_linear(1., CAM.orig, 20.,
				chg_rep_vec(CAM.vue, ft_vec_create(0., -1., 0.)));
	if (keycode == 269 || keycode == 264)
		CAM.orig = ft_vec_linear(1., CAM.orig, 20.,
				chg_rep_vec(CAM.vue, ft_vec_create(0., 1., 0.)));
	if (keycode == 123)
		CAM.orig = ft_vec_linear(1., CAM.orig, 100.,
				chg_rep_vec(CAM.vue, ft_vec_create(-1., 0., 0.)));
	if (keycode == 124)
		CAM.orig = ft_vec_linear(1., CAM.orig, 100.,
				chg_rep_vec(CAM.vue, ft_vec_create(1., 0., 0.)));
	if (keycode == 125)
		CAM.orig = ft_vec_linear(1., CAM.orig, 100.,
				chg_rep_vec(CAM.vue, ft_vec_create(0., 0., 1.)));
	if (keycode == 126)
		CAM.orig = ft_vec_linear(1., CAM.orig, 100.,
				chg_rep_vec(CAM.vue, ft_vec_create(0., 0., -1.)));
	if (keycode == 33)
	{
		ft_bzero(frame->video.map, HEIGHT * WIDTH * 4);
		frame->scene.aa++;
	}
	return (my_key_funct4(keycode, frame));
}

int				my_key_funct2(int keycode, t_frame *frame)
{
	if (keycode == 13)
		CAM.vue = chg_rep_mat(mat_rot_u(3. * M_PI / 180.,
					chg_rep_vec(CAM.vue, ft_vec_create(1., 0., 0.))), CAM.vue);
	if (keycode == 1)
		CAM.vue = chg_rep_mat(mat_rot_u(-3. * M_PI / 180.,
					chg_rep_vec(CAM.vue, ft_vec_create(1., 0., 0.))), CAM.vue);
	if (keycode == 0)
		CAM.vue = chg_rep_mat(mat_rot_u(9. * M_PI / 180.,
					chg_rep_vec(CAM.vue, ft_vec_create(0., 1., 0.))), CAM.vue);
	if (keycode == 2)
		CAM.vue = chg_rep_mat(mat_rot_u(-9. * M_PI / 180.,
					chg_rep_vec(CAM.vue, ft_vec_create(0., 1., 0.))), CAM.vue);
	if (keycode == 12)
		CAM.vue = chg_rep_mat(mat_rot_u(1. * M_PI / 180.,
					chg_rep_vec(CAM.vue, ft_vec_create(0., 0., 1.))), CAM.vue);
	if (keycode == 14)
		CAM.vue = chg_rep_mat(mat_rot_u(-1. * M_PI / 180.,
					chg_rep_vec(CAM.vue, ft_vec_create(0., 0., 1.))), CAM.vue);
	return (my_key_funct3(keycode, frame));
}
