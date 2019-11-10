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
