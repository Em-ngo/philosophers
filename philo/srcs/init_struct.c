/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:58:17 by engo              #+#    #+#             */
/*   Updated: 2022/12/17 15:28:25 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_nb_forks(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->n_philo)
	{
		philo[i].data->r_fork = malloc(sizeof(pthread_mutex_t));
		if (!philo[i].data->r_fork)
			return (NULL);
		i++;
	}
	i = 0;
	while (i < philo->n_philo)
	{
		philo[i].data->l_fork = philo->data[(i + 1) % philo->n_philo].r_fork;
		i++;
	}
}

void	init_struct(int ac, char **av, t_philo *philo)
{
	philo->philo = ft_atoi(av[1]);
	philo->t_to_die = ft_atoi(av[2]);
	philo->t_to_eat = ft_atoi(av[3]);
	philo->t_to_sleep = ft_atoi(av[4]);
	pthread_mutex_init(&philo->data->write, NULL);
	if (ac == 6)
		philo->meal = ft_atoi(av[5]);
	else
		philo->meal = 0;
}
