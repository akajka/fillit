/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:06:33 by akorobov          #+#    #+#             */
/*   Updated: 2018/11/22 18:45:07 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			valid_test_line(char *line, int k)
{
	size_t	i;

	i = 0;
	if (line == NULL)
		return (1);
	while ((line[i] == '#' || line[i] == '.') && line[i] != '\0')
		i++;
	if (ft_strlen(line) == 4 && i == ft_strlen(line) && line[0] != '\0')
		return (1);
	else if (line[0] == '\0' && (k + 1) % 5 == 0)
		return (1);
	else
		return (0);
}

int			valid_test_figure(char **arr)
{
	int		i;
	int		j;
	int		c;

	i = 0;
	c = 0;
	while (arr[i] && i < 4)
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '#')
			{
				CHECK_POSITION(j + 1, CHECK_SHARP(arr[i][j + 1], c));
				CHECK_POSITION(j - 1, CHECK_SHARP(arr[i][j - 1], c));
				CHECK_POSITION(i + 1, CHECK_SHARP(arr[i + 1][j], c));
				CHECK_POSITION(i - 1, CHECK_SHARP(arr[i - 1][j], c));
			}
			j++;
		}
		i++;
	}
	CHECK_VAL_FIG(c);
}

int			valid_test_square(char **arr)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (arr[i] && i < 4)
	{
		k = 0;
		while (arr[i][k])
		{
			if (arr[i][k] == '#')
				j--;
			else if (arr[i][k] == '.')
				j++;
			k++;
		}
		i++;
	}
	if (j == 8)
		if (valid_test_figure(arr) == 1)
			return (1);
	return (0);
}
