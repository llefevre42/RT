/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_form.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 22:34:44 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/24 20:19:04 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	menu_form(t_tri *l)
{
	mlx_put_image_to_window(l->mlx, l->win, l->pt_p_menu_form, 0, 0);
}

void	reset(char *add)
{
	add[0] = ' ';
	add[1] = ' ';
	add[2] = ' ';
}

void	reset_all(t_tri *l)
{
	reset(l->tab_pos_x);
	reset(l->tab_pos_y);
	reset(l->tab_pos_z);
	reset(l->tab_dir_x);
	reset(l->tab_dir_y);
	reset(l->tab_dir_z);
	reset(l->tab_color_r);
	reset(l->tab_color_g);
	reset(l->tab_color_b);
	reset(l->tab_ray);
	reset(l->tab_transp);
	reset(l->tab_diff);
	reset(l->tab_shine);
	reset(l->tab_refra);
	reset(l->tab_reflec);
	reset(l->tab_matiere);
	reset(l->tab_rug);
	reset(l->tab_limite);
}

void	modif_form(t_tri *l)
{
	t_object	*obj;
	int			c;

	if (!(obj = current_obj(l)))
		ft_error_txt("modif form obj pointer is NULL\n");
	c = 0XFFFFFF;
	reset_all(l);
	add_form(l);
	mlx_put_image_to_window(l->mlx, l->win, l->pt_p_menu_shape, 0, 0);
	free(str_itoa_b(l, 160, 465, obj->orig.x));
	free(str_itoa_b(l, 260, 465, obj->orig.y));
	free(str_itoa_b(l, 360, 465, obj->orig.z));
	free(str_itoa_b(l, 560, 465, obj->data.x * 100));
	free(str_itoa_b(l, 660, 465, obj->data.y * 100));
	free(str_itoa_b(l, 760, 465, obj->data.z * 100));
	free(str_itoa_b(l, 360, 585, obj->color.x * 255));
	free(str_itoa_b(l, 460, 585, obj->color.y * 255));
	free(str_itoa_b(l, 560, 585, obj->color.z * 255));
	if (obj->type == 3)
		free(str_itoa_b(l, 160, 725, obj->r * 100));
	else
		free(str_itoa_b(l, 160, 725, obj->r));
	modif_form2(l, obj);
}

void	modif_form2(t_tri *l, t_object *obj)
{
	int c;

	c = 0XFFFFFF;
	free(str_itoa_b(l, 260, 725, obj->transp));
	free(str_itoa_b(l, 360, 725, obj->matiere));
	free(str_itoa_b(l, 460, 725, obj->indice * 100));
	free(str_itoa_b(l, 560, 725, obj->rug * 100));
	free(str_itoa_b(l, 660, 725, obj->ks * 100));
	free(str_itoa_b(l, 760, 725, obj->reflec * 100));
	if (obj->type == 1)
		mlx_string_put(l->mlx, l->win, 440, 350, 0X000000, "sphere");
	if (obj->type == 0)
		mlx_string_put(l->mlx, l->win, 440, 350, 0X000000, "plan");
	if (obj->type == 2)
		mlx_string_put(l->mlx, l->win, 440, 350, 0X000000, "cylinder");
	if (obj->type == 3)
		mlx_string_put(l->mlx, l->win, 440, 350, 0X000000, "cone");
}
