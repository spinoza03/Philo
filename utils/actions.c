/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:13:09 by ilallali          #+#    #+#             */
/*   Updated: 2025/05/08 20:29:16 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_up(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if(philo->id % 2 == 0)
	{
		pthread_mutex_lock(&data->forks[philo->right_fork_id]);
		print_act(philo, "has taken a fork");
		pthread_mutex_lock(&data->forks[philo->left_fork_id]);
		print_act(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&data->forks[philo->left_fork_id]);
		print_act(philo, "has taken a fork");
		pthread_mutex_lock(&data->forks[philo->right_fork_id]);
		print_act(philo, "has taken a fork");
	}
}

void	put_down(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_unlock(&data->forks[philo->left_fork_id]);
	pthread_mutex_unlock(&data->forks[philo->right_fork_id]);
}

void	print_act(t_philo *philo, char *msg)
{
	t_data	*data;
	long	timestamp;

	data = philo->data;
	pthread_mutex_lock(&data->print_mutex);
	if (!has_someone_died(data))
	{
		timestamp = get_current_time() - data->start_time;
		printf("%ld %d %s\n", timestamp, philo->id + 1, msg);
	}
	pthread_mutex_unlock(&data->print_mutex);
}

int	has_someone_died(t_data *data)
{
	return (data->someone_die);
}
