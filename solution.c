/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:00:17 by iuolo             #+#    #+#             */
/*   Updated: 2019/11/05 19:02:51 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*ft_transfer_part(char **fl, int i, int c, t_piece *tetr)
{
	int		j;
	t_piece	*tmp;

	while (fl[i])
	{
		c++;
		i += 1;
	}
	if (!(tetr = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	if (!(tetr->data = malloc(sizeof(char*) * 5)))
		return (NULL);
	(tetr->data)[4] = NULL;
	tmp = tetr;
	j = -1;
	while (++j < c - 1)
	{
		if (!(tmp->next = (t_piece *)malloc(sizeof(t_piece) * 1)))
			return (NULL);
		if (!(tmp->next->data = malloc(sizeof(char*) * 5)))
			return (NULL);
		(tmp->next->data)[4] = NULL;
		tmp = tmp->next;
	}
	return (tetr);
}
