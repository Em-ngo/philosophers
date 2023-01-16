/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:00:06 by engo              #+#    #+#             */
/*   Updated: 2022/01/15 21:04:40 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(t_data *data, long t2s)
{
	long	start_time;

	start_time = current_time();
	while (((current_time() - start_time) * 1000) < t2s
		&& !ft_check_death(data) && !max_meals(data - (data->id - 1)))
		usleep(50);
}

void	ft_garbage(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		pthread_mutex_destroy(&philo->fork[i]);
		i++;
	}
	i = 0;
	free(philo->fork);
	pthread_mutex_destroy(&philo->write);
	pthread_mutex_destroy(&philo->check_die);
	pthread_mutex_destroy(&philo->check_last_eat);
	pthread_mutex_destroy(&philo->check_max_eat);
}

long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
