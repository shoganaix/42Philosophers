/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:57:20 by msoriano          #+#    #+#             */
/*   Updated: 2024/09/21 19:40:21 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/* Check the inputs given are numbers 
 * Calls check_non_negative function: 
 * if negative number / not digit: returns -> 1 
 *  Else, returns -> 0
*/

int	check_input(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
			{
				j++;
				continue ;
			}
			if ((argv[i][j] < '0' || argv[i][j] > '9'))
				return (1);
			j++;
		}
		i++;
	}
	if (check_non_negative(argv) != 0)
		return (1); 
	return (0);
}

int	check_non_negative(char **argv)
{
	int	i;
	int	nb;

	i = 1;
	while (argv[i + 1])
	{
		nb = ft_atoi(argv[i]);
		if (nb < 0)
			return (1);
		i++;
	}
	return (0);
}

//Checks if they are dead, returns the value of data-> dead 1 if they are
void	check_death(t_data *data, t_philo *philo)
{
	int	i;

	while (!(data->finished_eating))
	{
		i = 0;
		while (i < data->number_of_philosophers && !(data->dead))
		{
			pthread_mutex_lock(&(data->lock_meal));
			if ((data->start_time - philo[i].time_of_last_meal)
				> data->time_to_die)
			{
				prints(data, i, "died");
				data->dead = 1;
			}
			pthread_mutex_unlock(&(data->lock_meal));
			usleep(100);
			i++;
		}
		if (data->dead)
			break ;
		i = 0;
		while (data->number_of_times_each_philosopher_must_eat != -1
			&& i < data->number_of_philosophers && philo[i].eat_counter
			>= data->number_of_times_each_philosopher_must_eat)
			i++;
		if (i == data->number_of_philosophers)
			data->finished_eating = 1;
	}
}


void	print_values(t_data *data)
{
	int		i;
	t_philo	*philo;

	// Print general data
	printf("Number of Philosophers: %d\n", data->number_of_philosophers);
	printf("Time to Die: %d\n", data->time_to_die);
	printf("Time to Eat: %d\n", data->time_to_eat);
	printf("Time to Sleep: %d\n", data->time_to_sleep);
	printf("Number of Times Each Philosopher Must Eat: %d\n",
		data->number_of_times_each_philosopher_must_eat);
	printf("\n");

	// Print each philosopher data
	i = 0;
	while (i < data->number_of_philosophers)
	{
		philo = &data->philosophers[i];
		printf("Philosopher %d:\n", i + 1);
		printf("  ID: %d\n", philo->philo_id);
		printf("  Left Fork ID: %d\n", philo->left_fork_id);
		printf("  Right Fork ID: %d\n", philo->right_fork_id);
		//printf("  Thread ID: %lu\n", (unsigned long)philo->thread_1);
		printf("\n");
		i++;
	}
}
