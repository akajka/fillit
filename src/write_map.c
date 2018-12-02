/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:09:47 by akorobov          #+#    #+#             */
/*   Updated: 2018/11/23 10:44:15 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_cord		*ft_coord_fig(char **arr)
{
	t_cord	*crds;
	int		x;
	int		y;
	int		k;

	crds = (t_cord*)malloc(sizeof(t_cord) * 4);
	y = 0;
	k = 0;
	while (k < 4)
	{
		x = 0;
		while (arr[y][x])
		{
			if (arr[y][x] != '.')
			{
				crds[k].x = x;
				crds[k].y = y;
				k++;
			}
			x++;
		}
		y++;
	}
	return (crds);
}

void		delete_fig(int g)
{
	int		i;
	int		j;

	i = 0;
	while (g_map[i])
	{
		j = 0;
		while (g_map[i][j])
		{
			if (g_map[i][j] == 'A' + g)
				g_map[i][j] = '.';
			j++;
		}
		i++;
	}
}

int			input_map(char **arr, t_cord *crds, int x, int y)
{
	int		k;

	k = 0;
	while (g_map[y] && g_map[y][x])
	{
		if (g_map[y][x] == '.')
		{
			g_map[y][x] = arr[crds[k].y][crds[k].x];
			k++;
			if (k == 4)
				return (1);
			y += crds[k].y - crds[k - 1].y;
			x += crds[k].x - crds[k - 1].x;
		}
		else
			break ;
	}
	return (0);
}

int			write_map(char ***arr, int g)
{
	t_cord	*crds;
	int		y;
	int		x;

	LAST_FIG(arr[g], y, crds, ft_coord_fig(arr[g]));
	while (g_map[y])
	{
		x = 0;
		while (g_map[y][x])
		{
			if (input_map(arr[g], crds, x, y) == 1)
			{
				if (write_map(arr, g + 1) == 1)
				{
					free(crds);
					return (1);
				}
			}
			delete_fig(g);
			x++;
		}
		y++;
	}
	free(crds);
	return (0);
}
