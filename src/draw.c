/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 20:14:03 by gpueo--g          #+#    #+#             */
/*   Updated: 2015/03/04 16:30:43 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		put_pixel_img(t_coord pp, t_mlx *s_libx, int color)
{
	int			i;

	i = (s_libx->sizeline * pp.y) + (s_libx->bpp * pp.x / 8);
	if (i >= 0 && pp.x < WIDTH && pp.y < HEIGHT)
	{
		s_libx->data[i] = mlx_get_color_value(s_libx->mlx, color);
		s_libx->data[i + 1] = mlx_get_color_value(s_libx->mlx, color >> 8);
		s_libx->data[i + 2] = mlx_get_color_value(s_libx->mlx, color >> 16);
	}
}

void			position(int x, int y, int z, t_coord *p)
{
	t_coord		start;

	start.x = 50 + p->start->deplacementx;
	start.y = 400 + p->start->deplacementy;
	p->x = start.x + x * p->start->zoom + y * p->start->zoom;
	p->y = start.y + x * p->start->zoom / 2 - y * p->start->zoom / 2 - z;
}

static void		ft_draw_line_h(t_coord pd, t_coord p1, t_mlx *var, int color)
{
	int			i;
	float		slope;
	t_coord		pp;

	i = 0;
	slope = (float)pd.y / (float)pd.x;
	while (i != pd.x)
	{
		pp.x = i + p1.x;
		pp.y = slope * i + p1.y;
		put_pixel_img(pp, var, color);
		i += ft_sgn(pd.x);
	}
}

static void		ft_draw_line_v(t_coord pd, t_coord p1, t_mlx *var, int color)
{
	int			i;
	float		slope;
	t_coord		pp;

	i = 0;
	slope = (float)pd.x / (float)pd.y;
	while (i != pd.y)
	{
		pp.x = slope * i + p1.x;
		pp.y = i + p1.y;
		put_pixel_img(pp, var, color);
		i += ft_sgn(pd.y);
	}
}

void			ft_draw_line(t_coord p1, t_coord p2, t_mlx *var, int color)
{
	t_coord		pd;

	pd.x = p2.x - p1.x;
	pd.y = p2.y - p1.y;
	if (ft_abs(pd.x) >= ft_abs(pd.y))
		ft_draw_line_h(pd, p1, var, color);
	else
		ft_draw_line_v(pd, p1, var, color);
}
