/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrandr <tolrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:37:19 by tolrandr          #+#    #+#             */
/*   Updated: 2024/08/14 13:07:19 by tolrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"

typedef struct s_map
{
	int	empty;
	int	wall;
	int	exit;
	int	item;
	int	start;
}	t_map;

typedef struct s_position
{
	int	x;
	int	y;
	int	move;
}	t_position;

typedef struct s_grid
{
	int	width;
	int	height;
}	t_grid;

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
}	t_ptr;

typedef struct s_event
{
	t_ptr		*ptr;
	t_position	pos;
	t_grid		*grid;
	char		**string;
	t_map		map;
}	t_event;

int			ft_check_map(int fd, int length);
int			ft_extension(char *string);
char		**ft_error(char *file);
void		ft_update_header(char c, t_map *p);
t_map		ft_init(t_map p);
void		error(int d);
int			ft_content(t_map *map);
char		**ft_alloc(int size_x, int size_y);
void		ft_free(char **string, int length);
int			ft_map_validate(char **string, int size_x, int size_y);
t_position	ft_get_pos(char **string, int size_x, int size_y);
t_grid		ft_get_window(char *file);
void		ft_fill_map(char **string, t_ptr *ptr, t_grid *grid);
void		ft_put_img(t_ptr *ptr, char *file, int x, int y);
int			ft_window(t_ptr *ptr, t_grid *grid);
int			ft_events(int keycode, t_event *event);
void		ft_move_down(t_event *event);
void		ft_move_up(t_event *event);
void		ft_move_left(t_event *event);
void		ft_move_right(t_event *event);
void		ft_close(t_event *event, int win);
void		ft_img_up(t_event *event, int exit);
void		ft_img_down(t_event *event, int exit);
void		ft_img_left(t_event *event, int exit);
void		ft_img_right(t_event *event, int exit);
int			ft_count_line(int fd);
void		ft_quit(char *string);
char		*ft_itoa(int n);

#endif