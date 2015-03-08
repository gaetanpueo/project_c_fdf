/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 20:14:03 by gpueo--g          #+#    #+#             */
/*   Updated: 2015/03/04 16:30:43 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		key_hook(int keycode, t_mlx *s_libx)
{
	if (keycode == 65307)
	{
		ft_putendl("End");
		exit (0);
	}
	if (keycode == 65451)
		s_libx->start.zoom++;
	if (keycode == 65453)
		s_libx->start.zoom--;
	if (keycode == 65363)
		s_libx->start.deplacementx++;
	if (keycode == 65361)
		s_libx->start.deplacementx--;
	if (keycode == 65364)
		s_libx->start.deplacementy++;
	if (keycode == 65362)
		s_libx->start.deplacementy--;
	repaint(s_libx);
	return (0);
}

int		mouse_hook(int button, int x, int y)
{
	(void)x;
	(void)y;
	(void)button;
	return (0);
}

int		fdf_expose(t_mlx *s_libx)
{
	control_draw(s_libx);
	mlx_put_image_to_window(s_libx->mlx, s_libx->win, s_libx->img, 0, 0);
	return (0);
}
