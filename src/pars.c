/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:51:06 by ilallali          #+#    #+#             */
/*   Updated: 2025/05/03 16:38:12 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_integer(char *str)
{
	if (!str || !*str)
	return (0);
	if (*str == '-' || *str == '+')
	str++;
	if (!*str)
	return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
		return (0);
		str++;
	}
	return (1);
}

int	pars_args(char *str)
{
	int		error;
	
	if (!is_valid_integer(str))
		return (0);
	ft_atoi(str, &error);
	if (!error)
		return (0);
	return (1);
}
