/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:27:35 by thvocans          #+#    #+#             */
/*   Updated: 2018/05/21 15:20:33 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_H
# define JSON_H

# include "rt.h"

struct			s_trans
{
	t_object	*o;
	int			read[21];
	int			depth;
	t_trans		*next;
};

struct			s_pars
{
	int			depth;
	int			extr;
	int			extr_depth;
	char		**params;
	int			*p_len;
	int			p_cpt;
	char		*f;
	int			i;
	int			type;
	int			last_type;
	t_trans		*l;
};

/*
** Parsing
*/

void			parsing_choice(t_frame *frame, char **argv);
void			parsing_txt(t_frame *frame, int fd);
void			parsing_object(t_frame *frame, char *line);
void			parsing_json(t_frame *s, int fd);

int				gnb(const int fd, char **line);
double			atof_custom(char *str);
int				ft_isdigispace(char *str, int i);
int				ft_isfloat(char *str, int i);
void			ft_skiptobracket(t_pars *p);
void			ft_comma(t_pars *p);
void			ft_endbracket(t_pars *p);
void			ft_transf(t_pars *p);
void			rm_transf(t_pars *p);
int				ft_error_txt(char *str);

int				jsonator(t_frame *frame, t_pars *p);
void			paramator(t_frame *frame, t_pars *p);
void			paramator2(t_frame *frame, t_pars *p);
void			paramator3(t_pars *p);
void			paramator4(t_pars *p, void **var);
void			paramator5(t_pars *p);

void			ft_obj(t_frame *frame, t_pars *p);
void			call_obj(t_frame *frame, t_pars *p);
t_mat			ft_point(t_frame *frame, t_pars *p);
t_mat			ft_rotation(t_frame *frame, t_pars *p);
void			ft_light(t_frame *frame, t_pars *p);
void			ft_cam(t_frame *frame, t_pars *p);
void			ft_size(t_frame *frame, t_pars *p);
void			ft_back(t_frame *frame, t_pars *p);
void			ft_ambiante(t_frame *frame, t_pars *p);
void			ft_limit(t_pars *p);
void			ft_lum(t_pars *p);
void			ft_quad_obj(t_pars *p);
void			**ft_voidstar(t_pars *p);

double			ft_one_double(t_pars *p);
t_vec			ft_vec3(t_pars *p);
t_quad			ft_quad(t_pars *p);

#endif
