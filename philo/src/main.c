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
	/*t_philo	philos;
	t_stats	stats;
	pthread_mutex_t	*forks;*/

	if (ac != 5 && ac != 6)
		return (printf("ERROR!!!!"), -1);
	parse_args(av);
}