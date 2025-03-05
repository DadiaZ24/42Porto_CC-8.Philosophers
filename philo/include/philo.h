/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:11:51 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/09/30 17:26:49 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

//________________________________________________________________
//|_____________________________[LIBS]____________________________|
//|_______________________________________________________________|

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdbool.h>
#include <semaphore.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

//________________________________________________________________
//|____________________________[MACROS]___________________________|
//|_______________________________________________________________|

//----COLORS
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define BLUE "\033[0;36m"
#define DEFAULT_COLOR "\033[0m"

//-----MESSAGES

//________________________________________________________________
//|__________________________[STRUCTURES]_________________________|
//|_______________________________________________________________|

typedef struct s_stats t_stats;

typedef struct s_philo
{
	int philo_id;
	int meals;
	long last_meal;
	pthread_t id;
	int left_fork;
	int right_fork;
	t_stats *stats;

} t_philo;

typedef struct s_stats
{
	int philo_total;
	long time_to_die;
	long time_to_eat;
	long time_to_sleep;
	int meals_required;
	bool stop;
	pthread_mutex_t *forks;
	pthread_mutex_t print;
	long start_time;
	t_philo **philos;

} t_stats;

//________________________________________________________________
//|__________________________[FUNCTIONS]__________________________|
//|_______________________________________________________________|

int parser(int ac, char **av);
int init_forks(t_stats *stats);
int init_stats(int ac, char **av, t_stats *stats);
void init_philos(t_stats *stats, t_philo **philos);
int init_program(int ac, char **av, t_stats *stats, t_philo **philos);
void action(t_stats *stats, t_philo *philo, char *msg);
int exec(t_stats *stats, t_philo *philo);
void *philo_routine(t_philo *philo);
void routine(t_philo *philo, t_stats *stats);
suseconds_t current_time_ms(void);
int free_program(t_stats *stats, t_philo *philos);
int ft_atoi(const char *str);
#endif