/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:12:27 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/06 00:05:01 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

size_t		ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	cheak_size(long n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*n_str;
	int		len;
	int		s;
	long	num;

	num = (long)n;
	s = 0;
	if (num < 0)
	{
		num = -num;
		s = 1;
	}
	len = cheak_size(num);
	if (!(n_str = (char *)malloc(sizeof(char) * len + s + 1)))
		return (NULL);
	if (s)
		n_str[0] = '-';
	n_str[len + s] = '\0';
	while (len)
	{
		n_str[len - (s ? 0 : 1)] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (n_str);
}
