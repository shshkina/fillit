/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 22:30:01 by iuolo             #+#    #+#             */
/*   Updated: 2019/10/23 20:06:30 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char        **g_res;
int         g_size;

char **ft_create_map(size_t size)
{
    int     i;
    int     k;
    char    **tmp;

    i = 0;
    if (!(tmp = (char **)malloc(sizeof(char*) * (size + 1))))
        return (NULL);
    tmp[size] = NULL;
    while(i < size)
    {
        tmp[i] = malloc(sizeof(char) * (size + 1));
        tmp[i][size] = '\0';
        i++;
    }
    i = 0;
    while (i < size)
    {
        k = 0;
        while (k < size)
        {
            tmp[i][k] = '0';
            k++;
        }
        i++;
    }
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

    i = -1;
    while (g_res[++i])
    {
        ft_putstr(g_res[i]);
        ft_putchar('\n');
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

int ft_put(char **arr, char **map, int i, int k)
{
    int     i1;
    int     k1;

    i1 = -1;
    while (arr[++i1])
    {
        if (!(map[i1 + 1]))
            return (0);
        k = -1;
        while (arr[i1][++k1])
            if (!(map[i1 + i][k1 + k]) ||
                (map[i1 + i][k1 + k] != '0' && arr[i1][k1] != 0))
                    return (0);
    }
    i = -1;
    while (arr[++i])
    {
        k = -1;
        while (arr[i1][++k1])
            if (arr[i1][k1] != '0')
                map[i1 + 1][k1 + k] = arr[i1][k1];
    }
    return (1);
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
        if (fill[i][0] == '\n')
            i++;
        if (!(fill[i][0]))
            break ;
        c++;
        i += 4;
    }
    if (!(tetr = (t_piece*)malloc(sizeof(t_piece))))
        return (NULL);
    if(!(tmp->data = malloc(sizeof(char*) * 5)))
        return (NULL);
    (tmp->data)[4] = NULL;
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
        tmp->next = NULL;
    }
    tmp = tetr;
    c = 0;
    while (tmp)
    {
        i = 0;
        while (i < 4)
        {
            k = 0;
            if (!(arr[i] = malloc(sizeof(char) * 5)))
                return (NULL);
            while (k < 4)
            {
                arr[i][k] = fill[c][k];
                   k++;
            }
            arr[i][k] = '\0';
            i++;
            c++;
        }
        c++;
        tmp = tmp->next;
    }
    ft_clean(fill);
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
        str[i][g_size] = 0;
        i++;
    }
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

int     ft_backtracking(t_piece *tetro, char **map)
{
    int i;
    int j;
    char **tmp_map;

    if(!(tetro))
    {
        ft_printmap(map);
        exit (0);
    }
    i = 0;
    while (i < g_size)
    {
        int k;

        k = 0;
        while (k < g_size)
        {
            if (!(tmp_map = ft_copy(map)))
                return (-1);
            if(ft_put(tetro->data, map, i, k) == 1)
                if (ft_backtracking(tetro->next, map) == 0)
                    continue ;
            ft_clean(map);
            map = tmp_map;
            ft_clean(tmp_map);
            k++;
        }
        i++;
    }
    return (0);
}

int     ft_main(char **fill, size_t size)
{
    int i;
    int k;
    char **map;
    t_piece *tetro;

    if (!(tetro = ft_transfer(fill)))
        return (-1);
    i = 1;
    while (1)
    {
        if (!(map = ft_create_map(size)))
            return (-1);
        if (ft_backtracking(tetro, map) == -1)
        {
            ft_clean(map);
            return (-1);
        }
        i++;
    }
}
