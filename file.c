/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 22:30:01 by iuolo             #+#    #+#             */
/*   Updated: 2019/11/07 00:41:15 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// char        **g_res;
int         g_size;

char **ft_create_map(void)
{
    int     i;
    int     k;
    char    **tmp;

    i = 0;
    if (!(tmp = (char **)malloc(sizeof(char*) * (g_size + 1))))
        return (NULL);
    while(i < g_size)
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

int ft_sqrt(size_t n)
{
    size_t i;

    i = 2;
    while(i * i < n)
        i++;
    return (i);
}

void    ft_printmap(char **map)
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

int     ft_clean(char **map)
{
    int i;

    i = 0;
    while (map[i])
        free(map[i++]);
    free(map);
    return (0);

}

t_piece *ft_transfer(char **fill)
{
    char **arr;
    int i;
    int k;
    int c;
    int j;
    t_piece *tmp;
    t_piece *tetr;

    i = 0;
    c = 0;
    while (fill[i])
    {
        c++;
        i += 1;
    }
    if (!(tetr = (t_piece*)malloc(sizeof(t_piece))))
        return (NULL);
    if(!(tetr->data = malloc(sizeof(char*) * 5)))
        return (NULL);
    (tetr->data)[4] = NULL;
    tmp = tetr;
    j = 0;
    while (j < c - 1)
    {
        if (!(tmp->next = (t_piece *)malloc(sizeof(t_piece) * 1)))
            return (NULL);
        if (!(tmp->next->data = malloc(sizeof(char*) * 5)))
            return (NULL);
        (tmp->next->data)[4] = NULL;
        tmp = tmp->next;
        j += 1;
    }
    tmp->next = NULL;
    tmp = tetr;
    c = 0;
    while (tmp)
    {
        i = 0;
        arr = tmp->data;
        while (i < 4)
        {
            k = 0;
            if (!(arr[i] = malloc(sizeof(char) * 5)))
                return (NULL);
            while (k < 4)
            {
                if (fill[c][i * 4 + k] == '#')
                    fill[c][i * 4 + k] = 'A' + c;
                arr[i][k] = fill[c][i * 4 + k];
                k++;
            }
            arr[i][k] = '\0';
            i++;
        }
        c++;
        tmp = tmp->next;
    }
    return (tetr);
}

char    **ft_copy(char **map)
{
    char    **str;
    int     i;
    int     k;

    if (!(str = (char **)malloc(sizeof(char *) * (g_size + 1))))
        return (NULL);
    str[g_size] = NULL;
    i = 0;
    while (i < g_size)
    {
        if (!(str[i] = (char *)malloc(sizeof(char) * (g_size + 1))))
            return (NULL);
        str[i][g_size] = '\0';
        i++;
    }
    str[i] = NULL;
    i = 0;
    while (i < g_size)
    {
        k = 0;
        while (k < g_size)
        {
            str[i][k] = map[i][k];
            k++;
        }
        i++;
    }
    return (str);
}

// int ft_put(char **arr, char **map, int i, int k)
// {
//     int     i1;
//     int     k1;

//     i1 = -1;
//     while (arr[++i1])
//     {
//         if (!(map[i1 + 1]))
//             return (0);
//         k = -1;
//         while (arr[i1][++k1])
//             if (!(map[i1 + i][k1 + k]) ||
//                 (map[i1 + i][k1 + k] != '0' && arr[i1][k1] != 0))
//                     return (0);
//     }
//     i = -1;
//     ft_putstr("HELLO");
//     while (arr[++i])
//     {
//         k = -1;
//         while (arr[i1][++k1])
//             if (arr[i1][k1] != '0')
//                 map[i1 + 1][k1 + k] = arr[i1][k1];
//     }
//     return (1);
// }

int			ft_put(char **field, int i, int k, char **fg)
{
	int i1;
	int k1;

	i1 = -1;
	while (fg[++i1])
	{
		if (!(field[i1 + i]))
			return (0);
		k1 = -1;
		while (fg[i1][++k1])
			if (!(field[i1 + i][k1 + k]) ||
					(field[i1 + i][k1 + k] != '0' && fg[i1][k1] != '.'))
				return (0);
	}
	i1 = -1;
	while (fg[++i1])
	{
		k1 = -1;
		while (fg[i1][++k1])
			if (fg[i1][k1] != '.')
				field[i1 + i][k1 + k] = fg[i1][k1];
	}
	return (1);
}

int     ft_backtracking(t_piece *tetro, char **map)
{
    int i;
    int j;
    char **tmp_map;
    int k;
    int err;

    if(!(tetro))
    {
        ft_printmap(map);
        exit (0);
    }
    i = -1;
    while (++i < g_size)
    {
        k = -1;
        while (++k < g_size)
        {
			if (!(tmp_map = ft_copy(map)))
				return (-1);
			if ((err = ft_put(tmp_map, i, k, tetro->data)) == 1)
			{
				if ((err = ft_backtracking(tetro->next, tmp_map)) == 1)
					return (1);
				else if (err == -1)
					return (-1);
			}
            ft_clean(tmp_map);
        }
    }
    return (0);
}

int     ft_slice(t_piece *tetro)
{
    int i;
    int k;
    int max_h;
    int max_l;
    char **arr;
    t_piece *tmp;

    tmp = tetro;
    while (tmp)
    {
        arr = tmp->data;
        i = 0;
        max_h = 0;
        max_l = 0;
        while (arr[i])
        {
            k = -1;
            while (arr[i][++k])
                if (arr[i][k] != '.' && max_l - 1 < k)
                    max_l = k + 1;
            if (arr[i][0] != '.' || arr[i][1] != '.' || arr[i][2] != '.' || arr[i][3] != '.')
                max_h = i + 1;
            i++;
        }
        i = 0;
        while (i < max_h)
        {
            arr[i][max_l] = '\0';
            i++;
        }
        arr[i] = NULL;
        tmp = tmp->next;
    }
    return (1);
}

int     ft_solver(char **fill)
{
    int i;
    int k;
    char **map;
    t_piece *tetro;

    if (!(tetro = ft_transfer(fill)))
        return (-1);
    if (!(ft_slice(tetro)))
        return (-1);
    i = 1;
    g_size = 1;
    while (1)
    {
        if (!(map = ft_create_map()))
        {
            ft_putstr("hui1\n");
            return (-1);
        }
        if (ft_backtracking(tetro, map) == -1)
        {
            ft_putstr("hui2\n");
            ft_clean(map);
            return (-1);
        }
        ft_clean(map);
        g_size++;
    }
}