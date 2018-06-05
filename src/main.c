/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:46:28 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/28 19:04:20 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			init_scene(t_frame *frame)
{
	BG_COLOR = ft_vec_create(0., 0., 0.);
	SCENE.lum_amb = 0.;
	SCENE.lumvec = 0.;
	SCENE.lumvec_dir = ft_vec_create(0., 0., 0.);
	OBJECT_B = NULL;
	LIGHT_B = NULL;
	return ;
}

void			init_variable(t_frame *frame)
{
	WIDTH = 500.;
	HEIGHT = 500.;
	CAM.orig.x = 0.;
	CAM.orig.y = 0.0;
	CAM.orig.z = 0.;
	CAM.dir.x = 0.;
	CAM.dir.y = 0.;
	CAM.dir.z = 1.;
	CAM.vue = ft_mat_id();
	FOV = 30.;
	CAM.type = PLAN;
	frame->scene.px = 0;
	frame->scene.aa = 0;
	frame->scene.check = 0;
	frame->scene.bw = 0;
	frame->scene.sepia = 0;
	frame->scene.cartoon = 0;
	frame->move_x_tex = 0;
	frame->move_z_tex = 0;
	frame->stretch_tex = 49;
	frame->repeat_tex = 0;
	frame->tex = NULL;
	return ;
}

void			usage(void)
{
	exit(1);
}

void			init_windows(t_frame *frame)
{
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 2000, 1300, "RT");
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	MAP = (int*)mlx_get_data_addr(IMG, &VIDEO_B, &VIDEO_S, &VIDEO_E);
	init_textures(frame);
}

int				main(int argc, char **argv)
{
	t_frame			frame;

	(void)argc;
	init_scene(&frame);
	init_variable(&frame);
	parsing_choice(&frame, argv);
	init_windows(&frame);
	start(&frame, argv);
	return (0);
}
