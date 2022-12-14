/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:35:10 by engo              #+#    #+#             */
/*   Updated: 2022/12/14 18:07:14 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	if (check_isalnum(av) == 1)
	{
		write(2, "Error arguments. \n", 19);
		return (1);
	}
	init_struct(av, &philo);
	if (ac == 6 || ac == 5)
	{
		printf("fonctionne\n");
	}
	else
	{
		write(2, "Invalid number of arguments. \n", 31);
		return (1);
	}
	return (0);
}
