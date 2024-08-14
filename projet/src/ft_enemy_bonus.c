/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrandr <tolrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:09:35 by tolrandr          #+#    #+#             */
/*   Updated: 2024/05/24 16:19:08 by tolrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_enemy	ft_enemy(t_event *event)
{
	int		i;
	int		j;
	int		k;
	t_enemy	enemy;

	enemy.x = (int *)malloc(sizeof(int) * event->map.enemy + 1);
	enemy.y = (int *)malloc(sizeof(int) * event->map.enemy + 1);
	if (!enemy.x || !enemy.y)
		ft_close(event, 0);
	j = 0;
	k = 0;
	while (++j <= event->grid->height)
	{
		i = 0;
		while (++i < event->grid->width)
		{
			if (event->string[j][i] == 'X')
			{
				enemy.x[k] = i;
				enemy.y[k] = j;
				k++;
			}
		}
	}
	return (enemy);
}

int	ft_loop(t_event *event)
{
	static int	i;
	int			j;

	j = 0;
	while (j < event->map.enemy)
	{
		ft_put_img(event->ptr, event->enemy.file[i],
			event->enemy.x[j], event->enemy.y[j]);
		j++;
	}
	usleep(60000);
	i++;
	if (i == 4)
		i = 0;
	return (0);
}

void	ft_enemy_loop(t_event *event)
{
	mlx_loop_hook(event->ptr->mlx, ft_loop, event);
}
