/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrandr <tolrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:00:19 by tolrandr          #+#    #+#             */
/*   Updated: 2024/08/14 12:59:13 by tolrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	**ft_get_map(char *file, int size_x, int size_y)
{
	int		fd;
	int		i;
	int		j;
	char	*buffer;
	char	**string;

	fd = open(file, O_RDONLY);
	string = ft_alloc(size_x, size_y);
	buffer = (char *)malloc(sizeof(char) * 1);
	if (fd == -1 || !string || !buffer)
		return (ft_free(string, size_y), NULL);
	i = 0;
	j = 0;
	while (read(fd, buffer, 1))
	{
		if (buffer[0] != '\n')
			string[j][i++] = buffer[0];
		if (buffer[0] == '\n')
		{
			string[j][i] = '\0';
			i = 0;
			j++;
		}
	}
	return (free(buffer), string);
}

char	**ft_get_length(char *file, int size_y)
{
	int		fd;
	int		size_x;
	char	*buffer;
	char	**string;
	char	**string2;

	fd = open(file, O_RDONLY);
	buffer = (char *)malloc(sizeof(char));
	if (fd == -1 || !buffer)
		return (NULL);
	size_x = 0;
	while (read(fd, buffer, 1))
	{
		if (buffer[0] != '\n')
			size_x++;
		if (buffer[0] == '\n')
			break ;
	}
	close(fd);
	free(buffer);
	string = ft_get_map(file, size_x, size_y);
	string2 = ft_get_map(file, size_x, size_y);
	if (string == NULL || !ft_map_validate(string, size_x, size_y))
		return (ft_free(string, size_y), ft_free(string2, size_y), NULL);
	return (string2);
}

int	ft_same_line(int fd, char *buffer)
{
	int		i;
	int		temp;
	int		start;

	i = 0;
	start = 1;
	while (read(fd, buffer, 1))
	{
		if (start && buffer[0] == '\n')
		{
			temp = i;
			start = 0;
		}
		if (buffer[0] == '\n')
		{
			if (i != temp)
				return (close(fd), free(buffer), 0);
			temp = i;
			i = 0;
		}
		else if (buffer[0] != '\n')
			i++;
	}
	return (free(buffer), close(fd), 1);
}

char	**ft_error(char *file)
{
	int		fd;
	int		size;
	char	**string;
	char	*buffer;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ((void *)1);
	size = ft_count_line(fd);
	fd = open(file, O_RDONLY);
	buffer = (char *)malloc(sizeof(char));
	if (fd == -1 || !buffer)
		ft_quit(buffer);
	if (!ft_same_line(fd, buffer))
		return (close(fd), NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1 || !ft_check_map(fd, size))
		return (close(fd), NULL);
	close(fd);
	string = ft_get_length(file, size);
	if (!string)
		return (NULL);
	return (string);
}
