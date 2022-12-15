/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:35:10 by engo              #+#    #+#             */
/*   Updated: 2022/12/15 19:45:30 by engo             ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_philo			philo;
	pthread_t		*t1;

	t1 = 0;
	if (check_args(ac, av) == 1)
		return (1);
	else if (ac == 6 || ac == 5)
		ft_exec(ac, av, philo, t1);
	else
	{
		write(2, "Invalid number of arguments. \n", 31);
		return (1);
	}
	return (0);
}
