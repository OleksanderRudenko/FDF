/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 10:07:08 by arudenko          #+#    #+#             */
/*   Updated: 2018/01/15 10:33:24 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_ber(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->vertic)
	{
		j = 0;
		while (j < fdf->horiz)
		{
			if (j + 1 < fdf->horiz)
				draw_line_hor(fdf, i, j);
			if (i + 1 < fdf->vertic)
				draw_line_vert(fdf, i, j);
			j++;
		}
		i++;
	}
}

void	draw_line_hor(t_fdf *fdf, int i, int j)
{
	fdf->dx = (fdf->cor[i][j + 1].xn - fdf->cor[i][j].xn >= 0 ? 1 : -1);
	fdf->dy = (fdf->cor[i][j + 1].yn - fdf->cor[i][j].yn >= 0 ? 1 : -1);
	fdf->len_x = fabs(fdf->cor[i][j + 1].xn - fdf->cor[i][j].xn);
	fdf->len_y = fabs(fdf->cor[i][j + 1].yn - fdf->cor[i][j].yn);
	fdf->length = fmax(fdf->len_x, fdf->len_y);
	if (fdf->len_y <= fdf->len_x)
		part1(fdf, i, j);
	else
		part2(fdf, i, j);
}

void	draw_line_vert(t_fdf *fdf, int i, int j)
{
	fdf->dx = (fdf->cor[i + 1][j].xn - fdf->cor[i][j].xn >= 0 ? 1 : -1);
	fdf->dy = (fdf->cor[i + 1][j].yn - fdf->cor[i][j].yn >= 0 ? 1 : -1);
	fdf->len_x = fabs(fdf->cor[i + 1][j].xn - fdf->cor[i][j].xn);
	fdf->len_y = fabs(fdf->cor[i + 1][j].yn - fdf->cor[i][j].yn);
	fdf->length = fmax(fdf->len_x, fdf->len_y);
	if (fdf->len_y <= fdf->len_x)
		part1(fdf, i, j);
	else
		part2(fdf, i, j);
}

void	part1(t_fdf *fdf, int i, int j)
{
	fdf->x = fdf->cor[i][j].xn;
	fdf->y = fdf->cor[i][j].yn;
	fdf->d = -fdf->len_x;
	fdf->length++;
	while (fdf->length--)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x, fdf->y,\
			interpol_x(fdf, i, j, fdf->x));
		fdf->x += fdf->dx;
		fdf->d += 2 * fdf->len_y;
		if (fdf->d > 0)
		{
			fdf->d -= 2 * fdf->len_x;
			fdf->y += fdf->dy;
		}
	}
}

void	part2(t_fdf *fdf, int i, int j)
{
	fdf->x = fdf->cor[i][j].xn;
	fdf->y = fdf->cor[i][j].yn;
	fdf->d = -fdf->len_y;
	fdf->length++;
	while (fdf->length--)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x, fdf->y,\
			interpol_y(fdf, i, j, fdf->y));
		fdf->y += fdf->dy;
		fdf->d += 2 * fdf->len_x;
		if (fdf->d > 0)
		{
			fdf->d -= 2 * fdf->len_y;
			fdf->x += fdf->dx;
		}
	}
}
