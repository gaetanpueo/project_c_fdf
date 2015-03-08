/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 20:14:03 by gpueo--g          #+#    #+#             */
/*   Updated: 2015/03/04 16:30:43 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		add_elem(t_coord **list, t_coord *elem)
{
	t_coord		*prov;

	prov = *list;
	if (!*list)
	{
		elem->next = NULL;
		*list = elem;
	}
	else
	{
		while (prov->next != NULL)
			prov = prov->next;
		prov->next = elem;
		elem->next = NULL;
	}
}

t_coord		*make_elem(int line, int col, char *alt)
{
	t_coord		*elem;

	elem = (t_coord *)malloc(sizeof(t_coord));
	if (elem == NULL)
		return (NULL);
	elem->x = line;
	elem->y = col;
	elem->z = ft_atoi(alt);
	elem->next = NULL;
	return (elem);
}

void		make_list(t_coord **list, char **str)
{
	static int	line;
	int			col;
	t_coord		*elem;

	col = 0;
	if (!*list)
		line = 0;
	while (str[col])
	{
		elem = make_elem(line, col, str[col]);
		add_elem(&*list, elem);
		col++;
	}
	line++;
}

t_coord		*check_map(int fd)
{
	int		res;
	char	*l0;
	char	**l1;
	t_coord	*list;

	res = 0;
	l0 = NULL;
	l1 = NULL;
	while ((res = get_next_line(fd, &l0)))
	{
		l1 = ft_strsplit(l0, ' ');
		make_list(&list, l1);
		ft_memdel((void *)&l0);
		ft_memdel_2d(l1);
	}
	return (list);
}
