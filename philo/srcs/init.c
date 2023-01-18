/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:58:17 by engo              #+#    #+#             */
/*   Updated: 2023/01/17 16:49:42 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	init_thread(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&philo[i].philo_thread, NULL, \
		(void *)&ft_loop, philo + i))
			return (0);
		i++;
	}
	i = 0;
	usleep(50);
	ft_death(data, philo);
	while (i < data->nb_philo)
	{
		if (pthread_join(philo[i].philo_thread, NULL))
			return (0);
		i++;
	}
	return (1);
}

t_philo	*init_philo_struct(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * (data->nb_philo));
	if (!philo)
		return (0);
	while (i < data->nb_philo)
	{
		philo[i].data_ptr = data;
		philo[i].id = i + 1;
		philo[i].last_eat = 0;
		philo[i].nb_meal = 0;
		i++;
	}
	return (philo);
}

t_bool	init_fork_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (0);
		i++;
	}
	if (pthread_mutex_init(&data->write, NULL))
		return (0);
	if (pthread_mutex_init(&data->check_max_eat, NULL))
		return (0);
	if (pthread_mutex_init(&data->check_last_eat, NULL))
		return (0);
	if (pthread_mutex_init(&data->check_die, NULL))
		return (0);
	return (1);
}

t_bool	init_struct(int ac, char **av, t_data *data)
{
	data->nb_philo = ft_atoi(av[1]);
	data->ttd = ft_atoi(av[2]);
	data->tte = ft_atoi(av[3]);
	data->tts = ft_atoi(av[4]);
	data->time = current_time();
	data->die = 0;
	if ((data->nb_philo <= 0)
		|| data->ttd <= 0 || data->tte <= 0 || data->tts <= 0)
		return (0);
	if (ac == 6)
	{
		data->max_eat = ft_atoi(av[5]);
		if (data->max_eat <= -1)
			return (0);
	}
	else
		data->max_eat = -1;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
		return (0);
	if (!init_fork_mutex(data))
		return (ft_garbage(data), 0);
	return (1);
}
