/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:51:06 by ilallali          #+#    #+#             */
/*   Updated: 2025/07/11 18:18:55 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

int	is_valid_integer(char *str)
{
	int	has_digits;

	has_digits = 0;
	if (!str)
		return (0);
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		has_digits = 1;
		str++;
	}
	while (is_space(*str))
		str++;
	if (*str != '\0' || has_digits == 0)
		return (0);
	return (1);
}

int	pars_args(char *str)
{
	int	num;

	if (!is_valid_integer(str))
		return (0);
	if (ft_atoi1(str, &num) <= 0)
		return (0);
	if (!num)
		return (0);
	return (1);
}
