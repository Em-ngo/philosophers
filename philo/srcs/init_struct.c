/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:58:17 by engo              #+#    #+#             */
/*   Updated: 2022/12/15 19:18:18 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(int ac, char **av, t_philo *philo)
{
	philo->philo = ft_atoi(av[1]);
	philo->t_to_die = ft_atoi(av[2]);
	philo->t_to_eat = ft_atoi(av[3]);
	philo->t_to_sleep = ft_atoi(av[4]);
	pthread_mutex_init(&philo->write, NULL);
	if (ac == 6)
		philo->meal = ft_atoi(av[5]);
	else
		philo->meal = 0;
}
