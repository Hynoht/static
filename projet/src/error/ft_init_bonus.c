/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrandr <tolrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:50:28 by tolrandr          #+#    #+#             */
/*   Updated: 2024/08/14 12:59:25 by tolrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
#include <stdio.h>

void	ft_update_header(char c, t_map *p)
{
	if (c == '0')
		p->empty++;
	else if (c == '1')
		p->wall++;
	else if (c == 'C')
		p->item++;
	else if (c == 'E')
		p->exit++;
	else if (c == 'P')
		p->start++;
	else if (c == 'X')
		p->enemy++;
}

t_map	ft_init(t_map p)
{
	p.empty = 0;
	p.exit = 0;
	p.item = 0;
	p.start = 0;
	p.wall = 0;
	p.enemy = 0;
	return (p);
}

void	error(int d)
{
	if (d == 0)
		printf("\033[0;31mError\n");
	else if (d == 1)
		printf("\033[0;31mError\nTry <so_long> <map.ber>\n");
	else if (d == 2)
		printf("\033[0;31mError\nCheck your extension .ber!\n");
	else if (d == 3)
		printf("\033[0;31mError\nCheck your map!\n");
	else if (d == 4)
		perror("\033[0;31mError\n404 Not found!");
}

int	ft_content(t_map *map)
{
	t_map	*p;

	p = map;
	if (p->exit != 1 || p->item < 1 || p->start != 1)
		return (0);
	return (1);
}
