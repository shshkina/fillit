/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:08:50 by sbrynn            #+#    #+#             */
/*   Updated: 2019/11/08 01:49:57 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		readit(int fd, char ***fill, int *i)
{
	int		r;
	char	buff[22];
	char	*s;
	int		*hesh;

	*i = 0;
	while ((r = read(fd, buff, SQR_SIZE + 5)) >= 20 && *i <= 26)
	{
		buff[r] = '\0';
		hesh = ft_memalloc(sizeof(int) * 4);
		if (validit(r, buff, hesh))
		{
			s = normit(buff, hesh);
			(*fill)[*i] = s;
			(*i)++;
			free(hesh);
		}
		else
		{
			free(hesh);
			return (0);
		}
	}
	(*fill)[*i] = 0;
	return (*i > 26 ? 0 : 1);
}

void	ft_print_square(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (i % 4 == 0)
			ft_putchar('\n');
		if (i % 16 == 0)
			ft_putchar('\n');
		ft_putchar(s[i++]);
	}
}

void	ft_print(char **fill)
{
	while (*fill)
	{
		ft_print_square(*fill);
		fill++;
	}
}

void	cleanit(char ***fill, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free((*fill)[i]);
		i++;
	}
	free(*fill);
}

int		main(int ac, char **av)
{
	int		fd;
	char	**fill;
	int		i;

	if (ac == 2)
	{		
		fill = ft_memalloc(sizeof(char*) * 26);
		fd = open(av[1], O_RDONLY);
		if (!readit(fd, &fill, &i))
		{
			ft_putstr("error\n");
			return (0);
		}
		//ft_print(fill);
		ft_solver(fill);
		cleanit(&fill, i);
	}
	else
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (1);
	}
	return (0);
}
