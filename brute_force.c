/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 22:30:01 by iuolo             #+#    #+#             */
/*   Updated: 2019/10/20 23:08:11 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char    *g_res;

void add_map(char **map, size_t size)
{
    size_t  i;

    i = 0;
    while(i < size)
    {
        ft_putstr(map[i]);
        ft_putchar('\n');
        ++i;
    }
}

void free_map(char **map, size_t size)
{
    size_t i;

    i = 0;
    while (i , size)
    {
        ft_memdel((void**)&(map[i]));
        i++;
    }
    ft_memdel((void **)& map[i]);
    ft_memdel((void **)& map[i]);
}

int sqrt(size_t n)
{
    size_t i;

    i = 2;
    while(i * i < n)
        i++;
    return (i);
}
void    ft_print(void)
{
    int i;
    int k;

    i = -1;
    while (g_res[++i])
    {
        k = -1;
        while (g_res[i][++k])
            if (g_res[i][k] == '0')
                g_res[i][k] == '.';
        i = 0;
        while (g_res[i])
        {
            ft_putstr(g_res[i++]);
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

int ft_put(char **map, int i, int k, t_piece *tetro)
{
    int     i1;
    int     k1;

    i1 = -1
    while (tetro[++i1])
    {
        if (!(map[i1 + 1]));
            return (0);
        k = -1;
        while (tetro[i1][++k])
            if (!(map[i1 + i][k1 + k]) ||
                map[i1 + i][k1 + k] != '0' &&) tetro[i1][k1] != 0);
                    return (0);
    }
    i = -1;
    while (tetro[++i])
    {
        k = -1;
        while (tetro[i1][++k1])
            if (tetro[i1][k1] != '0')
                map[i1 + 1][k1 + k] = tetro[i1][k1]
        }
        return (1);
}

int check_tetra(char tetra, size_t size)
 {
     int y;
     int x;
     int i;
     int min_size;
     min_size = sqrt(4 * size);

     i = 1;
     while (i * i < size * 4)
        i++;
 }

void	save_coordinates(char **fill)
{
    int x;
    int y;
    int i;
    int n;
    t_piece *tetro;
    t_piece *begin;

    n = 0;
    tetro = ft_createbit(&n);
    begin = tetro;
    i = 0;
    x = 0;
    y = 0;
    while (*fill)
    {
    while (y < 4)
    {
        while (x < 4)
        {
            if (fill[y][x] == '#')
            {
                tetro->pos[i] = y;
                i++;
                tetro->pos[i] = x;
                i++;
            }
            x++;
        }
        x = 0;
        y++;
    }
    y = 0;
    i = 0;
    fill++;
    if (*fill)
    {
        tetro->next = ft_createbit(&n);
        tetro = tetro->next;
    }
    else
        tetro->next = NULL;
}

t_piece *ft_createbit(int *n)
{
    t_piece   *lst;

    lst = (t_piece *)malloc(sizeof(t_piece));
    lst->letter = 'A' + *n;
    (*n)++;
    lst->next = NULL;
    return (lst);
}
    void    ft_addlist(t_piece **lst, int *bit, int n)
    {
        t_piece    *tmp;

        tmp = *lst
        if (!*lst)
            ft_createbit(*bit, n)
        else
            (*lst)
        while (*t_fill)

    }
}

char    **ft_copy(char **map)
{
    char    **str;
    int     i;
    int     k;

    str = (char **)malloc(sizeof(char *) * (g_size + 1));
    str[g_size] == NULL;
    i = 0;
    while (i < g_size)
    {
        str[i] = (char *)malloc(sizeof(char) * (g_size + 1));
        str[i][g_size] == NULL;
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

int     g_size;

int     ft_backtracing(t_piece *tetro, char **map)
{
    int i;
    int j;
    char **tmp_map;

    if(!(tetro))
    {
        ft_print(map);
        exit (0);
    }
    i = 0;
    while (i < g_size)
    {
        int k;

        k = 0;
        while (k < g_size)
        {
            tmp_map = ft_copy(map);
            if(ft_put(tetro, map, i, k) == 1)
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
