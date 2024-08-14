/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrandr <tolrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:51:10 by tolrandr          #+#    #+#             */
/*   Updated: 2024/08/14 13:04:52 by tolrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../gnl/get_next_line.h"
#include "../so_long_bonus.h"

int	ft_first_line(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i] != '\n' && string[i] != '\0')
	{
		if (string[i] != '1')
			return (0);
		i++;
	}
	return (i);
}

int	ft_is(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'X'
		|| c == 'E' || c == 'P' || c == '\n')
		return (1);
	else
		return (0);
	return (1);
}

int	ft_verify_map(char *string, t_map *p, int length)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (string[i] != '\0')
	{
		if ((string[i] != '1' && j == 0)
			|| (string[i] == '\n' && string[i - 1] != '1'))
			return (0);
		if (!ft_is(string[i]))
			return (0);
		ft_update_header(string[i], p);
		if (string[i] == '\n')
		{
			if (j != length)
				return (0);
			j = 0;
		}
		i++;
		j++;
	}
	return (1);
}

int	ft_first(int fd)
{
	char	*string;
	int		size;

	string = get_next_line(fd);
	if (!string)
		free(string);
	size = ft_first_line(string);
	if (size == 0)
	{
		free(string);
		return (0);
	}
	free(string);
	return (size);
}

int	ft_check_map(int fd, int length)
{
	char	*string;
	int		i;
	int		size;
	int		size2;
	t_map	map;

	size = ft_first(fd);
	if (!size)
		return (0);
	map = ft_init(map);
	i = 0;
	while (i++ < length - 1)
	{
		string = get_next_line(fd);
		if (!ft_verify_map(string, &map, size))
			return (free(string), 0);
		free(string);
	}
	size2 = ft_first(fd);
	if (!size2 || size != size2 || size == length + 1 || !ft_content(&map))
		return (0);
	return (1);
}
