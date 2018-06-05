/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:09:48 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/16 19:34:25 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		expose_hook(t_frame *frame)
{
	int			haut;
	int			larg;

	if (frame->lst->preview_in == 1)
	{
		ray_multi_thread((void*)frame->lst->preview);
		mlx_put_image_to_window(frame->lst->preview->video.mlx, \
				frame->lst->preview->video.win, \
				frame->lst->preview->video.img, 375, 180);
	}
	if (frame->lst->true_split == 0 && frame->lst->preview_in == 0)
	{
		ray_multi_thread((void*)frame);
		haut = ((1000 - frame->video.width) / 2);
		larg = ((1000 - frame->video.height) / 2);
		mlx_put_image_to_window(MLX, WIN, IMG, 950 + haut, 149 + larg);
	}
	expose_hook2(frame);
}

void		expose_hook2(t_frame *frame)
{
	t_cam		tmp1;
	t_cam		tmp2;

	tmp1 = CAM;
	tmp2 = CAM;
	if (frame->lst->true_split == 1 && frame->lst->preview_in == 0)
	{
		tmp1 = CAM;
		tmp2 = CAM;
		if (frame->lst->current_cam_w == 1)
		{
			CAM = tmp1;
			CAM = tmp2;
		}
		else
			CAM = frame->lst->cam1;
		ray_multi_thread((void*)frame);
		mlx_put_image_to_window(MLX, WIN, IMG, 950, 149);
		expose_hook0(frame, tmp1, tmp2);
	}
	expose_hook3(frame, tmp1, tmp2);
}

void		expose_hook0(t_frame *frame, t_cam tmp1, t_cam tmp2)
{
	if (frame->lst->current_cam_w == 2)
	{
		CAM = tmp1;
		CAM = tmp2;
	}
	else
		CAM = frame->lst->cam2;
	ray_multi_thread((void*)frame);
	mlx_put_image_to_window(MLX, WIN, IMG, 950, 649);
	CAM = tmp1;
	CAM = tmp2;
}

void		*expose_hook3(t_frame *frame, t_cam tmp1, t_cam tmp2)
{
	if (frame->lst->true_split == 2 && frame->lst->preview_in == 0)
	{
		tmp1 = CAM;
		tmp2 = CAM;
		if (frame->lst->current_cam_w == 1)
		{
			CAM = tmp1;
			CAM = tmp2;
		}
		else
			CAM = frame->lst->cam1;
		ray_multi_thread((void*)frame);
		mlx_put_image_to_window(MLX, WIN, IMG, 950, 149);
		if (frame->lst->current_cam_w == 2)
		{
			CAM = tmp1;
			CAM = tmp2;
		}
		else
			CAM = frame->lst->cam2;
		ray_multi_thread((void*)frame);
		mlx_put_image_to_window(MLX, WIN, IMG, 1450, 149);
		expose_hook4(frame, tmp1, tmp2);
	}
	return (IMG);
}

void		expose_hook4(t_frame *frame, t_cam tmp1, t_cam tmp2)
{
	if (frame->lst->current_cam_w == 3)
	{
		CAM = tmp1;
		CAM = tmp2;
	}
	else
		CAM = frame->lst->cam3;
	ray_multi_thread((void*)frame);
	mlx_put_image_to_window(MLX, WIN, IMG, 950, 649);
	if (frame->lst->current_cam_w == 4)
	{
		CAM = tmp1;
		CAM = tmp2;
	}
	else
		CAM = frame->lst->cam4;
	ray_multi_thread((void*)frame);
	mlx_put_image_to_window(MLX, WIN, IMG, 1450, 649);
	CAM = tmp1;
	CAM = tmp2;
}
