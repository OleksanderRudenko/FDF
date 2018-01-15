/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 10:07:17 by arudenko          #+#    #+#             */
/*   Updated: 2018/01/15 10:35:12 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		list_size(t_flist *head)
{
	int		i;
	t_flist	*tmp;

	tmp = head;
	i = 0;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	arr_colors(char *s, int **arr, int **arr_color)
{
	int		i;
	int		j;
	char	**sabian;

	i = 0;
	j = ft_num_words(s, ' ');
	*arr_color = (int *)malloc(sizeof(int) * j);
	*arr = (int *)malloc(sizeof(int) * j);
	if (!(*arr_color) || !(*arr))
		return ;
	sabian = ft_strsplit(s, ' ');
	while (i < j)
	{
		(*arr)[i] = ft_atoi(sabian[i]);
		(*arr_color)[i] = get_laid_with_color(sabian[i]);
		if ((*arr_color)[i] == 0)
			(*arr_color)[i] = 0x0FFFFFF;
		i++;
	}
	free_double(sabian);
}

void	change_x(t_fdf *fdf, float a)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->vertic)
	{
		j = 0;
		while (j < fdf->horiz)
		{
			fdf->cor[i][j].xn += a;
			j++;
		}
		i++;
	}
}

void	change_y(t_fdf *fdf, float a)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->vertic)
	{
		j = 0;
		while (j < fdf->horiz)
		{
			fdf->cor[i][j].yn += a;
			j++;
		}
		i++;
	}
}

void	error(void)
{
	ft_putendl("usage: ./fdf source_file");
	exit(0);
}
