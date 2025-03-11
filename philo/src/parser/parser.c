/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:22:30 by ddias-fe          #+#    #+#             */
/*   Updated: 2025/03/11 17:13:07 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_atol(const char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] <= 13 && str[i] >= 9) || (str[i] == 32))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	parser(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac != 5 && ac != 6)
	{
		printf("Error: Wrong number of arguments\n");
		printf("Usage: ./philo [number_of_philos] [time_to_die]");
		printf(" [time_to_eat] [time_to_sleep] [number_of_meals (optional)]\n");
		return (1);
	}
	while (av[++i])
	{
		if (ft_atol(av[i]) <= 0 || ft_atol(av[i]) > 2147483647)
			return (printf("Error: Invalid arguments\n"), 1);
		j = -1;
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]))
				return (printf("Error: Invalid arguments\n"), 1);
		}
	}
	return (0);
}
