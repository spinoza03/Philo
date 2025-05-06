/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:22:06 by ilallali          #+#    #+#             */
/*   Updated: 2025/05/06 13:44:43 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fill_data(char **av)
{
	t_data *data;
	
	data->num_philos = ft_atoi(av[1],1);
	data->time_to_die = ft_atoi(av[2],1);
	data->time_to_eat = ft_atoi(av[3],1);
	data->time_to_sleep = ft_atoi(av[4],1);
	data->required_meal = ft_atoi(av[5],1);
}