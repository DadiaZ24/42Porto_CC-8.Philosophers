/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:23:54 by ddias-fe          #+#    #+#             */
/*   Updated: 2025/03/06 17:47:13 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	action(t_stats *stats, t_philo *philo, char *msg)
{
	pthread_mutex_lock(&stats->action);
	if (stats->stop)
	{
		pthread_mutex_unlock(&stats->action);
		return (false);
	}
	printf("[%ld] %d %s\n", current_time_ms() - stats->start_time,
		philo->philo_id, msg);
	pthread_mutex_unlock(&stats->action);
	return (true);
}

bool	us_checker(t_stats *stats, t_philo *philo, long tu, long tc)
{
	if (tu > tc)
	{
		usleep(tc * 1000);
		action(stats, philo, "has died");
		pthread_mutex_lock(&stats->action);
		stats->stop = true;
		pthread_mutex_unlock(&stats->action);
		return (false);
	}
	usleep(tu * 1000);
	return (true);
}

void	lock_forks(t_stats *stats, t_philo *philo)
{
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
}

void unlock_forks(t_stats *stats, t_philo *philo)
{
    if (philo->philo_id % 2 == 0)
    {
        pthread_mutex_unlock(&stats->forks[philo->right_fork]);
        pthread_mutex_unlock(&stats->forks[philo->left_fork]);
    }
    else
    {
        pthread_mutex_unlock(&stats->forks[philo->left_fork]);
        pthread_mutex_unlock(&stats->forks[philo->right_fork]);
    }
}
