/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:07:11 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/09/30 17:26:54 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_program(int ac, char **av, t_stats *stats, t_philo **philos)
{
	if (!init_stats(ac, av, stats))
		return (printf("ERROR!!!!"), 0);
	*philos = malloc(sizeof(t_philo) * stats->philo_total);
	if (!*philos)
		return (printf("ERROR!!!!"), 0);
	init_philos(stats, *philos);
	return (1);
}

void init_philos(t_stats *stats, t_philo *philos)
{
	int i;

	i = -1;
	while (++i < stats->philo_total)
	{
		philos[i].philo_id = i + 1;
		philos[i].meals = 0;
		philos[i].last_meal = 0;
		philos[i].left_fork = i;
		philos[i].right_fork = (i + 1) % stats->philo_total;
	}
	stats->philos = philos;
}

int init_stats(int ac, char **av, t_stats *stats)
{
	if (ac == 5)
	{
		stats->philo_total = ft_atoi(av[1]);
		stats->time_to_die = ft_atoi(av[2]);
		stats->time_to_eat = ft_atoi(av[3]);
		stats->time_to_sleep = ft_atoi(av[4]);
		stats->meals_required = -1;
	}
	else
	{
		stats->philo_total = ft_atoi(av[1]);
		stats->time_to_die = ft_atoi(av[2]);
		stats->time_to_eat = ft_atoi(av[3]);
		stats->time_to_sleep = ft_atoi(av[4]);
		stats->meals_required = ft_atoi(av[5]);
	}
	stats->start_time = current_time_ms();
	stats->stop = false;
	if (pthread_mutex_init(&stats->action, NULL))
		return (0);
	if (!init_forks(stats))
		return (0);
	return (1);
}

int init_forks(t_stats *stats)
{
	int i;

	i = -1;
	stats->forks = malloc(sizeof(pthread_mutex_t) * stats->philo_total);
	if (!stats->forks)
		return (0);
	while (++i < stats->philo_total)
		pthread_mutex_init(&stats->forks[i], NULL);
	return (1);
}
