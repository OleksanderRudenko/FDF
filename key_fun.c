/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 10:07:38 by arudenko          #+#    #+#             */
/*   Updated: 2018/01/15 10:35:36 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_r_l(t_fdf *fdf, int a)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	change_x(fdf, a);
	draw_string_menu(fdf);
	draw_line_ber(fdf);
}

void	move_u_d(t_fdf *fdf, int a)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	change_y(fdf, a);
	draw_string_menu(fdf);
	draw_line_ber(fdf);
}

void	rot_x(t_fdf *fdf, int a)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	rotate_x(fdf, a);
	draw_string_menu(fdf);
	draw_line_ber(fdf);
}

void	rot_y(t_fdf *fdf, int a)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	rotate_y(fdf, a);
	draw_string_menu(fdf);
	draw_line_ber(fdf);
}

void	rot_z(t_fdf *fdf, int a)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	rotate_z(fdf, a);
	draw_string_menu(fdf);
	draw_line_ber(fdf);
}
