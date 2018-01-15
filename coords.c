/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 10:06:24 by arudenko          #+#    #+#             */
/*   Updated: 2018/01/15 10:23:08 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_foo		**fill_coords(t_fdf fdf)
{
	t_foo		**tmp;
	int			i;
	int			j;

	i = 0;
	tmp = (t_foo **)malloc(sizeof(t_foo *) * fdf.vertic);
	while (i < fdf.vertic)
	{
		j = -1;
		tmp[i] = (t_foo *)malloc(sizeof(t_foo) * fdf.horiz);
		while (++j < fdf.horiz)
		{
			tmp[i][j].x = ((j - fdf.horiz / 2) * fdf.scale);
			tmp[i][j].y = (i - fdf.vertic / 2) * fdf.scale;
			tmp[i][j].x_or = ((j - fdf.horiz / 2) * fdf.scale);
			tmp[i][j].y_or = (i - fdf.vertic / 2) * fdf.scale;
			tmp[i][j].xn = tmp[i][j].x + fdf.screen_w / 2;
			tmp[i][j].yn = tmp[i][j].y + fdf.screen_h / 2;
		}
		i++;
	}
	return (tmp);
}

void		fill_color(t_flist *head, t_fdf *fdf)
{
	int			i;
	int			j;
	int			*arr_color;
	t_flist		*lol;
	int			*arr;

	i = -1;
	lol = head;
	while (++i < fdf->vertic)
	{
		j = 0;
		arr_colors(lol->ln, &arr, &arr_color);
		while (j < fdf->horiz)
		{
			fdf->cor[i][j].color = arr_color[j];
			fdf->cor[i][j].col_or = fdf->cor[i][j].color;
			fdf->cor[i][j].z = arr[j] * 6;
			fdf->cor[i][j].z_original = arr[j] * 6;
			j++;
		}
		free(arr_color);
		free(arr);
		lol = lol->next;
	}
}

void		change_color(t_fdf *fdf)
{
	int			i;
	int			j;
	int			red;
	int			green;
	int			blue;

	i = 0;
	red = fdf->cor[0][0].color / 256 ^ 2;
	green = (fdf->cor[0][0].color / 256 % 256 ^ 2);
	blue = fdf->cor[0][0].color % 256;
	while (i < fdf->vertic)
	{
		j = 0;
		while (j < fdf->horiz)
		{
			fdf->cor[i][j].color = (red * 0xFFFF) + (green * 0xFF) + (blue);
			if (fdf->cor[i][j].z_original != 0)
				fdf->cor[i][j].color = 0x009600;
			j++;
		}
		i++;
	}
}
