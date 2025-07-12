/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:12:38 by ilallali          #+#    #+#             */
/*   Updated: 2025/07/12 15:41:57 by ilallali         ###   ########.fr       */
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

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	int				left_fork_id;
	int				right_fork_id;
	long			last_meal_time;
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

/*
** --- Function Prototypes ---
*/

/* Initialization */
int		fill_data(char **av, t_data *data);
int		init_philos(t_data *data);
int		pars_args(char *str);

/* Simulation */
int		start_simulation(t_data *data);
void	*routine(void *arg);

/* Actions */
void	print_act(t_philo *philo, char *msg);
void	pick_up(t_philo *philo);
void	put_down(t_philo *philo);

/* Monitors */
int		check_dead(t_data *data);
void	*death_monitor(void *arg);
void	*meals_monitor(void *arg);

/* Utils */
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
int		ft_atoi1(const char *str, int *num);
long	get_curent_time(void);
void	ft_usleep(long time, t_data *data);
int		is_space(char c);

/* FUNCTIONS */
void	one_philo(t_data *data);
void	cleanup(t_data *data);

#endif