/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:39:28 by ddias-fe          #+#    #+#             */
/*   Updated: 2025/03/06 17:48:34 by ddias-fe         ###   ########.fr       */
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
				(void *)philo_routine, &philo[i]))
			return (printf("ERROR!!!!"), 0);
	}
	i = -1;
	while (++i < stats->philo_total)
	{
		pthread_join(philo[i].id, NULL);
	}
	return (1);
}

void	*philo_routine(t_philo *philo)
{
	routine(philo, philo->stats);
	return (NULL);
}

void	routine(t_philo *philo, t_stats *stats)
{
	while (1)
	{
		pthread_mutex_lock(&stats->action);
		if (stats->stop)
		{
			pthread_mutex_unlock(&stats->action);
			pthread_mutex_unlock(&stats->forks[philo->left_fork]);
			break ;
		}
		pthread_mutex_unlock(&stats->action);
		if (!take_action(stats, philo))
			break ;
		unlock_forks(stats, philo);
		if (stats->meals_required >= 0)
			philo->meals++;
		philo->last_meal = current_time_ms();
		if(!action(stats, philo, "is sleeping"))
			break ;
		if (!us_checker(stats, philo, stats->time_to_sleep, 
			stats->time_to_die - (philo->last_meal - stats->start_time)))
			{
				break ;
			}
		if (!action(stats, philo, "is thinking"))
			break ;
		if (stats->meals_required != -1
			&& philo->meals >= stats->meals_required)
			break ;
	}
}

bool	take_action(t_stats *stats, t_philo *philo)
{
	if (stats->philo_total <= 1)
	{
		usleep(stats->time_to_die * 1000);
		action(stats, philo, "died");
		return (false);
	}
	lock_forks(stats, philo);
	action(stats, philo, "is eating");
	if (!us_checker(stats, philo, stats->time_to_eat, 
		stats->time_to_die - (philo->last_meal - stats->start_time)))
		return (false);
	return (true);
}

bool	check_dead(t_stats *stats, t_philo *philo)
{
	if ((current_time_ms() - philo->last_meal) > stats->time_to_die)
	{
		action(stats, philo, "has died");
		pthread_mutex_lock(&stats->action);
		stats->stop = true;
		pthread_mutex_unlock(&stats->action);
		unlock_forks(stats, philo);
		return (false);
	}
	return (true);
}
