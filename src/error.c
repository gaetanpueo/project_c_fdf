/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 20:14:03 by gpueo--g          #+#    #+#             */
/*   Updated: 2015/03/04 16:30:43 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		nb_arg(int ac)
{
	if (ac < 2)
	{
		ft_putendl("No file");
		return (0);
	}
	return (1);
}

int		val_fd(int fd)
{
	if (fd <= 0)
	{
		ft_putendl("Error file");
		return (0);
	}
	return (1);
}
