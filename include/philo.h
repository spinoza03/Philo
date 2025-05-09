/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:12:38 by ilallali          #+#    #+#             */
/*   Updated: 2025/05/09 15:00:44 by ilallali         ###   ########.fr       */
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
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	int				left_fork_id;
	int				right_fork_id;
	pthread_t		thread;
	pthread_mutex_t	meal_lock;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				someone_die;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_t		death_thread;
	pthread_t		meal_thread;
	t_philo			*philos;
}	t_data;

int	fill_data(char **av, t_data *data);
int		init_philos(t_data *data);
int		pars_args(char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
long	get_curent_time(void);
void	ft_usleep(long time);
void	print_act(t_philo *philo, char *action);
void	pick_up(t_philo *philo);
void	put_down(t_philo *philo);
int		check_dead(t_data *data);
int		start_simulation(t_data *data);
void	print_act(t_philo *philo, char *msg);
void	pick_up(t_philo *philo);
void	put_down(t_philo *philo);
int		check_dead(t_data *data);
void	*death_monitor(void *arg);
#endif