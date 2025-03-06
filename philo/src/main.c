/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:55:43 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/09/30 17:27:31 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philos;
	t_stats	stats;

	philos = NULL;
	if (parser(ac))
		return (-1);
	if (!init_program(ac, av, &stats, &philos))
		return (-1);
	if (!exec(&stats, philos))
		return (printf("Error executing"), free_program(&stats), 0);
	if (!free_program(&stats))
		return (printf("Error freeing memory"), 0);
	return (0);
}
