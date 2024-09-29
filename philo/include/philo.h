/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:11:51 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/09/29 14:11:51 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//________________________________________________________________
//|_____________________________[LIBS]____________________________|
//|_______________________________________________________________|

# include "../../libs/libft/libft.h"
# include <pthread.h>

//________________________________________________________________
//|____________________________[MACROS]___________________________|
//|_______________________________________________________________|

//----COLORS
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define BLUE "\033[0;36m"
# define DEFAULT_COLOR "\033[0m"

//-----MESSAGES
# define ERROR "ERROR\n"
# define ERROR_AC "%s%s%s Invalid number of arguments (minimum: 2 \
/ actual: %d) \n"
# define ERROR_ISDIGIT "%s%s%s Invalid data -> you can only input digits"
# define ERROR_DUP "%s%s%s Invalid data -> you have duplicate numbers"
# define ERROR_MAX_MIN "%s%s%s Invalid data -> you numbers should be INTs \
 (check limits.h: INT_MAX and INT_MIN)"

//________________________________________________________________
//|__________________________[STRUCTURES]_________________________|
//|_______________________________________________________________|

typedef struck s_philo{
	int	id;
	pthread_mutex_t left_fork;
}

//________________________________________________________________
//|__________________________[FUNCTIONS]__________________________|
//|_______________________________________________________________|



#endif