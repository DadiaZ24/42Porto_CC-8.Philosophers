/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:31:50 by ddias-fe          #+#    #+#             */
/*   Updated: 2025/03/20 19:13:31 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	sleeping(t_philo *philo)
{
	action (philo->stats, philo, "is sleeping");
	if (!usleep_checking(philo->stats->time_to_sleep * 1000, philo->stats))
		return (false);
	return (true);
}

void	thinking(t_philo *philo)
{
	action(philo->stats, philo, "is thinking");
}

bool	eating(t_philo *philo)
{
	lock_forks(philo->stats, philo);
	pthread_mutex_lock(&philo->stats->action);
	philo->last_meal = current_time_ms();
	if (philo->stats->meals_required >= 0)
		philo->meals++;
	pthread_mutex_unlock(&philo->stats->action);
	action(philo->stats, philo, "is eating");
	usleep(philo->stats->time_to_eat * 1000);
	unlock_forks(philo->stats, philo);
	return (true);
}
