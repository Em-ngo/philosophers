/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:00:06 by engo              #+#    #+#             */
/*   Updated: 2022/12/17 17:06:32 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *tmp)
{
	t_philo	*philo;

	philo = (t_philo *)tmp;
	pthread_mutex_lock(&philo->write);
	printf("philo created\n");
	pthread_mutex_unlock(&philo->write);
	sleep(2);
	pthread_mutex_lock(&philo->write);
	printf("philo died\n");
	pthread_mutex_unlock(&philo->write);
	return (tmp);
}

void	ft_exec(int ac, char **av, t_philo philo, pthread_t *t1)
{
	int	nb_philo;

	init_struct(ac, av, &philo);
	nb_philo = ft_atoi(av[1]);
	init_forks(&philo);
	t1 = malloc(sizeof(t_philo) * nb_philo);
	while (nb_philo > 0)
	{
		pthread_create(&t1[nb_philo], NULL, &routine, &philo);
		--nb_philo;
	}
	while (nb_philo <= philo.n_philo)
	{
		pthread_join(t1[nb_philo], NULL);
		++nb_philo;
	}
	free(t1);
}
