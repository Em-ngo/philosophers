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

void	ft_lock_fork(t_philo *philo)
{
	if (philo->id == 1)
	{
		pthread_mutex_lock(\
		&philo->data_ptr->fork[philo->data_ptr->nb_philo - 1]);
		pthread_mutex_lock(&philo->data_ptr->fork[philo->id - 1]);
		display(philo, LOCK_FORK);
		display(philo, LOCK_FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->data_ptr->fork[philo->id - 1]);
		pthread_mutex_lock(&philo->data_ptr->fork[philo->id - 2]);
		display(philo, LOCK_FORK);
		display(philo, LOCK_FORK);
	}
}

void	ft_unlock_fork(t_philo *philo)
{
	if (philo->id == 1)
	{
		pthread_mutex_unlock(\
		&philo->data_ptr->fork[philo->data_ptr->nb_philo - 1]);
		pthread_mutex_unlock(&philo->data_ptr->fork[philo->id - 1]);
	}
	else
	{
		pthread_mutex_unlock(&philo->data_ptr->fork[philo->id - 1]);
		pthread_mutex_unlock(&philo->data_ptr->fork[philo->id - 2]);
	}
}

t_bool	max_meals(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->data_ptr->check_max_eat);
	if (philo->data_ptr->max_eat == -1)
	{
		pthread_mutex_unlock(&philo->data_ptr->check_max_eat);
		return (0);
	}
	while (i < philo->data_ptr->nb_philo)
	{
		if (philo[i].nb_meal < philo->data_ptr->max_eat)
		{
			pthread_mutex_unlock(&philo->data_ptr->check_max_eat);
			return (0);
		}
		i++;
	}
	pthread_mutex_unlock(&philo->data_ptr->check_max_eat);
	return (1);
}

t_bool	ft_check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data_ptr->check_die);
	if (!philo->data_ptr->die)
	{
		pthread_mutex_unlock(&philo->data_ptr->check_die);
		return (0);
	}
	pthread_mutex_unlock(&philo->data_ptr->check_die);
	return (1);
}
