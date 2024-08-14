/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrandr <tolrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 08:00:45 by tolrandr          #+#    #+#             */
/*   Updated: 2024/08/14 12:55:12 by tolrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_grid	ft_get_window(char *file)
{
	int		start;
	int		fd;
	char	*buffer;
	t_grid	g;

	fd = open(file, O_RDONLY);
	buffer = (char *)malloc(sizeof(char) * 1);
	start = 1;
	g.width = 0;
	g.height = 0;
	if (fd == -1 || !buffer)
		return (g);
	while (read(fd, buffer, 1))
	{
		if (buffer[0] != '\n' && start)
			g.width++;
		else if (buffer[0] == '\n')
		{
			g.height++;
			start = 0;
		}
	}
	close(fd);
	free(buffer);
	return (g);
}

void	ft_zero(t_event *event, int x, int y)
{
	event->map.item--;
	event->string[y][x] = '0';
}

void	ft_put_img(t_ptr *ptr, char *file, int x, int y)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(ptr->mlx, file, &width, &height);
	mlx_put_image_to_window(ptr->mlx, ptr->win, img, x * 50, y * 50);
	mlx_destroy_image(ptr->mlx, img);
}

void	ft_fill_map(char **string, t_ptr *ptr, t_grid *grid)
{
	int		i;
	int		j;

	j = 0;
	while (j <= grid->height)
	{
		i = 0;
		while (i < grid->width)
		{
			if (string[j][i] == '1')
				ft_put_img(ptr, "src/textures/wall.xpm", i, j);
			else if (string[j][i] == 'E')
				ft_put_img(ptr, "src/textures/exit.xpm", i, j);
			else if (string[j][i] == 'C')
				ft_put_img(ptr, "src/textures/item4.xpm", i, j);
			else if (string[j][i] == '0')
				ft_put_img(ptr, "src/textures/road.xpm", i, j);
			else if (string[j][i] == 'P')
				ft_put_img(ptr, "src/textures/right1.xpm", i, j);
			i++;
		}
		j++;
	}
}
