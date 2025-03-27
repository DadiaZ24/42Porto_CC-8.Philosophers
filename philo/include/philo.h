/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:11:51 by ddias-fe          #+#    #+#             */
/*   Updated: 2025/03/27 11:35:08 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//________________________________________________________________
//|_____________________________[LIBS]____________________________|
//|_______________________________________________________________|

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>

//________________________________________________________________
//|____________________________[MACROS]___________________________|
//|_______________________________________________________________|

//----COLORS
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define BLUE "\033[0;36m"
# define DEFAULT_COLOR "\033[0m"

//-----MESSAGES

//________________________________________________________________
//|__________________________[STRUCTURES]_________________________|
//|_______________________________________________________________|

typedef struct s_stats	t_stats;

typedef struct s_philo
{
	int			philo_id;
	int			meals;
	int			right_fork;
	int			left_fork;
	bool		is_full;
	pthread_t	id;
	suseconds_t	last_meal;
	t_stats		*stats;

}	t_philo;

typedef struct s_stats
{
	int				philo_total;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_required;
	int				philos_feeded;
	int				time_to_think;
	bool			stop;
	suseconds_t		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	action;
	pthread_mutex_t	lock;
	t_philo			*philos;

}	t_stats;

//________________________________________________________________
//|__________________________[FUNCTIONS]__________________________|
//|_______________________________________________________________|

int			init_program(int ac, char **av, t_stats *stats, t_philo **philos);
int			parser(int ac, char **av);
int			exec(t_stats *stats, t_philo *philo);
int			init_forks(t_stats *stats);
int			init_stats(int ac, char **av, t_stats *stats);
int			free_program(t_stats *stats);
int			ft_atoi(const char *str);
void		init_philos(t_stats *stats, t_philo *philos);
void		*routine(t_philo *philo);
bool		sleeping(t_philo *philo);
void		unlock_forks(t_stats *stats, t_philo *philo);
void		thinking(t_philo *philo);
void		lock_forks(t_stats *stats, t_philo *philo);
void		main_checker(t_philo *philo, t_stats *stats);
bool		eating(t_philo *philo);
bool		action(t_stats *stats, t_philo *philo, char *msg);
bool		check_dead(t_philo *philo, t_stats *stats);
suseconds_t	current_time_ms(void);
bool		usleep_checking(suseconds_t time, t_stats *stats);

#endif
