/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:31:12 by ntrusevi          #+#    #+#             */
/*   Updated: 2018/11/23 11:29:16 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define MALLOCCH(x) if (!x) {free(x); exit(EXIT_FAILURE);}
# define VALID_TEST(x, y) if (x != 1) {free(y); ERROR;}
# define NEXT(x, y) x = 0; y++;
# define BREAK(x) if (x == 0) break ;
# define MANY_SQ_TEST(x, y) if (x[27] != NULL) {free(x); ERROR;}
# define LAST_SQUARE(x) free(x); x = NULL;
# define CHECK_SHARP(x, y) if (x == '#') y++
# define CHECK_POSITION(x, y) if (x >= 0 && x < 4) y;
# define CHECK_VAL_FIG(x) if (x == 6 || x == 8) return (1); else return (0);
# define CHECK_FIGURE(j, x, y) if (x >= j - 1  || y >= j - 1 )  return (0);
# define LAST_FIG(x, y, z, q) y = 0; if (x == NULL) return (1); z = q;
# define ERROR ft_putendl("error"); exit(EXIT_FAILURE);
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct	s_coords
{
	int			x;
	int			y;
}				t_cord;

char			**g_map;
int				main(int argc, char **argv);
void			check_map(char ***arr);
int				valid_test_line(char *line, int k);
int				valid_test_figure(char **arr);
int				valid_test_square(char **arr);
void			create_map(char ***arr);
void			change_sharp(char **arr, int k);
void			new_map(int j);
int				write_map(char ***arr, int g_fig);
t_cord			*ft_coord_fig(char **arr);
int				input_map(char **arr, t_cord *crds, int x, int y);
void			delete_fig(int g);

#endif
