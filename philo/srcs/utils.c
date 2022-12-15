/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:07:04 by engo              #+#    #+#             */
/*   Updated: 2022/12/15 15:02:17 by engo             ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	nb;

	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - 48;
		str++;
	}
	return (nb);
}

int	check_intmax(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) >= INT_MAX || (ft_strlen(av[i]) > 11))
			return (1);
		i++;
	}
	return (0);
}

int	check_isalnum(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
