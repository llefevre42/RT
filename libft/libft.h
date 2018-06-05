/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 20:35:34 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/24 19:18:10 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_mat
{
	double			a;
	double			b;
	double			c;
	double			d;
	double			e;
	double			f;
	double			g;
	double			h;
	double			i;
}					t_mat;

typedef struct		s_quad
{
	t_mat			q;
	t_vec			u;
	double			k;
}					t_quad;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

_Bool				ft_vec_equal(t_vec a, t_vec b);
t_mat				ft_mat_mult(t_mat x, t_mat y);
t_mat				ft_mat_null(void);
t_mat				ft_mat_id(void);
double				ft_quad_calc(t_vec x, t_mat q, t_vec y);
int					ft_signe(double a);
int					ft_meme_signe(double a, double b);
t_vec				ft_vec_create(double x, double y, double z);
t_vec				ft_normalize(t_vec a);
double				ft_norme(t_vec a);
double				ft_norme2(t_vec a);
t_vec				ft_vec_mult(t_vec a, t_vec b);
t_vec				ft_vec_scal(double k, t_vec a);
t_vec				ft_vec_cross(t_vec b, t_vec c);
t_vec				ft_vec_linear(double a, t_vec u, double b, t_vec v);
double				ft_vec_dot(t_vec a, t_vec b);
int					ft_int_rgb_to_hex(double r, double g, double b);
t_vec				ft_hex_to_rgb(int hex);
int					ft_rgb_to_hex(t_vec rgb);
double				**ft_create_double_tab(int n, int m);
double				ft_atoi_d(char **str);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isblank(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isnum(char c);
int					ft_isprint(int c);
int					ft_isspace(char c);
int					ft_isupper(int c);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strisalpha(char *str);
int					ft_strislower(char *str);
int					ft_strisnum(char *str);
int					ft_strisprint(char *str);
int					ft_strisupper(char *str);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strlowcase(char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
char				*ft_strndup(const char *s, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strupcase(char *str);
void				ft_swap(int *a, int *b);
int					ft_tolower(int c);
int					ft_toupper(int c);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void(*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void(f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_malloncat(char *dest, char *buf, size_t n);
int					gnl(const int fd, char **line);
t_vec				ft_vec_product(t_vec a, t_vec b);
#endif
