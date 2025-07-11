/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:51:18 by ilallali          #+#    #+#             */
/*   Updated: 2025/07/11 18:06:34 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_and_record_death(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->meal_lock);
	time = get_curent_time() - philo->last_meal_time;
	pthread_mutex_unlock(&philo->meal_lock);
	if (time > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->death_mutex);
		if (philo->data->someone_die == 0)
		{
			philo->data->someone_die = 1;
			printf("%ld %d died\n", get_curent_time()
				- philo->data->start_time, philo->id + 1);
			pthread_mutex_unlock(&philo->data->death_mutex);
			return (1);
		}
		pthread_mutex_unlock(&philo->data->death_mutex);
	}
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
			if (check_and_record_death(&data->philos[i]))
				return (NULL);
			i++;
		}
		if (check_dead(data))
			return (NULL);
		usleep(500);
	}
	return (NULL);
}
