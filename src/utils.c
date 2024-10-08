/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:17:56 by msoriano          #+#    #+#             */
/*   Updated: 2024/09/24 14:39:42 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	get_timestamp(void)
{
	struct timeval	t_val;

	if (gettimeofday(&t_val, NULL))
		return (my_perror("gettimeofday() function failed \n"), -1);
	return ((t_val.tv_sec * 1000) + (t_val.tv_usec / 1000));
}

int	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = get_timestamp();
	while ((get_timestamp() - start) < time)
		ft_usleep(time / 10);
	return (0);
}

//		WORK IN PROGRESS
// Destroys mutex and clears data
//NOt necessary to free thread_id because it points at philosophers pointer
void	clears_and_exit(t_data *data, t_philo *philo)
{
	int		i;

	i = -1;
	while (++i < data->number_of_philosophers)
		pthread_join(philo[i].thread_id, NULL);
	i = -1;
	while (++i < data->number_of_philosophers)
	{
		//mutex destroy
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->lock_wr);
}

void	prints(t_data *data, int id, char *message)
{
	pthread_mutex_lock(&(data->lock_wr));
	if (!check_datadead(data))
	{
		printf("%lli %i %s\n", get_timestamp()
			- data->start_time, id + 1, message);
	}
	pthread_mutex_unlock(&(data->lock_wr));
}