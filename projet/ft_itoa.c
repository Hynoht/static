/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrandr <tolrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:04:47 by tolrandr          #+#    #+#             */
/*   Updated: 2024/08/14 13:08:21 by tolrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static int	ft_nbr(int n)
{
	int	i;

	i = 0;
	while (n != '\0')
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_fillitoa(char *string, int length, int is_neg, int n)
{
	string[length--] = '\0';
	if (n == 0)
		string[length--] = '0';
	while (length >= 0)
	{
		string[length--] = n % 10 + '0';
		n /= 10;
	}
	if (is_neg == 1)
		string[0] = '-';
	if (is_neg == 2)
	{
		string[0] = '-';
		string[strlen(string) - 1] = '8';
	}
	return (string);
}

char	*ft_itoa(int n)
{
	int		is_neg;
	int		length;
	char	*string;

	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		n = -n;
	}
	if (n == -2147483648)
	{
		is_neg = 2;
		n = n - 1;
	}
	length = ft_nbr(n);
	if (n == 0)
		length = 1;
	if (is_neg == 1 || is_neg == 2)
		length++;
	string = (char *)malloc(sizeof(char) * length + 1);
	if (string == NULL)
		return (NULL);
	return (ft_fillitoa(string, length, is_neg, n));
}
