/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:51:18 by ilallali          #+#    #+#             */
/*   Updated: 2025/07/10 17:52:15 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_philo_dead(t_philo *philo)
{
	long	time_since_meal;

	pthread_mutex_lock(&philo->meal_lock);
	time_since_meal = get_curent_time() - philo->last_meal_time;
	if (time_since_meal > philo->data->time_to_die)
	{
		pthread_mutex_unlock(&philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_lock);
	return (0);
}

void	*death_monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->num_philos)
		{
			if (is_philo_dead(&data->philos[i]))
			{
				print_act(&data->philos[i], "died");
				pthread_mutex_lock(&data->death_mutex);
				data->someone_die = 1;
				pthread_mutex_unlock(&data->death_mutex);
				return (NULL);
			}
			i++;
		}
		ft_usleep(1);
	}
	return (NULL);
}
