/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrandr <tolrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:04:50 by tolrandr          #+#    #+#             */
/*   Updated: 2024/05/27 14:18:06 by tolrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_mouse(t_event *event)
{
	ft_close(event, 0);
	return (0);
}

void	ft_event(t_ptr *ptr, char **string, t_grid *grid, t_map map)
{
	t_event		event;
	t_player	player;
	t_enemy		enemy;

	event.ptr = ptr;
	event.pos = ft_get_pos(string, grid->width, grid->height);
	event.string = string;
	event.map = map;
	event.grid = grid;
	ft_player(&player);
	event.player = player;
	enemy = ft_enemy(&event);
	ft_enemy_init(&enemy);
	event.enemy = enemy;
	ft_enemy_loop(&event);
	mlx_string_put(ptr->mlx, ptr->win, 5,
		((grid->height + 1) * 50) + 25, 0xFFFFFF, "Moves  :  0");
	if (!mlx_hook(ptr->win, 2, 1L << 0, &ft_events, &event))
		ft_free(string, grid->height);
	mlx_hook(ptr->win, 17, 0L, ft_mouse, &event);
	mlx_loop(ptr->mlx);
}

t_map	ft_get__(char **string, t_grid *grid)
{
	int		i;
	int		j;
	t_map	map;

	map = ft_init(map);
	j = 0;
	while (j <= grid->height)
	{
		i = 0;
		while (i < grid->width)
		{
			if (string[j][i] == 'C')
				map.item++;
			else if (string[j][i] == 'X')
				map.enemy++;
			i++;
		}
		j++;
	}
	return (map);
}

int	main(int argc, char *argv[])
{
	t_ptr	ptr;
	char	**string;
	t_grid	grid;
	t_map	map;

	if (argc != 2)
		return (error(1), 0);
	if (!ft_extension(argv[1]))
		return (error(2), 0);
	string = ft_error(argv[1]);
	if (string == (void *)1)
		return (error(4), 0);
	else if (!string)
		return (error(3), 0);
	grid = ft_get_window(argv[1]);
	if (!ft_window(&ptr, &grid))
		return (ft_free(string, grid.height), error(0), 0);
	ft_fill_map(string, &ptr, &grid);
	map = ft_get__(string, &grid);
	ft_event(&ptr, string, &grid, map);
	ft_free(string, grid.height);
	return (0);
}
