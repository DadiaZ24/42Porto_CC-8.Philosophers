/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:39:28 by ddias-fe          #+#    #+#             */
/*   Updated: 2025/03/27 11:41:19 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	exec(t_stats *stats, t_philo *philo)
{
	int	i;

	i = -1;
	stats->start_time = current_time_ms();
	while (++i < stats->philo_total)
	{
		philo[i].last_meal = stats->start_time;
		philo[i].stats = stats;
		if (pthread_create(&philo[i].id, NULL,
				(void *)routine, &philo[i]))
			return (printf("Error creating threads"), 0);
	}
	main_checker(philo, stats);
	i = -1;
	while (++i < stats->philo_total)
	{
		if (pthread_join(philo[i].id, NULL))
			return (printf("Error joining threads"), 0);
	}
	return (1);
}

void	*routine(t_philo *philo)
{
	if (philo->stats->philo_total == 1)
	{
		action(philo->stats, philo, "has taken a fork");
		usleep(philo->stats->time_to_die * 1000);
		return (NULL);
	}
	while (1)
	{
		pthread_mutex_lock(&philo->stats->action);
		if (philo->stats->stop)
		{
			pthread_mutex_unlock(&philo->stats->action);
			break ;
		}
		pthread_mutex_unlock(&philo->stats->action);
		if (!eating(philo))
			break ;
		if (!sleeping(philo))
			break ;
		thinking(philo);
	}
	return (NULL);
}

bool	check_dead(t_philo *philo, t_stats *stats)
{
	if (philo->meals == stats->meals_required && philo->is_full == false)
	{
		philo->is_full = true;
		stats->philos_feeded++;
	}
	if ((current_time_ms() - philo->last_meal) > stats->time_to_die)
	{
		pthread_mutex_unlock(&stats->action);
		action(stats, philo, "died");
		pthread_mutex_lock(&stats->action);
		philo->stats->stop = true;
		pthread_mutex_unlock(&stats->action);
		return (true);
	}
	return (false);
}

void	main_checker(t_philo *philo, t_stats *stats)
{
	int	i;

	while (1)
	{
		i = -1;
		pthread_mutex_lock(&stats->action);
		while (++i < stats->philo_total)
		{
			if (check_dead(&philo[i], stats))
				return ;
		}
		if (stats->philos_feeded == stats->philo_total)
		{
			stats->stop = true;
			printf("All philos are feeded\n");
			pthread_mutex_unlock(&stats->action);
			return ;
		}
		pthread_mutex_unlock(&stats->action);
	}
}
