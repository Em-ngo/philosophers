/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:07:04 by engo              #+#    #+#             */
/*   Updated: 2022/12/14 18:07:28 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(char **av, t_philo *philo)
{
	philo->philo = ft_atoi(av[1]);
	philo->t_to_die = ft_atoi(av[2]);
	philo->t_to_eat = ft_atoi(av[3]);
	philo->t_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->meal = ft_atoi(av[5]);
}

int	ft_atoi(const char *str)
{
	int	nb;

	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - 48;
		str++;
	}
	return (nb);
}

int	check_isalnum(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
