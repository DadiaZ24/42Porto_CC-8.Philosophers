/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:23:54 by ddias-fe          #+#    #+#             */
/*   Updated: 2025/03/06 11:23:54 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action(t_stats *stats, t_philo *philo, char *msg)
{
	pthread_mutex_lock(&stats->action);
	if (stats->stop)
	{
		pthread_mutex_unlock(&stats->action);
		return ;
	}
	printf("[%ld] %d %s\n", current_time_ms() - stats->start_time,
		philo->philo_id, msg);
	pthread_mutex_unlock(&stats->action);
}
