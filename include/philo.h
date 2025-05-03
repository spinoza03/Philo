/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:12:38 by ilallali          #+#    #+#             */
/*   Updated: 2025/05/03 16:35:28 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	time_lock;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	left_fork;
}	t_philo;

typedef	struct s_data
{
	int	num_philos;
	int	time_to_die;
	int	time_to_sleep;
	int	time_to_eat;
	int	must_eat;
	int	required_meal;
	int	meal_eat;
	int	someone_die;
	long	start_time;
	pthread_mutex_t	forks;
	pthread_mutex_t	print_mutex;
	t_philo	*philos;
}	t_data;


int	pars_args(char *str);
void	ft_putstr_fd(char *s, int fd);
int	ft_atoi(const char *str, int *error);
#endif