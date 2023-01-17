/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:35:10 by engo              #+#    #+#             */
/*   Updated: 2023/01/17 15:12:51 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat_and_more(t_philo *philo)
{
	if (!ft_check_death(philo) && !max_meals(philo - (philo->id - 1)))
		ft_eat(philo);
	if (!ft_check_death(philo) && !max_meals(philo - (philo->id - 1)))
		ft_sleep(philo, philo->data_ptr->tts * 1000);
	if (!ft_check_death(philo) && !max_meals(philo - (philo->id - 1)))
		ft_think(philo);
	usleep(500);
}

void	*ft_loop(t_philo *philo)
{
	if (philo->data_ptr->nb_philo == 1)
	{
		display(philo, LOCK_FORK);
		pthread_mutex_lock(&philo->data_ptr->check_die);
		philo->data_ptr->die = 1;
		pthread_mutex_unlock(&philo->data_ptr->check_die);
		usleep(philo->data_ptr->ttd * 1000);
		display(philo, DIE);
		return (0);
	}
	if (philo->data_ptr->nb_philo % 2)
	{
		if (philo->id == philo->data_ptr->nb_philo)
			ft_usleep(philo, (philo->data_ptr->tte * 1000) * 2);
		else if (philo->id % 2)
			ft_usleep(philo, philo->data_ptr->tte * 1000);
	}
	else if (!(philo->data_ptr->nb_philo % 2) && (philo->id % 2))
		ft_usleep(philo, philo->data_ptr->tte * 1000);
	while (!ft_check_death(philo) && !max_meals(philo - (philo->id - 1)))
		ft_eat_and_more(philo);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		data;
	t_philo		*philo;

	if (check_args(ac, av) == 1)
		return (0);
	else if (ac == 6 || ac == 5)
	{
		if (!init_struct(ac, av, &data))
			return (5);
		philo = init_philo_struct(&data);
		if (!philo)
			return (ft_garbage(&data), 0);
		int tesm = init_thread(&data, philo);
		if (tesm)
			return (tesm);
		return (ft_garbage(&data), free(philo), 0);
	}
}
