/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 20:14:03 by gpueo--g          #+#    #+#             */
/*   Updated: 2015/03/04 16:30:43 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int		ft_color(int z)
{
	if (z < 0)
		return (BLEUMARINE);
	if (z == 0)
		return (BLEU);
	if (z > 0)
		return (CYAN);
	return (BLEU);
}

static void		position_h(t_coord *old, t_mlx *s_libx)
{
	t_coord			min;
	t_coord			max;

	min.start = &s_libx->start;
	max.start = &s_libx->start;
	if (old->x == old->next->x)
	{
		position(old->x, old->y, old->z, &min);
		position(old->next->x, old->next->y, old->next->z, &max);
		ft_draw_line(min, max, s_libx, ft_color(old->z));
	}
}

static void		position_v(t_coord *old, t_coord *new, t_mlx *s_libx)
{
	t_coord			min;
	t_coord			max;

	min.start = &s_libx->start;
	max.start = &s_libx->start;
	if (new->x == old->x + 1)
	{
		position(old->x, old->y, old->z, &min);
		position(new->x, new->y, new->z, &max);
		ft_draw_line(min, max, s_libx, ft_color(new->z));
	}
}

static void		end_position(t_coord *old, t_coord *new, t_mlx *s_libx)
{
	t_coord			min;
	t_coord			max;

	min.start = &s_libx->start;
	max.start = &s_libx->start;
	position(new->x, new->y, new->z, &min);
	position(old->x, old->y, old->z, &max);
	ft_draw_line(min, max, s_libx, ft_color(new->z));
	old = old->next;
	while (old->next != NULL)
	{
		position(old->x, old->y, old->z, &min);
		position(old->next->x, old->next->y, old->next->z, &max);
		ft_draw_line(min, max, s_libx, ft_color(old->z));
		old = old->next;
	}
}

void			control_draw(t_mlx *s_libx)
{
	t_coord			*old;
	t_coord			*new;

	old = s_libx->list;
	new = old->next;
	while (new->x == old->x && new->next)
		new = new->next;
	while (new->next != NULL)
	{
		position_h(old, s_libx);
		position_v(old, new, s_libx);
		if (new->y == old->y)
			new = new->next;
		old = old->next;
		if (new->x == old->x)
			new = new->next;
	}
	end_position (old, new, s_libx);
}
