/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:15:00 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/17 18:14:13 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "s_bmp.h"
# include "typedef.h"

struct					s_perlin
{
	double				u;
	double				v;
	double				w;
	double				x;
	double				y;
	double				z;
	int					gx;
	int					gy;
	int					gz;
	double				g000;
	double				g001;
	double				g010;
	double				g011;
	double				g100;
	double				g110;
	double				g111;
	double				g101;
	double				x00;
	double				x01;
	double				x11;
	double				x10;
	double				xy0;
	double				xy1;
	double				xyz;
};

struct					s_video
{
	void				*win;
	void				*mlx;
	double				width;
	double				height;
	void				*img;
	int					*map;
	int					b;
	int					s;
	int					e;
};

struct					s_limit
{
	double				x0;
	double				x1;
	double				y0;
	double				y1;
	double				z0;
	double				z1;
};

struct					s_cam
{
	t_vec				dir;
	t_vec				orig;
	double				fov;
	t_mat				vue;
	int					type;
};

struct					s_object
{
	int					type;
	int					matiere;
	double				rug;
	int					volume;
	t_object			*transf;
	t_object			*next_transf;
	int					transf_type;
	t_vec				orig;
	t_vec				data;
	t_vec				color;
	t_vec				color_save;
	t_quad				quad;
	t_limit				limit;
	double				alpha;
	double				ka;
	double				ks;
	double				kd;
	double				reflec;
	double				transp;
	double				indice;
	double				r;
	t_object			*next;
};

struct					s_light
{
	t_vec				orig;
	t_vec				i;
	t_vec				color;
	t_object			*obj;
	t_light				*next;
};

struct					s_lum
{
	t_vec				lum_d;
	t_vec				lum_s;
	t_vec				lp;
	t_vec				norm;
	double				dist;
};

struct					s_material
{
	double				t1;
	double				t2;
	t_object			*obj1;
	t_object			*obj2;
	t_material			*before;
	t_material			*next;
};

struct					s_ray
{
	t_vec				dir;
	t_vec				orig;
	double				tmin;
	double				tmax;
	double				t;
	double				reflec;
	t_object			*obj_intersect;
	double				indice;
};

struct					s_scene
{
	t_object			*object_begin;
	t_light				*light_begin;
	t_vec				bg_color;
	double				lum_amb;
	double				lumvec;
	t_vec				lumvec_dir;
	unsigned int		px : 1;
	unsigned int		aa : 1;
	unsigned int		check : 1;
	unsigned int		bw : 1;
	unsigned int		sepia : 1;
	unsigned int		cartoon : 1;

};

struct					s_tri
{
	void				*pt_inter_g;
	unsigned int		*inter_g;
	void				*pt_cube_s_grey;
	unsigned int		*cube_s_grey;
	void				*pt_block_xl_red;
	unsigned int		*block_xl_red;
	void				*pt_back;
	unsigned int		*back;
	void				*pt_cube_xs_purple;
	unsigned int		*cube_xs_purple;
	void				*pt_cube_xs_white;
	unsigned int		*cube_xs_white;
	void				*pt_cube_xs_grey;
	unsigned int		*cube_xs_grey;
	void				*pt_cube_xxs_black;
	unsigned int		*cube_xxs_black;
	void				*pt_cube_s_white;
	unsigned int		*cube_s_white;
	void				*pt_cube_s_green;
	unsigned int		*cube_s_green;
	char				*tab_pos_x;
	char				*tab_pos_y;
	char				*tab_pos_z;
	char				*tab_dir_x;
	char				*tab_dir_y;
	char				*tab_dir_z;
	char				*tab_color_r;
	char				*tab_color_g;
	char				*tab_color_b;
	char				*tab_ray;
	char				*tab_transp;
	char				*tab_limite;
	char				*tab_diff;
	char				*tab_shine;
	char				*tab_refra;
	char				*tab_reflec;
	char				*tab_matiere;
	char				*tab_rug;
	float				pos_x;
	float				pos_y;
	float				pos_z;
	float				dir_x;
	float				dir_y;
	float				dir_z;
	float				color_r;
	float				color_g;
	float				color_b;
	float				ray;
	float				transp;
	float				limite;
	float				diff;
	float				reflec;
	float				shine;
	float				refra;
	float				cam_x;
	float				cam_y;
	float				cam_z;
	long int			re;
	void				*pt_p_split;
	unsigned int		*p_split;
	void				*pt_p_form;
	unsigned int		*p_form;
	void				*pt_p_form_add;
	unsigned int		*p_form_add;
	void				*pt_p_form_del;
	unsigned int		*p_form_del;
	void				*pt_p_form_modif;
	unsigned int		*p_form_modif;
	void				*pt_p_light;
	unsigned int		*p_light;
	void				*pt_p_light_add;
	unsigned int		*p_light_add;
	void				*pt_p_light_del;
	unsigned int		*p_light_del;
	void				*pt_p_light_modif;
	unsigned int		*p_light_modif;
	void				*pt_p_file;
	unsigned int		*p_file;
	void				*pt_p_cam;
	unsigned int		*p_cam;
	void				*pt_p_return;
	unsigned int		*p_return;
	void				*pt_p_load1;
	unsigned int		*p_load1;
	void				*pt_p_load2;
	unsigned int		*p_load2;
	void				*pt_p_load3;
	unsigned int		*p_load3;
	void				*pt_p_load4;
	unsigned int		*p_load4;
	void				*pt_p_load5;
	unsigned int		*p_load5;
	void				*pt_p_fleched;
	unsigned int		*p_fleched;
	void				*pt_p_flecheg;
	unsigned int		*p_flecheg;
	void				*pt_p_flecheh;
	unsigned int		*p_flecheh;
	void				*pt_p_flecheb;
	unsigned int		*p_flecheb;
	void				*pt_p_screen;
	unsigned int		*p_screen;
	void				*pt_p_mini_file;
	char				*p_mini_file;
	void				*pt_p_menu_file;
	char				*p_menu_file;
	void				*pt_p_home;
	char				*p_home;
	void				*pt_p_render;
	char				*p_render;
	void				*pt_p_menu_shape;
	char				*p_menu_shape;
	void				*pt_p_menu_form;
	char				*p_menu_form;
	void				*pt_p_menu_cam;
	char				*p_menu_cam;
	void				*pt_p_white_button;
	char				*p_white_button;
	void				*pt_p_grey_button;
	char				*p_grey_button;
	long int			larg_l;
	long int			haut_l;
	t_cam				cam1;
	t_cam				cam2;
	t_cam				cam3;
	t_cam				cam4;
	t_cam				current_cam;
	t_frame				*frame;
	t_frame				*preview;
	t_vec				cam1_o;
	t_vec				cam1_d;
	t_vec				cam2_o;
	t_vec				cam2_d;
	t_vec				cam3_o;
	t_vec				cam3_d;
	t_vec				cam4_o;
	t_vec				cam4_d;
	t_vec				current_cam_o;
	t_vec				current_cam_d;
	int					current_cam_w;
	int					preview_in;
	char				**current_str;
	int					true_split;
	int					current_split;
	int					split;
	int					true_dupli;
	int					current_dupli;
	int					dupli;
	int					input;
	int					max_u;
	char				**current_tab;
	int					*iter;
	int					add_form_who;
	int					modif_form_who;
	int					sous_menu;
	int					lsize;
	char				*map;
	void				*mlx;
	void				*win;
	void				*win2;
	void				*pt_img;
	unsigned int		*img;
	long int			color;
	int					l;
	int					h;
	int					x;
	int					y;
	int					lon;
	int					key;
	int					count_liste;
	int					number_file;
	int					file_load;
	int					current_object;
	int					l_count_liste;
	int					l_number_file;
	int					l_current_object;
	int					l_add_form_who;
	int					augment;
	int					up;
	int					t1;
	int					t2;
	int					t3;
	int					page;
	int					i;
	int					h_swap;
	int					w_swap;
};

struct					s_texture
{
	void				*image;
	char				*img;
	int					w;
	int					h;
	int					bpp;
	int					sl;
	int					e;
	char				*name;
	struct s_texture	*next;
};

struct					s_frame
{
	t_video				video;
	t_cam				cam;
	t_scene				scene;
	t_tri				*lst;
	t_texture			*tex;
	int					move_x_tex;
	int					move_z_tex;
	int					stretch_tex;
	unsigned int		repeat_tex : 1;
};

struct					s_thread_s
{
	int					id;
	pthread_t			thread;
	t_frame				*frame;
};

struct					s_env_color
{
	t_vec	color;
	t_ray	tmp_ray;
	double	transp;
};

struct					s_env_inter
{
	t_light *tmp_light;
	t_ray	light_ray;
	t_vec	p;
	double	pq2;
	t_lum	lum;
	t_light tmp_l;
};

struct					s_env_verif
{
	t_material *mate;
	t_material *begin;
	t_material *extr;
};

struct					s_env_aa
{
	t_ray		ray;
	double		i;
	double		j;
	t_vec		col_tmp;
	t_vec		col;
};

struct					s_env_ray
{
	int			i;
	int			j;
	t_ray		ray;
	t_thread_s	tmp_th;
	t_vec		color;
};

#endif
