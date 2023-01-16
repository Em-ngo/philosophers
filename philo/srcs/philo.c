/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:00:06 by engo              #+#    #+#             */
/*   Updated: 2022/12/21 14:51:40 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lock_fork(t_data *data)
{
	if (data->id == 1)
	{
		pthread_mutex_lock(\
		&data->philo_ptr->fork[data->philo_ptr->nb_philo - 1]);
		pthread_mutex_lock(&data->philo_ptr->fork[data->id - 1]);
		display(data, LOCK_FORK);
		display(data, LOCK_FORK);
	}
	else
	{
		pthread_mutex_lock(&data->philo_ptr->fork[data->id - 1]);
		pthread_mutex_lock(&data->philo_ptr->fork[data->id - 2]);
		display(data, LOCK_FORK);
		display(data, LOCK_FORK);
	}
}

void	ft_unlock_fork(t_data *data)
{
	if (data->id == 1)
	{
		pthread_mutex_unlock(\
		&data->philo_ptr->fork[data->philo_ptr->nb_philo - 1]);
		pthread_mutex_unlock(&data->philo_ptr->fork[data->id - 1]);
	}
	else
	{
		pthread_mutex_unlock(&data->philo_ptr->fork[data->id - 1]);
		pthread_mutex_unlock(&data->philo_ptr->fork[data->id - 2]);
	}
}

int	max_meals(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->philo_ptr->check_max_eat);
	if (data->philo_ptr->max_eat == -1)
	{
		pthread_mutex_unlock(&data->philo_ptr->check_max_eat);
		return (0);
	}
	while (i < data->philo_ptr->nb_philo)
	{
		if (data[i].nb_meal < data->philo_ptr->max_eat)
		{
			pthread_mutex_unlock(&data->philo_ptr->check_max_eat);
			return (0);
		}
		i++;
	}
	pthread_mutex_unlock(&data->philo_ptr->check_max_eat);
	return (1);
}

int	ft_check_death(t_data *data)
{
	pthread_mutex_lock(&data->philo_ptr->check_die);
	if (!data->philo_ptr->die)
	{
		pthread_mutex_unlock(&data->philo_ptr->check_die);
		return (0);
	}
	pthread_mutex_unlock(&data->philo_ptr->check_die);
	return (1);
}
