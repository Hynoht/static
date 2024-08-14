/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrandr <tolrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:18:55 by tolrandr          #+#    #+#             */
/*   Updated: 2024/05/27 11:50:37 by tolrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_content(int fd, char *temp, int n)
{
	int		read_file;
	char	*string;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	string = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (string == NULL)
		return (NULL);
	while (n == 1)
	{
		read_file = read(fd, string, BUFFER_SIZE);
		if (read_file == 0)
			break ;
		if (read_file == -1)
		{
			free(string);
			return (NULL);
		}
		string[read_file] = '\0';
		temp = ft_temp(temp, string);
		if (ft_check(temp) == 1)
			n = 0;
	}
	free(string);
	return (temp);
}

int	ft_strlen_n(char *string)
{
	int	i;
	int	length;
	int	start;

	i = 0;
	length = 0;
	start = 1;
	while (string[i] != '\0')
	{
		if (start == 1 && string[i] != '\n')
			length++;
		else
			start = 0;
		i++;
	}
	return (i);
}

char	*ft_get_line(char *string)
{
	int		i;
	char	*str;

	if (!string)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen_n(string) + 2));
	if (str == NULL)
	{
		free(string);
		return (NULL);
	}
	i = 0;
	while (string[i] != '\n' && string[i] != '\0')
	{
		str[i] = string[i];
		i++;
	}
	if (ft_check(string) == 1)
	{
		str[i++] = '\n';
		str[i] = '\0';
	}
	else
		str[i] = '\0';
	return (str);
}

char	*ft_get_next_line(char *string)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!string)
		return (NULL);
	if (ft_check(string) == 1)
		while (string[i] != '\n')
			i++;
	else
	{
		free(string);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(string) - i) + 1);
	if (str == NULL)
		return (NULL);
	j = 0;
	i++;
	while (string[i] != '\0')
		str[j++] = string[i++];
	str[j] = '\0';
	free(string);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*string = NULL;
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	string = ft_get_content(fd, string, 1);
	if (!string || *string == '\0')
	{
		free(string);
		return (NULL);
	}
	line = ft_get_line(string);
	string = ft_get_next_line(string);
	return (line);
}
