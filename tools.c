/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 10:08:03 by arudenko          #+#    #+#             */
/*   Updated: 2018/01/15 10:38:59 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t		search_coma(char *str)
{
	size_t	i;

	if (str != NULL)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == ',')
				return (i);
			i++;
		}
	}
	return (0);
}

int			get_laid_with_color(char *str)
{
	int		a;
	char	*ass;

	if (search_coma(str) == 0)
		return (0);
	ass = ft_strsub(str, search_coma(str) + 1, ft_strlen(str));
	a = ft_atoi_base(ass + 2, 16);
	ft_strdel(&ass);
	return (a);
}

void		draw_string_menu(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, fdf->screen_w, 25,\
		0xAA0000, "MENU");
	mlx_string_put(fdf->mlx, fdf->win, fdf->screen_w, 50,\
		0xAA0000, "6 / 4 rotate X");
	mlx_string_put(fdf->mlx, fdf->win, fdf->screen_w, 75,\
		0x00AA00, "8 / 2 rotate Y");
	mlx_string_put(fdf->mlx, fdf->win, fdf->screen_w, 100,\
		0x0055AA, "7 / 3 rotate Z");
	mlx_string_put(fdf->mlx, fdf->win, fdf->screen_w, 125,\
		0xBB55AA, "+ / - zoom");
	mlx_string_put(fdf->mlx, fdf->win, fdf->screen_w, 150,\
		0xFFC832, "Arrow keys for move");
	mlx_string_put(fdf->mlx, fdf->win, fdf->screen_w, 175,\
		0xAAB182, "5  set defaults");
	mlx_string_put(fdf->mlx, fdf->win, fdf->screen_w, 200,\
		0xAAB182, "C and 1 for fun");
}

void		s_d(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->vertic)
	{
		j = 0;
		while (j < fdf->horiz)
		{
			fdf->cor[i][j].xn = fdf->cor[i][j].x_or + fdf->screen_w / 2;
			fdf->cor[i][j].yn = fdf->cor[i][j].y_or + fdf->screen_h / 2;
			fdf->cor[i][j].x = fdf->cor[i][j].x_or;
			fdf->cor[i][j].y = fdf->cor[i][j].y_or;
			fdf->cor[i][j].z = fdf->cor[i][j].z_original;
			fdf->cor[i][j].color = fdf->cor[i][j].col_or;
			j++;
		}
		i++;
	}
}

void		set_defaults(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	s_d(fdf);
	draw_string_menu(fdf);
	draw_line_ber(fdf);
}
