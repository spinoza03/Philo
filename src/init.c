/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:22:06 by ilallali          #+#    #+#             */
/*   Updated: 2025/07/12 15:32:21 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fill_data(char **av, t_data *data)
{
	int	i;

	i = 0;
	data->num_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->someone_die = 0;
	if (av[5])
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = -1;
	data->forks = malloc(data->num_philos * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (-1);
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->death_mutex, NULL);
	data->start_time = get_curent_time();
	return (0);
}

int	init_philos(t_data *data)
{
	int		i;
	t_philo	*ph;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
	{
		free(data->forks);
		return (-1);
	}
	while (i < data->num_philos)
	{
		ph = &data->philos[i];
		ph->id = i;
		ph->meals_eaten = 0;
		ph->last_meal_time = data->start_time;
		ph->left_fork_id = i;
		ph->right_fork_id = (i + 1) % data->num_philos;
		ph->data = data;
		pthread_mutex_init(&ph->meal_lock, NULL);
		i++;
	}
	return (0);
}
