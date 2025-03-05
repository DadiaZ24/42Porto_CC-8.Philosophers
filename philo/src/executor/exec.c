/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:39:28 by ddias-fe          #+#    #+#             */
/*   Updated: 2025/02/17 12:39:28 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void action(t_stats *stats, t_philo *philo, char *msg)
{
	if (stats->stop)
		return;
	pthread_mutex_lock(&stats->action);
	printf("[%ld] Philo %d %s\n", current_time_ms() - stats->start_time, philo->philo_id, msg);
	pthread_mutex_unlock(&stats->action);
}

void routine(t_philo *philo, t_stats *stats)
{
	while (1)
	{
		if (stats->stop)
			break;
		if (stats->philo_total <= 1)
		{
			action(stats, philo, "has died");
			break;
		}
		if (philo->philo_id % 2 == 0)
		{
			pthread_mutex_lock(&stats->forks[philo->right_fork]);
			pthread_mutex_lock(&stats->forks[philo->left_fork]);
			action(stats, philo, "has taken a fork");
			action(stats, philo, "has taken a fork");
		}
		else
		{
			pthread_mutex_lock(&stats->forks[philo->left_fork]);
			pthread_mutex_lock(&stats->forks[philo->right_fork]);
			action(stats, philo, "has taken a fork");
			action(stats, philo, "has taken a fork");
		}
		if ((current_time_ms() - philo->last_meal) > stats->time_to_die)
		{
			action(stats, philo, "has died");
			stats->stop = true;
			break;
		}
		action(stats, philo, "is eating");
		usleep(stats->time_to_eat * 1000);
		pthread_mutex_unlock(&stats->forks[philo->left_fork]);
		pthread_mutex_unlock(&stats->forks[philo->right_fork]);
		if (stats->meals_required >= 0)
			philo->meals++;
		philo->last_meal = current_time_ms();
		action(stats, philo, "is sleeping");
		usleep(stats->time_to_sleep * 1000);
		action(stats, philo, "is thinking");
		if (stats->meals_required != -1 && philo->meals >= stats->meals_required)
			break;
	}
}

void *philo_routine(t_philo *philo)
{
	routine(philo, philo->stats);
	return (NULL);
}

int exec(t_stats *stats, t_philo *philo)
{
	int i;

	i = -1;
	stats->start_time = current_time_ms();
	while (++i < stats->philo_total)
	{
		philo[i].last_meal = stats->start_time;
		philo[i].stats = stats;
		if (pthread_create(&philo[i].id, NULL, (void *)philo_routine, &philo[i]))
			return (printf("ERROR!!!!"), 0);
	}
	i = -1;
	while (++i < stats->philo_total)
	{
		pthread_join(philo[i].id, NULL);
	}
	return (1);
}
