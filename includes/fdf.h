/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 20:14:03 by gpueo--g          #+#    #+#             */
/*   Updated: 2015/03/04 16:30:43 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <mlx.h>
# include <fcntl.h>

# define WIDTH		1200
# define HEIGHT		900

typedef struct		s_start
{
	int				zoom;
	int				deplacementx;
	int				deplacementy;
}					t_start;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	struct s_coord	*next;
	t_start			*start;
}					t_coord;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	t_coord			*list;
	t_start			start;
}					t_mlx;

t_coord				*check_map(int fd);
void				make_list(t_coord **list, char **str);
t_coord				*make_elem(int line, int col, char *alt);
void				add_alem(t_coord **list, t_coord elem);
int					key_hook(int keycode, t_mlx *s_libx);
int					mouse_hook(int button, int x, int y);
void				init(t_mlx *s_libx);
void				init_window(t_mlx *s_libx);
void				init_hook(t_mlx *s_libx);
void				ft_draw_line(t_coord p1, t_coord p2, t_mlx *var, int color);
void				position(int x, int y, int z, t_coord *p);
void				control_draw(t_mlx *s_libx);
int					fdf_expose(t_mlx *s_libx);
int					nb_arg(int ac);
int					val_fd(int fd);
void				repaint(t_mlx *s_libx);
void				init_start(t_start *start);

#endif
