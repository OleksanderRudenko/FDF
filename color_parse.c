/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 10:06:15 by arudenko          #+#    #+#             */
/*   Updated: 2018/01/15 10:21:50 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_parse(t_fdf *fdf, t_color *col, int i, int j)
{
	fdf->cor[i][j].col_tmp = fdf->cor[i][j].color;
	col->red = fdf->cor[i][j].col_tmp >> 16;
	col->green = fdf->cor[i][j].col_tmp >> 8;
	col->blue = fdf->cor[i][j].col_tmp;
}

int		interpol_x(t_fdf *fdf, int i, int j, float x)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	t_color			col_start;
	t_color			col_end;

	if ((i + 1) < fdf->vertic && (j + 1) < fdf->horiz)
	{
		color_parse(fdf, &col_start, i, j);
		color_parse(fdf, &col_end, i, j + 1);
		fdf->dis = ((float)x - fdf->cor[i][j].xn) / \
			(fdf->cor[i][j + 1].xn - fdf->cor[i][j].xn);
		red = (col_end.red - col_start.red) * fdf->dis + col_start.red;
		green = (col_end.green - col_start.green) * fdf->dis + col_start.green;
		blue = (col_end.blue - col_start.blue) * fdf->dis + col_start.blue;
		return (fdf->cor[i][j].col_tmp = (unsigned int)(red << 16) + \
			(unsigned int)(green << 8) + (unsigned int)(blue));
	}
	return (fdf->cor[i][j].color);
}

int		interpol_y(t_fdf *fdf, int i, int j, float y)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	t_color			col_start;
	t_color			col_end;

	if ((i + 1) < fdf->vertic && (j + 1) < fdf->horiz)
	{
		color_parse(fdf, &col_start, i, j);
		color_parse(fdf, &col_end, i + 1, j);
		fdf->dis = (y - fdf->cor[i][j].yn) / \
			(fdf->cor[i + 1][j].yn - fdf->cor[i][j].yn);
		red = (col_end.red - col_start.red) * fdf->dis + col_start.red;
		green = (col_end.green - col_start.green) * fdf->dis + col_start.green;
		blue = (col_end.blue - col_start.blue) * fdf->dis + col_start.blue;
		return (fdf->cor[i][j].col_tmp = (unsigned int)(red << 16)\
			+ (unsigned int)(green << 8) + (unsigned int)(blue));
	}
	return (fdf->cor[i][j].color);
}
