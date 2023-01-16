/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:35:10 by engo              #+#    #+#             */
/*   Updated: 2023/01/16 12:12:30 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat_and_more(t_data *data)
{
	if (!ft_check_death(data) && !max_meals(data - (data->id - 1)))
		ft_eat(data);
	if (!ft_check_death(data) && !max_meals(data - (data->id - 1)))
		ft_sleep(data, data->philo_ptr->t2s * 1000);
	if (!ft_check_death(data) && !max_meals(data - (data->id - 1)))
		ft_think(data);
	usleep(500);
}

void	*ft_loop(t_data *data)
{
	if (data->philo_ptr->nb_philo == 1)
	{
		display(data, LOCK_FORK);
		pthread_mutex_lock(&data->philo_ptr->check_die);
		data->philo_ptr->die = 1;
		pthread_mutex_unlock(&data->philo_ptr->check_die);
		usleep(data->philo_ptr->t2d * 1000);
		display(data, DIE);
		return (0);
	}
	if (data->philo_ptr->nb_philo % 2)
	{
		if (data->id == data->philo_ptr->nb_philo)
			ft_usleep(data, (data->philo_ptr->t2e * 1000) * 2);
		else if (data->id % 2)
			ft_usleep(data, data->philo_ptr->t2e * 1000);
	}
	else if (!(data->philo_ptr->nb_philo % 2) && (data->id % 2))
		ft_usleep(data, data->philo_ptr->t2e * 1000);
	while (!ft_check_death(data) && !max_meals(data - (data->id - 1)))
		ft_eat_and_more(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo			philo;
	t_data			*data;

	if (check_args(ac, av) == 1)
		return (0);
	else if (ac == 6 || ac == 5)
	{
		if (init_struct(ac, av, &philo) == 1)
			return (0);
		data = init_philo_struct(&philo);
		if (!data)
			return (ft_garbage(&philo), 0);
		if (init_thread(&philo, data))
			return (0);
		return (ft_garbage(&philo), free(data), 1);
	}
}
