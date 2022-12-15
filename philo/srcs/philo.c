/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:00:06 by engo              #+#    #+#             */
/*   Updated: 2022/12/15 19:48:20 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exec(int ac, char **av, t_philo philo, pthread_t *t1)
{
	int	nb_philo;

	init_struct(ac, av, &philo);
	nb_philo = ft_atoi(av[1]);
	t1 = malloc(sizeof(t_philo) * nb_philo);
	while (nb_philo > 0)
	{
		pthread_create(&t1[nb_philo], NULL, &routine, &philo);
		--nb_philo;
	}
	while (nb_philo <= philo.philo)
	{
		pthread_join(t1[nb_philo], NULL);
		++nb_philo;
	}
	free(t1);
}
