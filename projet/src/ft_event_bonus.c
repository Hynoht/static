/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrandr <tolrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:33:33 by tolrandr          #+#    #+#             */
/*   Updated: 2024/08/14 12:58:51 by tolrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_events(int keycode, t_event *event)
{
	if (keycode == 'w')
		ft_move_up(event);
	else if (keycode == 's')
		ft_move_down(event);
	else if (keycode == 'a')
		ft_move_left(event);
	else if (keycode == 'd')
		ft_move_right(event);
	else if (keycode == 65307)
	{
		ft_close(event, 0);
	}
	ft_put_string(event);
	return (0);
}

void	ft_move_up(t_event *event)
{
	int		x;
	int		y;

	x = event->pos.x;
	y = event->pos.y;
	if (event->string[--y][x] != '1')
	{
		if (event->string[y][x] == 'C')
			ft_zero(event, x, y);
		if (event->string[y][x] == 'E' && event->map.item == 0)
			ft_close(event, 1);
		else if (event->string[y][x] == 'E' && event->map.item > 0
			&& event->string[y - 1][x] != '1')
		{
			ft_img_up(event, 1);
			return ;
		}
		else if (event->string[y][x] == 'X')
			ft_close(event, 2);
		else if (event->string[y][x] == 'E')
			return ;
		ft_img_up(event, 0);
		event->pos.move++;
	}
}

void	ft_move_down(t_event *event)
{
	int		x;
	int		y;

	x = event->pos.x;
	y = event->pos.y;
	if (event->string[++y][x] != '1')
	{
		if (event->string[y][x] == 'C')
			ft_zero(event, x, y);
		if (event->string[y][x] == 'E' && event->map.item == 0)
			ft_close(event, 1);
		else if (event->string[y][x] == 'E' && event->map.item > 0
			&& event->string[y + 1][x] != '1')
		{
			ft_img_down(event, 1);
			return ;
		}
		else if (event->string[y][x] == 'X')
			ft_close(event, 2);
		else if (event->string[y][x] == 'E')
			return ;
		ft_img_down(event, 0);
		event->pos.move++;
	}
}

void	ft_move_left(t_event *event)
{
	int		x;
	int		y;

	x = event->pos.x;
	y = event->pos.y;
	if (event->string[y][--x] != '1')
	{
		if (event->string[y][x] == 'C')
			ft_zero(event, x, y);
		if (event->string[y][x] == 'E' && event->map.item == 0)
			ft_close(event, 1);
		else if (event->string[y][x] == 'E' && event->map.item > 0
			&& event->string[y][x - 1] != '1')
		{
			ft_img_left(event, 1);
			return ;
		}
		else if (event->string[y][x] == 'X')
			ft_close(event, 2);
		else if (event->string[y][x] == 'E')
			return ;
		ft_img_left(event, 0);
		event->pos.move++;
	}
}

void	ft_move_right(t_event *event)
{
	int		x;
	int		y;

	x = event->pos.x;
	y = event->pos.y;
	if (event->string[y][++x] != '1')
	{
		if (event->string[y][x] == 'C')
			ft_zero(event, x, y);
		if (event->string[y][x] == 'E' && event->map.item == 0)
			ft_close(event, 1);
		else if (event->string[y][x] == 'E' && event->map.item > 0
			&& event->string[y][x + 1] != '1')
		{
			ft_img_right (event, 1);
			return ;
		}
		else if (event->string[y][x] == 'X')
			ft_close(event, 2);
		else if (event->string[y][x] == 'E')
			return ;
		ft_img_right (event, 0);
		event->pos.move++;
	}
}
