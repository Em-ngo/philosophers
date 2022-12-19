/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:58:17 by engo              #+#    #+#             */
/*   Updated: 2022/12/19 17:46:24 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	init_forks(t_philo *philo)
{
	int		i;

	i = 0;
	while (i < philo->n_philo)
	{
		if (pthread_mutex_init(&philo->forks[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&philo->write, NULL))
		return (1);
	return (0);
}

void	init_struct(int ac, char **av, t_philo *philo)
{
	(void)ac;
	philo->n_philo = ft_atoi(av[1]);
	philo->t_to_die = ft_atoi(av[2]);
	philo->t_to_eat = ft_atoi(av[3]);
	philo->t_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->meal = ft_atoi(av[5]);
	else
		philo->meal = 0;
}
