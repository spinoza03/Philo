/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:42:29 by ilallali          #+#    #+#             */
/*   Updated: 2025/05/08 19:57:37 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_curent_time(void)
{
	struct timeval	time;
	long			ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec *1000) + (time.tv_usec / 1000);
	return (ms);
}
void	ft_usleep(long time)
{
	long	start;

	start = get_curent_time();
	while ((get_curent_time() - start) < time)
		usleep(500);
}