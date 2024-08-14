/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrandr <tolrandr@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:09:15 by tolrandr          #+#    #+#             */
/*   Updated: 2024/03/14 14:09:16 by tolrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_temp(char *temp, char *string)
{
	if (temp == NULL)
		temp = ft_strdup(string);
	else if (temp != NULL && *string != '\0')
		temp = ft_strjoin(temp, string);
	return (temp);
}

int	ft_strlen(const char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		length;
	char	*join;

	length = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) * (length + 1));
	if (join == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		join[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		join[j++] = s2[i++];
	join[j] = '\0';
	free(s1);
	return (join);
}

char	*ft_strdup(char *s)
{
	int		length;
	int		i;
	char	*str;

	length = ft_strlen(s);
	str = (char *)malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_check(char *string)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '\n')
			return (found = 1);
		i++;
	}
	return (found);
}
