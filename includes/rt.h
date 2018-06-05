/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:45:37 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/28 16:56:21 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <libft.h>
# include <limits.h>
# include <pthread.h>
# include <sys/timeb.h>
# include <time.h>
# include <stdlib.h>

# include "typedef.h"
# include "gnb.h"
# include "json.h"
# include "struct.h"

# define BUFSIZE 3000000
# define LARG 2000
# define HAUT 1300
# define WIDTH frame->video.width
# define HEIGHT frame->video.height
# define CAM frame->cam
# define FOV frame->cam.fov
# define BG_COLOR frame->scene.bg_color
# define MLX frame->video.mlx
# define WIN frame->video.win
# define IMG frame->video.img
# define MAP frame->video.map
# define VIDEO_B frame->video.b
# define VIDEO_S frame->video.s
# define VIDEO_E frame->video.e
# define SCENE frame->scene
# define OBJECT_B frame->scene.object_begin
# define LIGHT_B frame->scene.light_begin
# define OBJ_I ray->obj_intersect
# define Q object->quad.q
# define U object->quad.u
# define PIXEL_LVL 5

enum
{
	PLAN, SPHERE, CYLINDRE, CONE, QUAD, LIGHT, BLANK
};

enum
{
	NORMAL, EAU, PIERRE
};

enum
{
	EXTRUSION, UNION, INTERSECTION, EXTRUSION_CONVX, EXTRUSION_INV
};

void			obj_to_mate(t_ray *ray, t_object *obj, \
		t_material **extr, t_vec tv);
t_material		*obj_inter_volume(t_material *src, t_material *extr);
t_material		*obj_extr(t_material *src, t_material *extr, int volume);
void			remove_all_mate(t_material *src);
void			add_mate(t_material *ne, t_material **src);
t_material		*create_mate(double t1, double t2, \
		t_object *obj1, t_object *obj2);
double			smooth_noise_3d(double x_pos, \
double			y_pos, double z_pos, double res);
t_mat			mat_rot_x(double theta);
t_mat			mat_rot_y(double theta);
t_mat			mat_rot_z(double theta);
t_mat			mat_rot_u(double theta, t_vec u);
t_vec			chg_rep_vec(t_mat q, t_vec c);
t_mat			chg_rep_mat(t_mat q, t_mat c);
void			parsing(t_frame *frame, char **argv);
void			parsing_object(t_frame *frame, char *line);
void			parsing_object2(t_frame *frame, char *line);
void			parsing_object3(t_frame *frame, char *line);
void			parsing_object4(t_frame *frame, char *line, char *tmp);
void			parsing_transf(t_frame *frame, \
		t_object **dst, char *line);
void			parsing_colb(t_frame *frame, char *line);
void			parsing_colb2(t_frame *frame, char *line, char *tmp);
void			my_error(int i);
void			init_light(t_light *l);
void			init_ray(t_ray *ray);
void			init_lum(t_lum *lum);
void			init_object(t_object *object);
void			init_object2(t_object *object);
void			add_object(t_object **dst, t_object *p_object, int type);
void			add_light_object(t_object **dst, t_vec o, t_vec c);
void			add_light(t_frame *f);
void			add_sphere(t_object **dst, int type);
void			add_cylindre(t_object **dst, int type);
void			add_cone(t_object **dst, int type);
void			add_quad(t_object **dst, int type);
void			add_plan(t_object **dst, int type);
void			add_blank(t_object **dst, int type);
void			rotate_obj(t_vec r, t_object *ob, t_vec ori);
void			verify_intersect(t_ray *ray, t_object *obj, t_vec t12);
t_vec			gradient_quad(t_object *object, t_vec p);
t_vec			intersect_quad(t_ray *ray, t_object *object);
t_vec			intersect_sphere(t_ray *ray, t_object *obj);
t_vec			intersect_cyl(t_ray *ray, t_object *obj);
t_vec			intersect_cone(t_ray *ray, t_object *obj);
t_vec			intersect_plan(t_ray *ray, t_object *obj);
t_vec			intersect_color(t_frame *frame, t_ray *ray);
void			find_intersect(t_frame *frame, t_ray *ray);
t_vec			intersect(t_ray *ray, t_frame *frame);
int				my_key_funct1(int keycode, t_frame *frame);
int				my_key_funct2(int keycode, t_frame *frame);
void			expose_hook(t_frame *frame);
void			expose_hook2(t_frame *frame);
void			expose_hook0(t_frame *frame, t_cam tmp1, t_cam tmp2);
void			*expose_hook3(t_frame *frame, t_cam tmp1, t_cam tmp2);
void			expose_hook4(t_frame *frame, t_cam tmp1, t_cam tmp2);
void			map_clear(t_frame *frame);
void			pixel_to_map(t_frame *frame, int i, int j, int hex);
t_ray			ray_pixel_to_scene(double i, \
		double j, t_frame *frame);
void			*raytracer(void *sthread);
void			ray_multi_thread(t_frame *frame);
void			usage(void);
int				start(t_frame *frame, char **str);
void			ft_error(int i);
void			text_form(t_tri *lst);
void			text_light_add(t_tri *lst);
void			text_light_del(t_tri *lst);
void			text_light_modif(t_tri *lst);
void			text_file(t_tri *lst);
void			text_flecheg(t_tri *lst);
void			text_flecheb(t_tri *lst);
void			text_home(t_tri *lst);
void			text_render(t_tri *lst);
void			text_mini_file(t_tri *lst);
void			text_menu_file(t_tri *lst);
void			text_menu_form(t_tri *lst);
void			text_menu_shape(t_tri *lst);
void			text_menu_cam(t_tri *lst);
void			text_grey_button(t_tri *lst);
void			text_white_button(t_tri *lst);
unsigned int	*tri_bmp(unsigned char *text, unsigned int *swap);
void			tri_bmp2(unsigned char *text, unsigned int *swap, t_bmp *data);
char			*ft_read_i(char *av, t_tri *lst);
void			clique_cam(t_tri *lst, int x, int y);
void			clique_cam2(t_tri *lst, int x, int y);
void			clique_cam3(t_tri *lst, int x, int y);
void			reset(char *add);
void			menu_cam(t_tri *l);
void			menu_cam2(t_tri *l);
void			menu_split(t_tri *lst);
void			file_manag(t_tri *lst, char *str);
void			source_bidon(t_tri *lst);
void			clique_on_file(t_tri *lst, int x, int y);
void			clique_on_file2(t_tri *lst, int x, int y);
void			clique_on_file3(t_tri *lst, int x, int y, int i);
void			clique_modif(t_tri *lst, int x, int y);
void			clique_modif2(t_tri *lst, int x, int y, t_object *obj);
void			clique_modif3(t_tri *lst, int x, int y, t_object *obj);
void			clique_modif4(t_tri *lst, int x, int y, t_object *obj);
void			clique_modif5(t_tri *lst, int x, int y, t_object *obj);
void			clique_modif6(t_tri *lst, int x, int y, t_object *obj);
void			clique_modif7(t_tri *lst, int x, int y, t_object *obj);
void			clique_add(t_tri *lst, int x, int y);
void			clique_add_2(t_tri *lst, int x, int y);
void			clique_add_3(t_tri *lst, int x, int y);
void			clique_add_4(t_tri *lst, int x, int y);
void			clique_add_5(t_tri *lst, int x, int y);
void			clique_add_6(t_tri *lst, int x, int y);
void			clique_add_7(t_tri *lst);
void			clique_add_8(t_tri *lst, int x, int y);
void			clique_add_light(t_tri *lst, int x, int y);
void			clique_add_light2(t_tri *lst, int x, int y);
void			clique_add_light3(t_tri *lst, int x, int y);
void			clique_add_light4(t_tri *lst, int x, int y);
void			clique_modif_light(t_tri *lst, int x, int y);
void			clique_modif_light2(t_tri *lst, int x, \
		int y, t_light *obj);
char			converte_value(int c);
void			what_a_value(int max, char **tab, char c);
void			init_val(t_tri *lst);
void			event_light(t_tri *lst, int x, int y);
void			event_light_40(t_tri *lst, int x, int y);
void			event_light_41(t_tri *lst, int x, int y);
void			event_light_41_2(t_tri *lst, int x, int y);
void			event_light_42(t_tri *lst, int x, int y);
void			event_light_43(t_tri *lst, int x, int y);
void			event_form(t_tri *lst, int x, int y);
void			event_form_20(t_tri *lst, int x, int y);
void			event_form_20_2(t_tri *lst, int x, int y);
void			event_form_21(t_tri *lst, int x, int y);
void			event_form_22(t_tri *lst, int x, int y);
void			event_form_23(t_tri *lst, int x, int y);
void			event_form_24(t_tri *lst, int x, int y);
void			event_form_24_2(t_tri *lst, int x, int y);
int				my_key_funct(int keycode, void *param);
void			menu_form(t_tri *lst);
void			add_form(t_tri *lst);
void			add_form2(t_tri *lst);
void			add_form3(t_tri *lst);
void			modif_form(t_tri *lst);
void			modif_form2(t_tri *lst, t_object *obj);
void			del_form(t_tri *lst);
void			menu_light(t_tri *lst);
void			menu_file(t_tri *lst);
void			menu_file2(t_tri *lst, int c, int i);
void			menu_file3(t_tri *lst, int c, int i);
void			menu_file4(t_tri *lst, int c, int i);
void			add_light_i(t_tri *lst);
void			add_light_i2(t_tri *lst);
void			del_light(t_tri *lst);
void			modif_light(t_tri *lst);
void			modif_light2(t_tri *lst, t_light *obj);
void			erase_menu(t_tri *lst);
void			generation(t_tri *lst);
int				put_cub(t_tri *lst);
int				put_cub_bis(int x, int y, t_tri *lst);
unsigned int	*put_in_img(int x, int y, \
		unsigned int *img, t_tri *lst);
void			bases(t_tri *lst);
void			main_menu(t_tri *lst);
int				put_mousse(int keycode, int x, int y, void *param);
char			*ft_malloncat(char *in, char *buf, size_t n);
void			screenshoot(unsigned int *tab, t_tri *lst);
t_object		*current_obj(t_tri *lst);
void			count_liste(t_tri *lst);
char			*ls(t_tri *lst, int nb);
char			*afich(char *str);
int				main(int argc, char **argv);
void			init_scene(t_frame *frame);
void			init_variable(t_frame *frame);
void			init_windows(t_frame *frame);
t_vec			check_texture(t_ray ray);
void			reset_filters(t_frame *frame);
t_vec			apply_filter(t_frame *frame, t_vec col);
t_light			*l_current_obj(t_tri *lst);
void			l_count_liste(t_tri *lst);
void			split_in_2(t_tri *lst);
void			split_in_4(t_tri *lst);
void			split_in_1(t_tri *lst);
void			gene_preview(t_tri *lst);
void			preview_build(t_tri *lst, t_object *obj, int type);
void			preview_build2(t_object *obj, t_object *tmp);
void			preview_build3(t_object *obj, t_object *tmp);
void			preview_add(t_tri *lst);
void			preview_add2(t_tri *lst, t_object *tmp);
void			preview_add3(t_tri *lst, t_object *tmp);
void			error_texture_load(char *name);
void			init_textures(t_frame *frame);
t_texture		*get_tex(t_frame *frame, char *name);
t_vec			apply_tex(t_frame *frame, char *name, \
		t_object *obj, t_ray *ray);
void			load_block(t_tri *lst);
void			init_lst(t_tri *lst, t_frame *frame, char **str);
void			init_lst2(t_tri *lst, t_frame *frame, char **str);
void			reset_all(t_tri *l);
void			put_mousse2(int keycode, int x, int y, t_tri *lst);
void			put_mousse_0(int keycode, int x, int y, t_tri *lst);
void			put_mousse_0_2(int keycode, int x, int y, t_tri *lst);
void			put_mousse_menu(int keycode, int x, int y, t_tri *lst);
void			put_mousse_11(int keycode, int x, int y, t_tri *lst);
void			put_mousse_11_2(int keycode, int x, int y, t_tri *lst);
void			put_mousse_11_3(int keycode, int x, int y, t_tri *lst);
void			put_mousse_40(int keycode, int x, int y, t_tri *lst);
void			put_mousse_20(int keycode, int x, int y, t_tri *lst);
void			load_block2(t_tri *lst);
void			go_to_file(t_tri *lst, int i);
void			limitation(t_light *obj);
t_vec			color_sum(t_frame *frame, t_ray *ray, t_lum lum);
void			color_sum2(t_frame *frame, t_ray *ray, \
		t_lum lum, t_env_color *e);
void			color_sum3(t_frame *frame, t_ray *ray, \
		t_lum lum, t_env_color *e);
t_vec			find_normal2(t_ray *ray, t_vec p, t_vec n);
void			intersect_color2(t_frame *frame, t_ray *ray, t_env_inter *e);
void			phong_shading(t_ray *ray, t_light *t, t_lum *l);
t_vec			find_normal(t_ray *ray, t_vec p);
void			lum_direct(t_frame *frame, t_ray *ray, t_lum *lum);
void			verify_intersect2(t_ray *ray, \
		t_object *obj, t_vec t12, t_env_verif *e);
void			verify_intersect3(t_ray *ray, t_object *obj, t_vec t12);
t_vec			surf_transf(t_ray *ray, t_object *obj, t_vec t12);
t_vec			surf_extrude_inv(t_object *obj, t_vec t12, t_vec t34);
t_vec			surf_extrude(t_ray *ray, t_object *obj, t_vec t12, t_vec t34);
t_material		*extrude(t_ray *ray, t_object *obj, t_material *src);
void			verify_t(t_ray *ray, t_object *obj, double t);
t_vec			intersect_shape(t_ray *ray, t_object *tmp);
t_material		*remove_mate(t_material *mate, t_material **begin);
t_material		*remove_mate2(t_material *mate, t_material **begin);
void			mate_inter_mate2(t_material *src, t_material *extr);
t_material		*mate_extr_mate(t_material *src, t_material *extr,
		t_material **begin);
void			mate_extr_mate2(t_material *src, t_material *extr);
t_material		*mate_inter_mate(t_material *src, \
		t_material *extr, t_material **begin);
t_material		*s_mate_extr_mate(t_material *src, \
		t_material *extr, t_material **begin);
void			obj_to_mate(t_ray *ray, t_object *obj, \
		t_material **extr, t_vec tv);
void			obj_to_mate2(t_ray *ray, t_object *obj, \
		t_material **extr, t_vec tv);
void			obj_to_mate3(t_ray *ray, t_object *obj, \
		t_material **extr, t_vec tv);
void			obj_to_mate4(t_ray *ray, t_object *obj, \
		t_material **extr, t_vec tv);
void			obj_to_mate5(t_ray *ray, t_object *obj, \
		t_material **extr);
double			linear_interpolate(double a, double b, double t);
double			fast_dot(const int *v, const double x, \
		const double y, const double z);
void			parsing_transf2(t_frame *frame, \
		t_object **dst, char *line, char *tmp);
void			trash_reset(t_object *trash);
char			*str_itoa_b(t_tri *lst, int x, int y, double nb);
char			*str_itoa_w(t_tri *lst, int x, int y, double nb);
char			**freetoa(int max, char **tab);
void			ft_store_list(t_frame *frame);

#endif
