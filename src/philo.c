/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:36:17 by msoriano          #+#    #+#             */
/*   Updated: 2024/08/20 21:37:30 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_forks(t_philo *philo)
{
	t_data		*data;

	data = philo->data;
	pthread_mutex_lock(&(data->forks[philo->left_fork_id]));
	print_action(philo->data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(data->forks[philo->right_fork_id]));
	print_action(philo->data, philo->id, "has taken a fork");
}

void	eats(t_philo *philo)
{
	t_data		*data;

	data = philo->data;
	take_forks(philo);
	pthread_mutex_lock(&(data->lock_meal));
	//philo->is_eating = 1;
	//philo->data->time_of_death = philo->data->time_to_die + get_time();
	print_action(philo->data, philo->id, "is eating");
	usleep(philo->data->time_to_eat);
	//philo->is_eating = 0;
	pthread_mutex_unlock(&(data->lock_meal));
	pthread_mutex_unlock(&(data->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(data->forks[philo->right_fork_id]));
}

void	*routine(void *philo_pt)
{
	t_philo		*philo;
	t_data		*data;
	int			i;

	philo = (t_philo *) philo_pt;
	data = philo->data;
	while (!(data->dead))
	{
		eats(philo);
		print_action(data, philo->id, "is thinking");
		//usleep(15000);
		print_action(data, philo->id, "is sleeping");
		usleep(philo->data->time_to_sleep);
		i++;
	}
	return (NULL);
}