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

void	ft_usleep(t_philo *philo, long long tts)
{
	long long	start_time;

	start_time = current_time();
	while (((current_time() - start_time) * 1000) < tts
		&& !ft_check_death(philo) && !max_meals(philo - (philo->id - 1)))
		usleep(50);
}

void	ft_garbage(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	i = 0;
	free(data->fork);
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->check_max_eat);
	pthread_mutex_destroy(&data->check_last_eat);
	pthread_mutex_destroy(&data->check_die);
}

long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
