/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 10:08:13 by arudenko          #+#    #+#             */
/*   Updated: 2018/01/15 11:03:35 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_fdf *fdf, int a)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->vertic)
	{
		j = 0;
		while (j < fdf->horiz)
		{
			fdf->cor[i][j].y = ((fdf->cor[i][j].y * cos(PI / 180 * a)) +\
				(fdf->cor[i][j].z * sin(PI / 180 * a)));
			fdf->cor[i][j].z = ((-fdf->cor[i][j].y * sin(PI / 180 * a)) +\
				(fdf->cor[i][j].z * cos(PI / 180 * a)));
			fdf->cor[i][j].xn = fdf->cor[i][j].x + fdf->screen_w / 2;
			fdf->cor[i][j].yn = fdf->cor[i][j].y + fdf->screen_h / 2;
			j++;
		}
		i++;
	}
}

void	rotate_y(t_fdf *fdf, int a)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->vertic)
	{
		j = 0;
		while (j < fdf->horiz)
		{
			fdf->cor[i][j].x = (fdf->cor[i][j].x * cos(PI / 180 * a) +\
				fdf->cor[i][j].z * sin(PI / 180 * a));
			fdf->cor[i][j].z = (-fdf->cor[i][j].x * sin(PI / 180 * a) +\
				fdf->cor[i][j].z * cos(PI / 180 * a));
			fdf->cor[i][j].xn = fdf->cor[i][j].x + fdf->screen_w / 2;
			fdf->cor[i][j].yn = fdf->cor[i][j].y + fdf->screen_h / 2;
			j++;
		}
		i++;
	}
}

void	rotate_z(t_fdf *fdf, int a)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->vertic)
	{
		j = 0;
		while (j < fdf->horiz)
		{
			fdf->cor[i][j].x = (fdf->cor[i][j].x * cos(PI / 180 * a)) -\
				fdf->cor[i][j].y * sin(PI / 180 * a);
			fdf->cor[i][j].y = (fdf->cor[i][j].x * sin(PI / 180 * a)) +\
				fdf->cor[i][j].y * cos(PI / 180 * a);
			fdf->cor[i][j].xn = fdf->cor[i][j].x + fdf->screen_w / 2;
			fdf->cor[i][j].yn = fdf->cor[i][j].y + fdf->screen_h / 2;
			j++;
		}
		i++;
	}
}
