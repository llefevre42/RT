/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:28:41 by llefevre          #+#    #+#             */
/*   Updated: 2018/05/21 15:48:47 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	text_light_add(t_tri *l)
{
	unsigned char	*tab;
	int				t1;
	int				t2;
	int				t3;

	if (!(tab = (unsigned char *)ft_read_i("texture/menu_light_add.bmp", l)))
		ft_error(1);
	l->pt_p_light_add = mlx_new_image(l->mlx, 200, 200);
	l->p_light_add = (unsigned int *)mlx_get_data_addr(\
			l->pt_p_light_add, &t1, &t2, &t3);
	l->p_light_add = tri_bmp(tab, l->p_light_add);
	free(tab);
}

void	text_light_del(t_tri *l)
{
	unsigned char	*tab;
	int				t1;
	int				t2;
	int				t3;

	if (!(tab = (unsigned char *)ft_read_i("texture/menu_light_del.bmp", l)))
		ft_error(1);
	l->pt_p_light_del = mlx_new_image(l->mlx, 200, 200);
	l->p_light_del = (unsigned int *)mlx_get_data_addr(\
			l->pt_p_light_del, &t1, &t2, &t3);
	l->p_light_del = tri_bmp(tab, l->p_light_del);
	free(tab);
}

void	text_light_modif(t_tri *l)
{
	unsigned char	*tab;
	int				t1;
	int				t2;
	int				t3;

	if (!(tab = (unsigned char *)ft_read_i("texture/menu_light_modif.bmp", l)))
		ft_error(1);
	l->pt_p_light_modif = mlx_new_image(l->mlx, 200, 200);
	l->p_light_modif = (unsigned int *)mlx_get_data_addr(\
			l->pt_p_light_modif, &t1, &t2, &t3);
	l->p_light_modif = tri_bmp(tab, l->p_light_modif);
	free(tab);
}

void	text_flecheg(t_tri *l)
{
	unsigned char	*tab;
	int				t1;
	int				t2;
	int				t3;

	if (!(tab = (unsigned char *)ft_read_i("texture/flecheG.bmp", l)))
		ft_error(1);
	l->pt_p_flecheg = mlx_new_image(l->mlx, 50, 50);
	l->p_flecheg = (unsigned \
			int *)mlx_get_data_addr(l->pt_p_flecheg, &t1, &t2, &t3);
	l->p_flecheg = tri_bmp(tab, l->p_flecheg);
	free(tab);
}

void	text_flecheb(t_tri *l)
{
	unsigned char	*tab;
	int				t1;
	int				t2;
	int				t3;

	if (!(tab = (unsigned char *)ft_read_i("texture/flecheD.bmp", l)))
		ft_error(1);
	l->pt_p_fleched = mlx_new_image(l->mlx, 50, 50);
	l->p_fleched = (unsigned \
			int *)mlx_get_data_addr(l->pt_p_fleched, &t1, &t2, &t3);
	l->p_fleched = tri_bmp(tab, l->p_fleched);
	free(tab);
}
