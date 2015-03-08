/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 20:14:03 by gpueo--g          #+#    #+#             */
/*   Updated: 2015/03/04 16:30:43 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		init_start(t_start *start)
{
	start->deplacementx = 0;
	start->deplacementy = 0;
	start->zoom = 10;
}

int			main(int ac, char **av)
{
	t_mlx		s_libx;
	int			fd;

	if (nb_arg(ac) == 0)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (val_fd(fd) == 0)
		return (0);
	init_start(&s_libx.start);
	s_libx.list = check_map(fd);
	init(&s_libx);
	init_window(&s_libx);
	mlx_hook(s_libx.win, 2, 1, key_hook, &s_libx);
	mlx_expose_hook(s_libx.win, fdf_expose, &s_libx);
	mlx_loop_hook(s_libx.win, key_hook, &s_libx);
	init_hook(&s_libx);
	mlx_loop(s_libx.mlx);
	return (0);
}
