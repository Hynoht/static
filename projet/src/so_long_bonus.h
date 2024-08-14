/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrandr <tolrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:37:19 by tolrandr          #+#    #+#             */
/*   Updated: 2024/05/27 14:15:31 by tolrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"

typedef struct s_map
{
	int	empty;
	int	wall;
	int	exit;
	int	item;
	int	start;
	int	enemy;
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

typedef struct s_player
{
	char	**up;
	char	**down;
	char	**left;
	char	**right;
}	t_player;

typedef struct s_enemy
{
	char	**file;
	int		*x;
	int		*y;
}	t_enemy;

typedef struct s_event
{
	t_ptr		*ptr;
	t_position	pos;
	t_grid		*grid;
	char		**string;
	t_map		map;
	t_player	player;
	t_enemy		enemy;
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
void		ft_player(t_player *player);
void		ft_enemy_init(t_enemy *enemy);
t_enemy		ft_enemy(t_event *event);
int			ft_loop(t_event *event);
void		ft_enemy_loop(t_event *event);
void		ft_put_string(t_event *event);
void		ft_zero(t_event *event, int x, int y);
int			ft_count_line(int fd);
void		ft_quit(char *string);

#endif
