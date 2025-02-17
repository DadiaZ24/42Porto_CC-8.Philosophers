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

void	action(t_stats *stats, t_philo *philo, char *msg)
{
	pthread_mutex_lock(&stats->print);
	printf("%ld %d %s\n", current_time_ms() - stats->start, philo->philo_id, msg);
	pthread_mutex_unlock(&stats->print);
}

void	routine(t_philo *philo, t_stats *stats)
{
	while (!stats->stop)
	{
		action(stats, philo, "is thinking");
		pthread_mutex_lock(&stats->forks[philo->left_fork]);
		action(stats, philo, "has taken the left fork");
		pthread_mutex_lock(&stats->forks[philo->right_fork]);
		action(stats, philo, "has taken the right fork");
		philo->last_meal = current_time_ms();
		action(stats, philo, "is eating");
		usleep(stats->time_to_eat * 1000);
		philo->meals++;
		pthread_mutex_unlock(&stats->forks[philo->left_fork]);
		pthread_mutex_unlock(&stats->forks[philo->right_fork]);
		action(stats, philo, "is sleeping");
		usleep(stats->time_to_sleep * 1000);
	}
}