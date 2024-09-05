/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:38:32 by msoriano          #+#    #+#             */
/*   Updated: 2024/09/05 12:30:00 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
    Initialize values on our data structure and calls init_philos
*/

int	init_values(t_data *data, char **argv)
{
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		data->number_of_times_each_philosopher_must_eat = -1;
	init_philos(data);
	//print_values(data);
	return (0);
}
/*
    Initialize values on our philo structure
    Left Fork ID: Their Index.   
    Right Fork ID: Index of the next philosopher. 
    For the last philosopher, the right fork ID wraps around to 0.
*/

void	init_philos(t_data *data)
{
	int	i;

	i = 1;
	while (i < (data->number_of_philosophers + 1))
	{
		data->philosophers[i].id = i;
		data->philosophers[i].data = data;
		data->philosophers[i].left_fork_id = i;
		data->philosophers[i].right_fork_id = (i + 1)
			% (data->number_of_philosophers + 1);
		i++;
	}
}


int	thread_init(t_data *data)
{
	int			i;
	t_philo		*philo;

	philo = data->philosophers;
	data->start_time = get_time();
/*
    Este bucle crea procesos separados para cada filósofo (hilos)
    Cada filósofo ejecuta su propio set de instrucciones/rutina independientemente
*/
	i = 0;
	while (++i < data->number_of_philosophers)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, &routine, &philo[i]))
			return (my_perror("error: pthread_create failed!"), -1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (my_perror("error: wrong number of arguments!"), -1);
	else if (input_checker(argv) != 0)
		return (my_perror("error: not a valid argument!"), -1);
	else if (init_values(&data, argv) != 0)
		return (my_perror("error: initialization failed!"), -1);
	else if (thread_init(&data) != 0)
		return (my_perror("error: thread_init failed!"), -1);
	clears_and_exit(&data);
	return (0);
}
