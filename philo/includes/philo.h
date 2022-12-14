/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:13:33 by engo              #+#    #+#             */
/*   Updated: 2022/12/14 18:07:41 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_philo
{
	int	philo;
	int	t_to_die;
	int	t_to_eat;
	int	t_to_sleep;
	int	meal;
}				t_philo;

void	init_struct(char **av, t_philo *philo);
int		check_isalnum(char **str);
int		ft_atoi(const char *str);


#endif
