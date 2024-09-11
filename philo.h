/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:11:11 by msoriano          #+#    #+#             */
/*   Updated: 2024/09/05 12:16:18 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				left_fork_id;
	int				right_fork_id;
	pthread_t		thread_id;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				start_time;
	int				time_of_death;
	int				dead; //bool?
	int				number_of_times_each_philosopher_must_eat;
	t_philo			philosophers[250];
	pthread_mutex_t	forks[250];
	pthread_mutex_t	lock_meal;

}	t_data;

/*Libft utils*/
void	my_perror(char *msg);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(char c);

/*Utils*/
int		get_time(void);
void	print_action(t_data *data, int id, char *msg);
void	clears_and_exit(t_data *data);


/*Checks*/
int		input_checker(char **argv);
void	print_values(t_data *data);

/*Philo*/
void	*routine(void *philo);

/*Main*/
void	init_philos(t_data *data);
int		init_values(t_data *data, char **argv);

#endif

/*
ARGUMENTOS QUE RECIBIRA EL PROGRAMA:
		◦ number_of_philosophers: number of philosophers and forks.
		◦ time_to_die (milisecs): if a philosopher doesnt start eating in 'time_to_die' after starting his last meal or the beginning of the simulation, they'll die.
		◦ time_to_eat (milisecs): time it takes a philosopher to eat. During that time he will use and lock two forks.
		◦ time_to_sleep (milisecs): time a philosopher will spend sleeping.
		◦ number_of_times_each_philosopher_must_eat(optional): if all philosophers eat at least 'number_of_times_each_philosopher_must_eat' the simulation  will stop. 
				If not specified, the simulation will stop only at the death of a philosopher
CAMBIOS DE ESTADO:
		◦ timestamp_in_ms X has taken a fork
		◦ timestamp_in_ms X is eating
		◦ timestamp_in_ms X is sleeping
		◦ timestamp_in_ms X is thinking
		◦ timestamp_in_ms X died
*/
