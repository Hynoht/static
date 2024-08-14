/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validate_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrandr <tolrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 08:50:10 by tolrandr          #+#    #+#             */
/*   Updated: 2024/05/24 16:19:45 by tolrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

t_position	ft_get_pos(char **string, int size_x, int size_y)
{
	int			i;
	int			j;
	t_position	pos;

	j = 0;
	pos.x = 0;
	pos.y = 0;
	pos.move = 0;
	while (j <= size_y)
	{
		i = 0;
		while (i < size_x)
		{
			if (string[j][i] == 'P')
			{
				pos.x = i;
				pos.y = j;
			}
			i++;
		}
		j++;
	}
	return (pos);
}

int	ft_memo(char **string, int n, int m)
{
	int	valid;

	if (n < 0 || m < 0 || string[m][n] == '1' || string[m][n] == 'X')
		return (0);
	string[m][n] = '1';
	if (string[m][n] == 'C')
		string[m][n] = '1';
	valid = ft_memo(string, n + 1, m) || ft_memo(string, n - 1, m)
		|| ft_memo(string, n, m + 1) || ft_memo(string, n, m - 1);
	return (valid);
}

int	ft_map_validate(char **string, int size_x, int size_y)
{
	int			i;
	int			j;
	t_position	pos;

	pos = ft_get_pos(string, size_x, size_y);
	j = 0;
	ft_memo(string, pos.x, pos.y);
	j = 0;
	while (j <= size_y)
	{
		i = 0;
		while (i < size_x)
		{
			if (string[j][i] == 'C' || string[j][i] == 'P'
				|| string[j][i] == 'E')
				return (0);
			i++;
		}
		j++;
	}
	ft_free(string, size_y);
	return (1);
}
