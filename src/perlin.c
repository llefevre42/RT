/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:23:02 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/17 18:21:14 by rpinault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

unsigned char				g_perm[512] =
{
	151, 160, 137, 91, 90, 15, 131, 13, 201, 95, 96, 53, 194, 233, 7, 225,
	140, 36, 103, 30, 69, 142, 8, 99, 37, 240, 21, 10, 23, 190, 6, 148,
	247, 120, 234, 75, 0, 26, 197, 62, 94, 252, 219, 203, 117, 35, 11, 32,
	57, 177, 33, 88, 237, 149, 56, 87, 174, 20, 125, 136, 171, 168, 68,
	175, 74, 165, 71, 134, 139, 48, 27, 166, 77, 146, 158, 231, 83, 111,
	229, 122, 60, 211, 133, 230, 220, 105, 92, 41, 55, 46, 245, 40, 244,
	102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132, 187, 208,
	89, 18, 169, 200, 196, 135, 130, 116, 188, 159, 86, 164, 100, 109, 198,
	173, 186, 3, 64, 52, 217, 226, 250, 124, 123, 5, 202, 38, 147, 118,
	126, 255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182, 189, 28,
	42, 223, 183, 170, 213, 119, 248, 152, 2, 44, 154, 163, 70, 221, 153,
	101, 155, 167, 43, 172, 9, 129, 22, 39, 253, 19, 98, 108, 110, 79, 113,
	224, 232, 178, 185, 112, 104, 218, 246, 97, 228, 251, 34, 242, 193, 238,
	210, 144, 12, 191, 179, 162, 241, 81, 51, 145, 235, 249, 14, 239, 107,
	49, 192, 214, 31, 181, 199, 106, 157, 184, 84, 204, 176, 115, 121, 50,
	45, 127, 4, 150, 254, 138, 236, 205, 93, 222, 114, 67, 29, 24, 72, 243,
	141, 128, 195, 78, 66, 215, 61, 156, 180,
	151, 160, 137, 91, 90, 15, 131, 13, 201, 95, 96, 53, 194, 233, 7, 225, 140,
	127, 4, 150, 254, 138, 236, 205, 93, 222, 114, 67, 29, 24, 72, 243, 141,
	128, 195, 78, 66, 215, 61, 156, 180
};

int							g_grad3[16][3] = {
	{1, 1, 0}, {-1, 1, 0}, {1, -1, 0}, {-1, -1, 0},
	{1, 0, 1}, {-1, 0, 1}, {1, 0, -1}, {-1, 0, -1},
	{0, 1, 1}, {0, -1, 1}, {0, 1, -1}, {0, -1, -1},
	{1, 1, 0}, {-1, 1, 0}, {0, -1, 1}, {0, -1, -1}};

static int					*get_grad(int x, int y, int z)
{
	int						rand_value;

	rand_value = g_perm[z + g_perm[y + g_perm[x]]];
	return (g_grad3[rand_value & 15]);
}

static double				quintic_poly(const double t)
{
	return (t * t * t * (t * (t * 6 - 15) + 10));
}

static void					int_and_frac(double value, int *integer_part,
		double *fractional_part)
{
	*integer_part = (int)value;
	if (value < 0)
		integer_part -= 1;
	*fractional_part = value - *integer_part;
}

double						smooth_noise_3d_2(t_perlin p)
{
	p.g110 = fast_dot(get_grad(p.gx + 1, p.gy + 1, p.gz),
			p.x - 1., p.y - 1., p.z);
	p.g111 = fast_dot(get_grad(p.gx + 1, p.gy + 1, p.gz + 1),
			p.x - 1., p.y - 1., p.z - 1.);
	p.u = quintic_poly(p.x);
	p.v = quintic_poly(p.y);
	p.w = quintic_poly(p.z);
	p.x00 = linear_interpolate(p.g000, p.g100, p.u);
	p.x10 = linear_interpolate(p.g010, p.g110, p.u);
	p.x01 = linear_interpolate(p.g001, p.g101, p.u);
	p.x11 = linear_interpolate(p.g011, p.g111, p.u);
	p.xy0 = linear_interpolate(p.x00, p.x10, p.v);
	p.xy1 = linear_interpolate(p.x01, p.x11, p.v);
	p.xyz = linear_interpolate(p.xy0, p.xy1, p.w);
	return (p.xyz);
}

double						smooth_noise_3d(double x_pos, double y_pos,
		double z_pos, double res)
{
	t_perlin				p;

	x_pos = fabs(x_pos) / res;
	y_pos = fabs(y_pos) / res;
	z_pos = fabs(z_pos) / res;
	int_and_frac(x_pos, &p.gx, &p.x);
	int_and_frac(y_pos, &p.gy, &p.y);
	int_and_frac(z_pos, &p.gz, &p.z);
	p.gx &= 255;
	p.gy &= 255;
	p.gz &= 255;
	p.g000 = fast_dot(get_grad(p.gx, p.gy, p.gz),
			p.x, p.y, p.z);
	p.g001 = fast_dot(get_grad(p.gx, p.gy, p.gz + 1),
			p.x, p.y, p.z - 1.);
	p.g010 = fast_dot(get_grad(p.gx, p.gy + 1, p.gz),
			p.x, p.y - 1., p.z);
	p.g011 = fast_dot(get_grad(p.gx, p.gy + 1, p.gz + 1),
			p.x, p.y - 1., p.z - 1.);
	p.g100 = fast_dot(get_grad(p.gx + 1, p.gy, p.gz),
			p.x - 1., p.y, p.z);
	p.g101 = fast_dot(get_grad(p.gx + 1, p.gy, p.gz + 1),
			p.x - 1., p.y, p.z - 1.);
	return (smooth_noise_3d_2(p));
}
