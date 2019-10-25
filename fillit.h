/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:29:54 by iuolo             #+#    #+#             */
/*   Updated: 2019/10/25 20:17:22 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define SQR_SIDE 4
# define SQR_SIZE 16
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int		g_size;
char	*normit(char *str, int *hesh);
void	findmin(int *mintop, int *minleft, int *hesh);
int		validit(int r, char *buff, int *hesh);
int		corrfigit(int *hesh);
int		*cntit(char *s, int **hesh);
int     ft_main(char **fill);


typedef struct		s_piece
{
	char			**data;
	struct s_piece	*next;
}					t_piece;

typedef struct	s_map
{
	int			size;
	char		**arr;
}				t_map;

#endif