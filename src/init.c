/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 20:14:03 by gpueo--g          #+#    #+#             */
/*   Updated: 2015/03/04 16:30:43 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		init(t_mlx *s_libx)
{
	s_libx->mlx = mlx_init();
	s_libx->img = mlx_new_image(s_libx->mlx, WIDTH, HEIGHT);
	s_libx->data = mlx_get_data_addr(s_libx->img, &s_libx->bpp,
			&s_libx->sizeline, &s_libx->endian);
}

void		init_window(t_mlx *s_libx)
{
	s_libx->win = mlx_new_window(s_libx->mlx, WIDTH, HEIGHT, "FDF");
}

void		init_hook(t_mlx *s_libx)
{
	mlx_mouse_hook(s_libx->win, mouse_hook, &s_libx);
}

void		repaint(t_mlx *s_libx)
{
	mlx_destroy_image(s_libx->mlx, s_libx->img);
	s_libx->img = mlx_new_image(s_libx->mlx, WIDTH, HEIGHT);
	fdf_expose(s_libx);
}
