/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:17:56 by msoriano          #+#    #+#             */
/*   Updated: 2024/09/05 14:56:11 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (my_perror("error: function gettimeofday() failed!"), -1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_action(t_data *data, int id, char *msg)
{
	if (!(data->dead))
	{
		printf("%i ", get_time() - data->start_time);
		printf("%i ", id + 1);
		printf("%s\n", msg);
	}
	return ;
}
//		WORK IN PROGRESS
// Destroys mutex and clears data
//NOt necessary to free thread_id because it points at philosophers pointer
void	clears_and_exit(t_data *data)
{
	int		i;


	i = 0;
	while(i < data->number_of_philosophers)
	{
		//mutex destroy
		pthread_mutex_destroy(&data->);
		pthread_mutex_destroy(&data->);
		i++;
	}
	pthread_mutex_destroy(&data->
	pthread_mutex_destroy(&data->
	free(data->forks);
	free(data->philosophers);
}


		// void	clear_data(t_data	*data)
		// {
		// 	if (data->tid)
		// 		free(data->tid);
		// 	if (data->forks)
		// 		free(data->forks);
		// 	if (data->philos)
		// 		free(data->philos);
		// }

		// void	ft_exit(t_data *data)
		// {
		// 	int	i;

		// 	i = -1;
		// 	while (++i < data->philo_num)
		// 	{
		// 		pthread_mutex_destroy(&data->forks[i]);
		// 		pthread_mutex_destroy(&data->philos[i].lock);
		// 	}
		// 	pthread_mutex_destroy(&data->write);
		// 	pthread_mutex_destroy(&data->lock);
		// 	clear_data(data);
		// }

