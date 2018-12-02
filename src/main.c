/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:07:11 by akorobov          #+#    #+#             */
/*   Updated: 2018/11/23 10:25:33 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		***create_array3d(int fd)
{
	int		i;
	int		k;
	int		ch;
	char	***arr;

	k = 0;
	i = 0;
	MALLOCCH((arr = (char ***)malloc(sizeof(char **) * 27)));
	MALLOCCH((arr[k] = (char **)malloc(sizeof(char *) * 5)));
	while ((ch = get_next_line(fd, &arr[k][i])) == 1 || ch == 0)
	{
		VALID_TEST(valid_test_line(arr[k][i], i), arr);
		i++;
		if (i % 5 == 0 || ch == 0)
		{
			VALID_TEST(valid_test_square(arr[k]), arr);
			NEXT(i, k);
			if (k <= 27)
				MALLOCCH((arr[k] = (char **)malloc(sizeof(char *) * 5)));
		}
		BREAK(ch);
	}
	MANY_SQ_TEST(arr, k);
	LAST_SQUARE(arr[k]);
	return (arr);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	***arr;
	int		k;

	k = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		arr = create_array3d(fd);
		create_map(arr);
		while (g_map[k])
			ft_putendl(g_map[k++]);
	}
	else
		ft_putendl("usage: fillit sample_file.txt");
	return (0);
}
