/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrandr <tolrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:52:00 by tolrandr          #+#    #+#             */
/*   Updated: 2024/05/24 16:19:18 by tolrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	**ft_alloc(int size_x, int size_y)
{
	int		i;
	char	**string;

	string = (char **)malloc(sizeof(char *) * (size_y + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (i < size_y + 1)
	{
		string[i] = (char *)malloc(sizeof(char) * (size_x + 1));
		if (!string[i])
			return (NULL);
		i++;
	}
	return (string);
}

void	ft_free(char **string, int length)
{
	int	i;

	i = 0;
	while (i <= length)
		free(string[i++]);
	free(string);
}
