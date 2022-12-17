/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:35:10 by engo              #+#    #+#             */
/*   Updated: 2022/12/17 14:19:34 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
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
