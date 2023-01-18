/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:07:04 by engo              #+#    #+#             */
/*   Updated: 2023/01/17 15:34:07 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	long long	r;
	int			neg;

	i = 0;
	r = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (r * neg > INT_MAX)
			return (0);
		r = r * 10 + (str[i] - 48);
		i++;
	}
	return (neg * r);
}

int	check_isalnum(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (!(ac == 5 || ac == 6))
		return (0);
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_intmax(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) > INT_MAX || ft_strlen(av[i]) > 11)
		{
			printf("int max\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	if (check_isalnum(ac, av) == 0 || check_intmax(ac, av) == 0)
	{
		write(2, "Error arguments. \n", 19);
		return (1);
	}
	return (0);
}
