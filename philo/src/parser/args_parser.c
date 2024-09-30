/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:44:17 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/09/30 15:47:54 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	parse_args(char **av)
{
	if (av[1] <= 0 || av[2] <= 0 || av[3] <= 0 || av[4] <= 0)
		return (printf("Wrong usage!"), false);
	if (!ft_isdigit(av[1]) || !ft_isdigit(av[2]) || !ft_isdigit(av[3])
		|| !ft_isdigit(av[4]))
		return (printf("Wrong usage!"), false);
}