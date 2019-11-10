/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 20:55:37 by iuolo             #+#    #+#             */
/*   Updated: 2019/10/30 20:58:01 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			g_size;

char		**ft_create_map(void)
{
	int		i;
	int		k;
	char	**tmp;

	i = 0;
	if (!(tmp = (char **)malloc(sizeof(char*) * (g_size + 1))))
		return (NULL);
	while (i < g_size)
	{
		tmp[i] = malloc(sizeof(char) * (g_size + 1));
		i++;
	}
	i = 0;
	while (i < g_size)
	{
		k = 0;
		while (k < g_size)
		{
			tmp[i][k] = '0';
			k++;
		}
		tmp[i][k] = '0';
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

void	ft_printmap(char **map)
{
	int i;
	int k;

	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == '0')
				map[i][k] = '.';
			k++;
		}
		i++;
	}
	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

int		ft_clean(char **map)
{
	int i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	return (0);
}
