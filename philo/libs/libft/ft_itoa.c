/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:54:34 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/04/09 14:54:34 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nsize(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;
	long	i;

	i = n;
	size = ft_nsize(i);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	str[size] = '\0';
	if (i < 0)
	{
		str[0] = '-';
		i *= -1;
	}
	else if (i == 0)
		str[0] = '0';
	while (i != 0)
	{
		str[--size] = (i % 10) + 48;
		i /= 10;
	}
	return (str);
}
