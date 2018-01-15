/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 10:08:30 by arudenko          #+#    #+#             */
/*   Updated: 2018/01/15 10:49:07 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include <math.h>

# define PI 3.1415

typedef struct		s_fdf
{
	struct s_foo	**cor;
	struct s_flist	*beg;
	float			x;
	float			y;
	float			d;
	float			dis;
	int				screen_w;
	int				screen_h;
	int				scale;
	int				dx;
	int				dy;
	int				len_x;
	int				len_y;
	int				length;
	int				horiz;
	int				vertic;
	void			*mlx;
	void			*win;
}					t_fdf;

typedef struct		s_foo
{
	float			x;
	float			y;
	float			z;
	float			x_or;
	float			y_or;
	float			z_original;
	float			xn;
	float			yn;
	int				color;
	int				col_tmp;
	int				col_or;
}					t_foo;

typedef struct		s_flist
{
	int				hor;
	int				vert;
	char			*ln;
	struct s_flist	*next;
}					t_flist;

typedef struct		s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}					t_color;

void				draw_line_ber(t_fdf *fdf);
t_foo				**fill_coords(t_fdf fdf);
void				fill_color(t_flist *head, t_fdf *fdf);
int					list_size(t_flist *head);
void				count_symbols(t_flist *head);
t_flist				*read_file(char *str);
void				draw_line_hor(t_fdf *fdf, int i, int j);
void				draw_line_vert(t_fdf *fdf, int i, int j);
int					*x_coord(int num, int num2);
int					*y_coord(int num, int num2);
void				rotate_x(t_fdf *fdf, int a);
void				rotate_y(t_fdf *fdf, int a);
void				rotate_z(t_fdf *fdf, int a);
void				change_x(t_fdf *fdf, float a);
void				change_y(t_fdf *fdf, float a);
int					get_laid_with_color(char *str);
size_t				search_coma(char *str);
void				arr_colors(char *s, int **arr, int **arr_color);
void				draw_line_ber(t_fdf *fdf);
void				turn_persp(t_fdf *fdf);
void				part1(t_fdf *fdf, int i, int j);
void				part2(t_fdf *fdf, int i, int j);
void				scale(t_fdf *fdf, float a);
void				free_double(char **s);
int					draw_all(t_fdf *fdf);
void				move_r_l(t_fdf *fdf, int a);
void				move_u_d(t_fdf *fdf, int a);
void				rot_x(t_fdf *fdf, int a);
void				rot_y(t_fdf *fdf, int a);
void				rot_z(t_fdf *fdf, int a);
void				change_color(t_fdf *fdf);
int					interpol_x(t_fdf *fdf, int i, int j, float x);
int					interpol_y(t_fdf *fdf, int i, int j, float y);
void				draw_string_menu(t_fdf *fdf);
void				change_c(t_fdf *fdf);
void				set_defaults(t_fdf *fdf);
void				error(void);

#endif
