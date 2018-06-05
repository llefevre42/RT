/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 20:12:38 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/30 13:05:31 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void		parsing_light(t_frame *frame, char *line)
{
	char		*tmp;

	add_light(frame);
	if ((tmp = ft_strstr(line, "origine")))
		LIGHT_B->orig = ft_vec_create(ft_atoi_d(&tmp)
				, ft_atoi_d(&tmp), ft_atoi_d(&tmp));
	if ((tmp = ft_strstr(line, "lum")))
	{
		LIGHT_B->i.x = ft_atoi_d(&tmp);
		LIGHT_B->i.y = ft_atoi_d(&tmp);
		LIGHT_B->i.z = ft_atoi_d(&tmp);
	}
	if ((tmp = ft_strstr(line, "couleur")))
	{
		LIGHT_B->color.x = ft_atoi_d(&tmp);
		LIGHT_B->color.y = ft_atoi_d(&tmp);
		LIGHT_B->color.z = ft_atoi_d(&tmp);
	}
	if ((tmp = ft_strstr(line, "affichage 1")))
	{
		add_light_object(&OBJECT_B, LIGHT_B->orig, LIGHT_B->color);
		if ((tmp = ft_strstr(line, "rayon")))
			OBJECT_B->r = ft_atoi_d(&tmp);
	}
}

static void		parsing_scene(t_frame *frame, char *line)
{
	char		*tmp;

	if ((tmp = ft_strstr(line, "WIDTH")))
		frame->video.width = ft_atoi_d(&tmp);
	if ((tmp = ft_strstr(line, "HEIGHT")))
		frame->video.height = ft_atoi_d(&tmp);
	if ((tmp = ft_strstr(line, "FOV")))
		frame->cam.fov = ft_atoi_d(&tmp);
	if ((tmp = ft_strstr(line, "AMBIANTE")))
		SCENE.lum_amb = ft_atoi_d(&line);
	if ((tmp = ft_strstr(line, "LUMDIR")))
	{
		SCENE.lumvec = ft_atoi_d(&line);
		SCENE.lumvec_dir.x = ft_atoi_d(&tmp);
		SCENE.lumvec_dir.y = ft_atoi_d(&tmp);
		SCENE.lumvec_dir.z = ft_atoi_d(&tmp);
	}
	if ((tmp = ft_strstr(line, "BACKGROUND")))
	{
		BG_COLOR.x = ft_atoi_d(&tmp);
		BG_COLOR.y = ft_atoi_d(&tmp);
		BG_COLOR.z = ft_atoi_d(&tmp);
	}
	if (WIDTH < 5 || HEIGHT < 5 || HEIGHT > 1000 || WIDTH > 1000)
		ft_error(0);
}

static void		parsing_cam(t_frame *frame, char *line)
{
	char		*tmp;
	t_vec		vec;

	if ((tmp = ft_strstr(line, "CAM")))
	{
		if ((tmp = ft_strstr(line, "origine")))
		{
			CAM.orig.x = ft_atoi_d(&tmp);
			CAM.orig.y = ft_atoi_d(&tmp);
			CAM.orig.z = ft_atoi_d(&tmp);
		}
		if ((tmp = ft_strstr(line, "rotation")))
			CAM.vue = mat_rot_u(ft_atoi_d(&tmp) * M_PI / 180.,
					ft_normalize(ft_vec_create(ft_atoi_d(&tmp),
							ft_atoi_d(&tmp), ft_atoi_d(&tmp))));
	}
	if ((tmp = ft_strstr(line, "point")))
	{
		vec = ft_normalize(ft_vec_create(ft_atoi_d(&tmp) - CAM.orig.x,
			ft_atoi_d(&tmp) - CAM.orig.y, ft_atoi_d(&tmp) - CAM.orig.z));
		CAM.vue = mat_rot_u(acos(ft_vec_dot(ft_vec_create(0., 0., -1.),
			vec)), ft_normalize(ft_vec_cross(ft_vec_create(0., 0., -1.),
			vec)));
	}
}

void			parsing_txt(t_frame *frame, int fd)
{
	char		*line;
	char		*tmp;

	line = NULL;
	while (gnl(fd, &line) == 1)
	{
		parsing_scene(frame, line);
		parsing_cam(frame, line);
		if ((tmp = ft_strstr(line, "LIGHT")))
			parsing_light(frame, line);
		parsing_object(frame, line);
		free(line);
	}
	free(line);
	close(fd);
	return ;
}
