/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:31:49 by ilallali          #+#    #+#             */
/*   Updated: 2025/05/06 13:44:20 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main (int ac, char **av)
{
	int	i;
	int	succes;

	if (ac == 5 || ac == 6)
	{
		i = 1;
		while (ac > i)
		{
			succes = pars_args(av[i]);
			if (!succes)
				ft_putstr_fd("Please Put Right ARGSSS\n",2);
			i++;
		}
		return 0;
	}
	fill_data(av);
	ft_putstr_fd("Error: Expected 4 or 5 arguments\n",2);
}
