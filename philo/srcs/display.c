/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:14:08 by engo              #+#    #+#             */
/*   Updated: 2023/01/30 15:04:15 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display(t_philo *philo, int msg)
{
	pthread_mutex_lock(&philo->data_ptr->write);
	if (!ft_check_death(philo) && !max_meals(philo - (philo->id - 1)))
	{
		if (msg == THINK)
			printf(GREY "%ld - Philosophers %d is thinking\n", \
			current_time() - philo->data_ptr->time, philo->id);
		else if (msg == SLEEP)
			printf(BLUE "%ld - Philosophers %d is sleeping\n", \
			current_time() - philo->data_ptr->time, philo->id);
		else if (msg == EAT)
			printf(CYAN "%ld - Philosophers %d is eating\n", \
			current_time() - philo->data_ptr->time, philo->id);
		else if (msg == LOCK_FORK)
			printf(PURPLE "%ld - Philosophers %d has taken a fork\n", \
			current_time() - philo->data_ptr->time, philo->id);
	}
	else if (msg == DIE && !max_meals(philo - (philo->id - 1)))
		printf(RED "%ld - Philosophers %d died\n", \
		current_time() - philo->data_ptr->time, philo->id);
	pthread_mutex_unlock(&philo->data_ptr->write);
}

void	ft_think(t_philo *philo)
{
	if (!ft_check_death(philo))
		display(philo, THINK);
	usleep(((philo->data_ptr->ttd - (philo->data_ptr->tte \
	+ philo->data_ptr->tts)) / 2) * 1000);
}

void	ft_sleep(t_philo *philo, long long tts)
{
	if (!ft_check_death(philo))
	{
		display(philo, SLEEP);
		ft_usleep(philo, tts);
	}
}

void	ft_eat(t_philo *philo)
{
	if (!ft_check_death(philo))
	{
		ft_lock_fork(philo);
		pthread_mutex_lock(&philo->data_ptr->check_last_eat);
		philo->last_eat = current_time() - philo->data_ptr->time;
		pthread_mutex_unlock(&philo->data_ptr->check_last_eat);
		display(philo, EAT);
		pthread_mutex_lock(&philo->data_ptr->check_max_eat);
		philo->nb_meal++;
		pthread_mutex_unlock(&philo->data_ptr->check_max_eat);
		ft_usleep(philo, philo->data_ptr->tte * 1000);
		ft_unlock_fork(philo);
	}
}

void	ft_death(t_data *data, t_philo *philo)
{
	int	i;

	while (!ft_check_death(philo))
	{
		i = 0;
		while (i < data->nb_philo)
		{
			pthread_mutex_lock(&philo->data_ptr->check_last_eat);
			if ((current_time() - data->time - philo[i].last_eat) >= data->ttd)
			{
				pthread_mutex_unlock(&philo->data_ptr->check_last_eat);
				pthread_mutex_lock(&philo->data_ptr->check_die);
				data->die = philo->id;
				pthread_mutex_unlock(&philo->data_ptr->check_die);
				display(philo + i, DIE);
				return ;
			}
			else
				pthread_mutex_unlock(&philo->data_ptr->check_last_eat);
			i++;
		}	
	}
}
