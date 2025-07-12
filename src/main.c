/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:31:49 by ilallali          #+#    #+#             */
/*   Updated: 2025/07/12 15:45:38 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

void	cleanup(t_data *data)
{
	free(data->forks);
	free(data->philos);
}

static int	run_simulation(t_data *data)
{
	if (start_simulation(data) == -1)
		return (error_exit("Simulation failed"));
	join_threads(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 1;
	if (ac != 5 && ac != 6)
		return (error_exit("Error: Expected 4 or 5 arguments"));
	while (i < ac)
	{
		if (!pars_args(av[i++]))
			return (error_exit("Error: Invalid argument"));
	}
	if (fill_data(av, &data) == -1)
		return (error_exit("Data init failed"));
	if (init_philos(&data) == -1)
		return (error_exit("Philo init failed"));
	if (data.num_philos == 1)
		one_philo(&data);
	else
		run_simulation(&data);
	cleanup(&data);
	return (0);
}
