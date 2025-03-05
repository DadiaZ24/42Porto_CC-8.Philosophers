/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:16:17 by ddias-fe          #+#    #+#             */
/*   Updated: 2025/02/17 14:16:17 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int free_program(t_stats *stats)
{
	int i;

	i = 0;
	while (i < stats->philo_total)
	{
		pthread_mutex_destroy(&stats->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&stats->action);
	if (stats->forks)
		free(stats->forks);
	if (stats->philos)
		free(stats->philos);
	return (1);
}
