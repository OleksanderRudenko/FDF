/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 10:07:01 by arudenko          #+#    #+#             */
/*   Updated: 2018/01/15 11:19:31 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_flist		*read_file(char *str)
{
	int			fd;
	t_flist		*tmp;
	char		*line;
	t_flist		*xd;

	if ((fd = open(str, O_RDONLY)) == -1)
	{
		exit(0);
		return (NULL);
	}
	xd = (t_flist *)malloc(sizeof(t_flist));
	tmp = xd;
	while ((get_next_line(fd, &line)))
	{
		tmp->ln = ft_strdup(line);
		tmp->next = (t_flist *)malloc(sizeof(t_flist));
		tmp = tmp->next;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	tmp->next = NULL;
	close(fd);
	return (xd);
}

void		count_symbols(t_flist *head)
{
	t_flist		*tmp;
	int			horiz;
	int			vertic;

	tmp = head;
	horiz = ft_num_words(head->ln, ' ');
	vertic = list_size(head);
	while (tmp->next)
	{
		tmp->hor = ft_num_words(tmp->ln, ' ');
		if (tmp->hor > horiz || tmp->hor == horiz)
			tmp->hor = horiz;
		else
		{
			ft_putendl("Error: wrong num of lines");
			exit(0);
		}
		tmp->vert = vertic;
		tmp = tmp->next;
	}
}

int			key_hook(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(0);
	if (key == 124 || key == 123)
		move_r_l(fdf, key == 123 ? -10 : 10);
	if (key == 126 || key == 125)
		move_u_d(fdf, key == 125 ? 10 : -10);
	if (key == 88 || key == 86)
		rot_x(fdf, key == 86 ? -2 : 2);
	if (key == 91 || key == 84)
		rot_y(fdf, key == 84 ? 2 : -2);
	if (key == 89 || key == 85)
		rot_z(fdf, key == 85 ? -1 : 1);
	if (key == 69 || key == 78)
		scale(fdf, key == 78 ? 0.9 : 1.1);
	if (key == 18)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		turn_persp(fdf);
		draw_line_ber(fdf);
	}
	if (key == 8)
		change_c(fdf);
	if (key == 87)
		set_defaults(fdf);
	return (0);
}

int			main(int argc, char **argv)
{
	t_fdf		fdf;

	if (argc != 2)
		error();
	fdf.scale = 30;
	fdf.beg = read_file(argv[1]);
	count_symbols(fdf.beg);
	fdf.vertic = list_size(fdf.beg);
	fdf.horiz = ft_num_words(fdf.beg->ln, ' ');
	while ((fdf.horiz * fdf.scale > 1500 || fdf.vertic * fdf.scale > 1000)\
		&& fdf.scale > 1)
		fdf.scale--;
	fdf.screen_w = fdf.beg->hor * fdf.scale + 50;
	fdf.screen_h = fdf.beg->vert * fdf.scale + 50;
	fdf.cor = fill_coords(fdf);
	fill_color(fdf.beg, &fdf);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, fdf.screen_w + 200,\
		fdf.screen_h, "WAAAAATT");
	draw_string_menu(&fdf);
	draw_line_ber(&fdf);
	mlx_hook(fdf.win, 2, 5, key_hook, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
