/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:58:17 by engo              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/16 12:11:34 by engo             ###   ########.fr       */
=======
/*   Updated: 2022/12/22 17:20:34 by engo             ###   ########.fr       */
>>>>>>> 21642b23b12191e8daf7d110b2774531e41f9549
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

<<<<<<< HEAD
int	init_thread(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		if (pthread_create(&data[i].philo_thread, NULL,
				(void *)&ft_loop, philo + i))
			return (0);
		i++;
	}
	i = 0;
	usleep(50);
	ft_death(data, philo);
	while (i < philo->nb_philo)
	{
		if (pthread_join(data[i].philo_thread, NULL))
			return (0);
		i++;
	}
	ft_garbage(philo);
	free(data);
	return (1);
}

t_data	*init_philo_struct(t_philo *philo)
{
	int		i;
	t_data	*data;

	i = 0;
	printf("test");
	data = malloc(sizeof(t_data) * (philo->nb_philo));
	if (!philo)
		return (0);
	while (i < philo->nb_philo)
	{
		data[i].philo_ptr = philo;
		data[i].id = i + 1;
		data[i].last_eat = 0;
		data[i].nb_meal = 0;
		i++;
	}
	return (data);
}

int	init_fork_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		if (pthread_mutex_init(&philo->fork[i], NULL))
			return (0);
		i++;
	}
	if (pthread_mutex_init(&philo->write, NULL))
		return (0);
	if (pthread_mutex_init(&philo->check_max_eat, NULL))
		return (0);
	if (pthread_mutex_init(&philo->check_last_eat, NULL))
		return (0);
	if (pthread_mutex_init(&philo->check_die, NULL))
		return (0);
	return (1);
}

int	init_struct(int ac, char **av, t_philo *philo)
{
	philo->nb_philo = ft_atoi(av[1]);
	philo->t2d = ft_atoi(av[2]);
	philo->t2e = ft_atoi(av[3]);
	philo->t2s = ft_atoi(av[4]);
	philo->time = current_time();
	philo->die = 0;
	printf("test3");
	if ((philo->nb_philo <= 0)
		|| philo->t2d <= 0 || philo->t2e <= 0 || philo->t2s <= 0)
		return (0);
	if (ac == 6)
	{
		philo->max_eat = ft_atoi(av[5]);
		if (philo->max_eat <= 0)
			return (0);
	}
	else
		philo->max_eat = 0;
	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->nb_philo);
	if (!philo->fork)
		return (0);
	if (!init_fork_mutex(philo))
		return (ft_garbage(philo), 0);
	return (1);
=======
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
>>>>>>> 21642b23b12191e8daf7d110b2774531e41f9549
}
