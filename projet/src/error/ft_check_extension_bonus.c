/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrandr <tolrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:05:57 by tolrandr          #+#    #+#             */
/*   Updated: 2024/08/14 13:09:27 by tolrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_quit(char *string)
{
	if (string)
		free(string);
	perror("\033[0;31mError\n404 Not found!");
	exit (1);
}

int	ft_extension(char *string)
{
	char	*ext;

	ext = strrchr(string, '.');
	if (ext == NULL)
		return (0);
	if (strncmp(".ber\0", ext, 5) == 0)
		return (1);
	return (0);
}

int	ft_count_line(int fd)
{
	char	*buffer;
	int		size;

	buffer = (char *)malloc(sizeof(char) * 1);
	if (!buffer)
		return (0);
	size = 0;
	while (read(fd, buffer, 1))
	{
		if (buffer[0] == '\n')
			size++;
	}
	free(buffer);
	close(fd);
	return (size);
}
