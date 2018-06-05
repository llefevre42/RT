/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_bmp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:33:16 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/16 17:09:05 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_BMP_H
# define S_BMP_H

struct __attribute__((packed))	s_bmp
{
	short						type;
	int							file_size;
	short						creator1;
	short						creator2;
	int							offset;
	int							header_size;
	int							width;
	int							height;
	short						color_planes;
	short						bpp;
	int							compression;
	int							raw_bmp_size;
	int							h_resolution;
	int							v_resolution;
	int							nb_color_in_palette;
	int							nb_important_colors;
	unsigned int				*tab32;
	unsigned char				*tab8;
};
#endif
