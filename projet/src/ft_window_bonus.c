/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrandr <tolrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:55:57 by tolrandr          #+#    #+#             */
/*   Updated: 2024/08/14 12:59:05 by tolrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_close(t_event *event, int win)
{
	if (win == 1)
		printf("\033[5m \033[1;32mYou win!\n\033[1 \033[0m");
	else if (win == 2)
		printf("\033[5m \033[1;31mGAME OVER!\n\033[1 \033[0m");
	if (event->player.up != NULL)
	{
		free(event->player.up);
		free(event->player.down);
		free(event->player.left);
		free(event->player.right);
	}
	if (event->enemy.file != NULL)
		free(event->enemy.file);
	if (event->enemy.x != NULL && event->enemy.y)
	{
		free(event->enemy.x);
		free(event->enemy.y);
	}
	mlx_destroy_window(event->ptr->mlx, event->ptr->win);
	mlx_destroy_display(event->ptr->mlx);
	free(event->ptr->mlx);
	ft_free(event->string, event->grid->height);
	exit (1);
}

int	ft_window(t_ptr *ptr, t_grid *grid)
{
	ptr->mlx = mlx_init();
	if (!ptr->mlx)
		return (0);
	ptr->win = mlx_new_window(ptr->mlx, grid->width * 50,
			(grid->height + 2) * 50, "so_long");
	if (!ptr->win)
	{
		mlx_destroy_display(ptr->mlx);
		free(ptr->mlx);
		return (0);
	}
	return (1);
}
