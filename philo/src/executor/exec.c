/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:39:28 by ddias-fe          #+#    #+#             */
/*   Updated: 2025/03/11 18:38:16 by ddias-fe         ###   ########.fr       */
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
		if (!routine_check(stats, philo))
		{
			printf("%d SALTOU FORA\n", philo->philo_id);
			break ;
		}
		if (!eat(stats, philo))
		{
			printf("%d SALTOU FORA\n", philo->philo_id);
			break ;
		}
		if (stats->meals_required >= 0)
			philo->meals++;
		if (!action(stats, philo, "is sleeping"))
		{
			printf("%d SALTOU FORA\n", philo->philo_id);
			break ;
		}
		if (!us_checker(stats, philo, stats->time_to_sleep,
				stats->time_to_die - (current_time_ms() - philo->last_meal)))
		{
			printf("%d SALTOU FORA\n", philo->philo_id);
			break ;
		}
		usleep(stats->time_to_sleep * 1000);
		if (!action(stats, philo, "is thinking"))
		{
			printf("%d SALTOU FORA\n", philo->philo_id);
			break ;
		}
		if (stats->meals_required != -1
			&& philo->meals >= stats->meals_required)
			{
				printf("%d SALTOU FORA\n", philo->philo_id);
				break ;
			}
	}
}

bool	eat(t_stats *stats, t_philo *philo)
{
	if (!eat_checks(stats, philo))
		return (false);
	if (stats->time_to_die < stats->time_to_eat)
	{
		usleep(stats->time_to_die * 1000);
		action(stats, philo, "has died");
		pthread_mutex_lock(&stats->action);
		stats->stop = true;
		pthread_mutex_unlock(&stats->action);
		return (false);
	}
	lock_forks(stats, philo);
	philo->last_meal = current_time_ms();
	if (!action(stats, philo, "is eating"))
		return (unlock_forks(stats, philo), false);
	if (!us_checker(stats, philo, stats->time_to_eat,
			stats->time_to_die - (current_time_ms() - philo->last_meal)))
		return (unlock_forks(stats, philo), false);
	usleep(stats->time_to_eat * 1000);
	unlock_forks(stats, philo);
	return (true);
}

bool	eat_checks(t_stats *stats, t_philo *philo)
{
	if (stats->philo_total <= 1)
	{
		usleep(stats->time_to_die * 1000);
		action(stats, philo, "died");
		return (false);
	}
	pthread_mutex_lock(&stats->action);
	if (stats->stop)
	{
		pthread_mutex_unlock(&stats->action);
		return (false);
	}
	pthread_mutex_unlock(&stats->action);
	return (true);
}
