/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 09:09:51 by akorobov          #+#    #+#             */
/*   Updated: 2018/11/23 10:23:06 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		change_sharp(char **arr, int k)
{
	int		i;
	int		j;

	i = 0;
	while (arr[i] && i < 5)
	{
		j = 0;
		while (arr[i][j] && j < 5)
		{
			if (arr[i][j] == '#')
				arr[i][j] = 'A' + k;
			j++;
		}
		i++;
	}
}

void		new_map(int j)
{
	int		i;
	int		ch;

	i = 0;
	MALLOCCH((g_map = (char **)malloc(sizeof(char *) * j)));
	while (i < j - 1)
	{
		ch = 0;
		MALLOCCH((g_map[i] = (char *)malloc(sizeof(char) * j)));
		while (ch < j - 1)
		{
			g_map[i][ch] = '.';
			ch++;
		}
		g_map[i][ch] = '\0';
		i++;
	}
	g_map[j - 1] = NULL;
}

void		memfree(void)
{
	int		i;

	i = 0;
	while (g_map[i])
	{
		free(g_map[i]);
		i++;
	}
	free(g_map);
}

void		create_map(char ***arr)
{
	int		k;
	int		j;

	j = 3;
	k = 0;
	while (arr[k])
	{
		change_sharp(arr[k], k);
		k++;
	}
	new_map(j);
	while (write_map(arr, 0) == 0)
	{
		j++;
		k = 0;
		memfree();
		new_map(j);
	}
}
