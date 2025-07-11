/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:31:49 by ilallali          #+#    #+#             */
/*   Updated: 2025/07/11 18:17:58 by ilallali         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 1;
	if (ac != 5 && ac != 6)
	{
		ft_putstr_fd("Error: Expected 4 or 5 arguments\n", 2);
		return (1);
	}
	while (i < ac)
	{
		if (!pars_args(av[i++]))
		{
			ft_putstr_fd("Error: Invalid argument\n", 2);
			return (1);
		}
	}
	if (fill_data(av, &data) == -1)
		return (error_exit("Data init failed"));
	if (init_philos(&data) == -1)
		return (error_exit("Philo init failed"));
	if (start_simulation(&data) == -1)
		return (error_exit("Simulation failed"));
	join_threads(&data);
	return (cleanup(&data), 0);
}
