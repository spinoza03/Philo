/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:23:14 by ilallali          #+#    #+#             */
/*   Updated: 2025/05/08 19:47:29 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if(philo->id % 2 == 0)
		ft_usleep(1);
	while(!chi_7ed_mat(philo->data))
	{
		print_act(philo, "is thinking");
		pick_up(philo);
		print_act(philo, "is eating");
		pthread_mutex_lock(&philo->meal_lock);
		philo->last_meal_time = get_curent_time();
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->meal_lock);
		ft_usleep(philo->data->time_to_eat);
		put_down(philo);
		print_act(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
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
		if(pthread_create(&data->philos[i].thread,
			NULL, routine, &data->philos[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
}
