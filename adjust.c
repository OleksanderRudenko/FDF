/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 10:06:05 by arudenko          #+#    #+#             */
/*   Updated: 2018/01/15 10:10:09 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_x_y(t_fdf *fdf, float a)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->vertic)
	{
		j = 0;
		while (j < fdf->horiz)
		{
			fdf->cor[i][j].x = fdf->cor[i][j].x * a;
			fdf->cor[i][j].y = fdf->cor[i][j].y * a;
			fdf->cor[i][j].xn = fdf->cor[i][j].xn * a;
			fdf->cor[i][j].yn = fdf->cor[i][j].yn * a;
			j++;
		}
		i++;
	}
}

void	turn_persp(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->vertic)
	{
		j = 0;
		while (j < fdf->horiz)
		{
			fdf->cor[i][j].x = fdf->cor[i][j].x / (1 - fdf->cor[i][j].z / 25);
			fdf->cor[i][j].y = fdf->cor[i][j].y / (1 - fdf->cor[i][j].z / 25);
			fdf->cor[i][j].xn = fdf->cor[i][j].x + fdf->screen_w / 2;
			fdf->cor[i][j].yn = fdf->cor[i][j].y + fdf->screen_h / 2;
			j++;
		}
		i++;
	}
}

void	scale(t_fdf *fdf, float a)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	scale_x_y(fdf, a);
	draw_string_menu(fdf);
	draw_line_ber(fdf);
}

void	change_c(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_string_menu(fdf);
	change_color(fdf);
	draw_line_ber(fdf);
}

void	free_double(char **s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_strdel(&s[i]);
		i++;
	}
	free(s);
	s = NULL;
}
