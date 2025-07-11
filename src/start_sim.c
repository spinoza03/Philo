/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:23:14 by ilallali          #+#    #+#             */
/*   Updated: 2025/07/11 18:29:06 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat / 2, philo->data);
	while (!check_dead(philo->data))
	{
		print_act(philo, "is thinking");
		pick_up(philo);
		print_act(philo, "is eating");
		pthread_mutex_lock(&philo->meal_lock);
		philo->last_meal_time = get_curent_time();
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->meal_lock);
		ft_usleep(philo->data->time_to_eat, philo->data);
		put_down(philo);
		print_act(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep, philo->data);
	}
	return (NULL);
}

static int	all_philos_are_full(t_data *data)
{
	int	i;
	int	full_philos;

	i = 0;
	full_philos = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&data->philos[i].meal_lock);
		if (data->philos[i].meals_eaten >= data->must_eat)
			full_philos++;
		pthread_mutex_unlock(&data->philos[i].meal_lock);
		i++;
	}
	if (full_philos == data->num_philos)
		return (1);
	return (0);
}

void	*meals_monitor(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	if (data->must_eat <= 0)
		return (NULL);
	while (!check_dead(data))
	{
		if (all_philos_are_full(data))
		{
			pthread_mutex_lock(&data->death_mutex);
			data->someone_die = 1;
			pthread_mutex_unlock(&data->death_mutex);
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}

int	start_simulation(t_data *data)
{
	int	i;

	data->start_time = get_curent_time();
	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].last_meal_time = data->start_time;
		if (pthread_create(&data->philos[i].thread,
				NULL, routine, &data->philos[i]) != 0)
			return (-1);
		i++;
	}
	if (pthread_create(&data->death_thread, NULL, death_monitor, data) != 0)
		return (-1);
	if (data->must_eat > 0)
	{
		if (pthread_create(&data->meal_thread, NULL, meals_monitor, data) != 0)
			return (-1);
	}
	pthread_join(data->death_thread, NULL);
	if (data->must_eat > 0)
		pthread_join(data->meal_thread, NULL);
	return (0);
}

/*
 Cases
 -1- ./philo 5 800 200 200 no death
 -2- ./philo 200 60 60 60 death
 -3- ./philo 2 410 200 200 no death
 -4- ./philo 2 310 200 100 death
	*------------------------------------------------------------------------------*
	| if num_of_philos ? odd : time_to_die = time_to_eat x 2 + time_to_sleep + 10  |
	|																		       |
	| if num_of_philos ? even : time_to_die = time_to_eat + time_to_sleep + 10     |
	*------------------------------------------------------------------------------*
*/