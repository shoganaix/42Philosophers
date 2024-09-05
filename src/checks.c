/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:57:20 by msoriano          #+#    #+#             */
/*   Updated: 2024/08/20 20:04:53 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/* Check the inputs given are numbers */

int	input_checker(char **argv)
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
	return (0);
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
	i = 1;
	while (i < data->number_of_philosophers +1)
	{
		philo = &data->philosophers[i];
		printf("Philosopher %d:\n", i);
		printf("  ID: %d\n", philo->id);
		printf("  Left Fork ID: %d\n", philo->left_fork_id);
		printf("  Right Fork ID: %d\n", philo->right_fork_id);
		printf("  Thread ID: %lu\n", (unsigned long)philo->thread_id);
		printf("\n");
		i++;
	}
}
