/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrandr <tolrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:17:08 by tolrandr          #+#    #+#             */
/*   Updated: 2024/08/14 13:09:36 by tolrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_string(t_event *event)
{
	char	*string;
	char	*black;

	black = "src/textures/black.xpm";
	string = ft_itoa(event->pos.move);
	ft_put_img(event->ptr, black, 1, event->grid->height + 1);
	mlx_string_put(event->ptr->mlx, event->ptr->win, 65,
		((event->grid->height + 1) * 50) + 26, 0xFFFFFF, string);
	free(string);
}

void	ft_img_up(t_event *event, int exit)
{
	char		*road;
	static int	i;

	road = "src/textures/road.xpm";
	if (exit)
	{
		ft_put_img(event->ptr, road, event->pos.x, event->pos.y);
		event->pos.y -= 2;
		ft_put_img(event->ptr, road, event->pos.x, event->pos.y);
		ft_put_img(event->ptr, event->player.up[i], event->pos.x, event->pos.y);
	}
	else
	{
		ft_put_img(event->ptr, road, event->pos.x, event->pos.y);
		--event->pos.y;
		ft_put_img(event->ptr, road, event->pos.x, event->pos.y);
		ft_put_img(event->ptr, event->player.up[i], event->pos.x, event->pos.y);
	}
	i++;
	if (i == 3)
		i = 0;
}

void	ft_img_down(t_event *event, int exit)
{
	char		*road;
	static int	i;

	road = "src/textures/road.xpm";
	if (exit)
	{
		ft_put_img(event->ptr, road, event->pos.x, event->pos.y);
		event->pos.y += 2;
		ft_put_img(event->ptr, road, event->pos.x, event->pos.y);
		ft_put_img(event->ptr, event->player.down[i],
			event->pos.x, event->pos.y);
	}
	else
	{
		ft_put_img(event->ptr, road, event->pos.x, event->pos.y);
		++event->pos.y;
		ft_put_img(event->ptr, road, event->pos.x, event->pos.y);
		ft_put_img(event->ptr, event->player.down[i],
			event->pos.x, event->pos.y);
	}
	i++;
	if (i == 3)
		i = 0;
}

void	ft_img_left(t_event *event, int exit)
{
	char		*road;
	static int	i;

	road = "src/textures/road.xpm";
	if (exit)
	{
		ft_put_img(event->ptr, road, event->pos.x, event->pos.y);
		event->pos.x -= 2;
		ft_put_img(event->ptr, road, event->pos.x, event->pos.y);
		ft_put_img(event->ptr, event->player.left[i],
			event->pos.x, event->pos.y);
	}
	else
	{
		ft_put_img(event->ptr, road, event->pos.x, event->pos.y);
		--event->pos.x;
		ft_put_img(event->ptr, road, event->pos.x, event->pos.y);
		ft_put_img(event->ptr, event->player.left[i],
			event->pos.x, event->pos.y);
	}
	i++;
	if (i == 3)
		i = 0;
}

void	ft_img_right(t_event *event, int exit)
{
	char		*road;
	static int	i;

	road = "src/textures/road.xpm";
	if (exit)
	{
		ft_put_img(event->ptr, road, event->pos.x, event->pos.y);
		event->pos.x += 2;
		ft_put_img(event->ptr, road, event->pos.x, event->pos.y);
		ft_put_img(event->ptr, event->player.right[i],
			event->pos.x, event->pos.y);
	}
	else
	{
		ft_put_img(event->ptr, road, event->pos.x, event->pos.y);
		++event->pos.x;
		ft_put_img(event->ptr, road, event->pos.x, event->pos.y);
		ft_put_img(event->ptr, event->player.right[i],
			event->pos.x, event->pos.y);
	}
	i++;
	if (i == 3)
		i = 0;
}
