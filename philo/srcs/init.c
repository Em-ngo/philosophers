/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:58:17 by engo              #+#    #+#             */
/*   Updated: 2022/12/22 17:20:34 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = 0;
	philo = malloc(sizeof(t_philo) * (philo->n_philo));
	while (i <= philo->n_philo)
	{
		philo->data[i].last_eat = current_time();
		philo->data[i].id = i + 1;
		philo->data[i].meal = 0;
		i++;
	}
	return (philo);
}

int	init_forks(t_philo *philo)
{
	int		i;

	i = 0;
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->n_philo);
	if (!philo->forks)
		return (1);
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
	philo->n_philo = ft_atoi(av[1]);
	philo->t_to_die = ft_atoi(av[2]);
	philo->t_to_eat = ft_atoi(av[3]);
	philo->t_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->meal = ft_atoi(av[5]);
	else
		philo->meal = 0;
}
