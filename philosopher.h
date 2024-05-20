/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:11:11 by msoriano          #+#    #+#             */
/*   Updated: 2024/05/16 17:26:35 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					is_eating;
	int					meals_eaten;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	struct s_program	*program;

}	t_philo;

typedef struct s_program
{
	int					number_of_philosophers;
	int					number_of_meals;
	int					dead;
	size_t				start_time;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	pthread_mutex_t		*forks;
	pthread_mutex_t		lock;
	pthread_mutex_t		write_lock;
	t_philo			*philo;
}	t_program;
#endif