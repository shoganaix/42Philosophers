/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:36:17 by msoriano          #+#    #+#             */
/*   Updated: 2024/09/21 19:28:59 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_forks(t_philo *philo)
{
	t_data		*data;

	data = philo->data;
	pthread_mutex_lock(&(data->forks[philo->left_fork_id]));
	prints(philo->data, philo->philo_id, "has taken a fork");
	pthread_mutex_lock(&(data->forks[philo->right_fork_id]));
	prints(philo->data, philo->philo_id, "has taken a fork");
}
void	action_eat(t_philo *philo)
{
	t_data		*data;

	data = philo->data;
	take_forks(philo);
	pthread_mutex_lock(&(data->lock_meal));
	prints(philo->data, philo->philo_id, "is eating");
	philo->time_of_last_meal = get_timestamp();
	pthread_mutex_unlock(&(data->lock_meal));
	action_sleep(data);
	philo->eat_counter++;
	pthread_mutex_unlock(&(data->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(data->forks[philo->right_fork_id]));
}

void	action_sleep(t_data *data)
{
	long long	i;

	i = get_timestamp();
	while (!(data->dead))
	{
		if ((get_timestamp() - i) >= data->time_to_sleep)
			break ;
		usleep(50);
	}
}

void	*routine(void *philo_pt)
{
	t_philo	*philo;
	t_data	*data;
	int		i;

	philo = (t_philo *) philo_pt;
	data = philo->data;
	//printf("Hola soy el philo %i\n", philo->philo_id);
	/* We separate for even and odds
	 * THIS IS NECESSARY TO AVOID 
	 */
	if (philo->philo_id % 2)
		usleep(15000);
	while (!(data->dead))
	{
		action_eat(philo);
		if (data->finished_eating)
			break ;
		prints(data, philo->philo_id, "is sleeping");
		action_sleep(data);
		prints(data, philo->philo_id, "is thinking");
		i++;
	}
	return (NULL);
}