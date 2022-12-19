/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:13:33 by engo              #+#    #+#             */
/*   Updated: 2022/12/19 17:43:36 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h> 
# include <sys/time.h>

typedef struct t_data
{
	pthread_t		time;
	pthread_mutex_t	death;
}				t_data;

typedef struct s_philo
{
	int				n_philo;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				last_died;
	int				meal;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	t_data			*data;
}				t_philo;

int		ft_atoi(char *str);

int		check_isalnum(int ac, char **av);
int		check_intmax(int ac, char **av);
int		check_args(int ac, char **av);

void	init_struct(int ac, char **av, t_philo *philo);
int		init_forks(t_philo *philo);

void	*routine(void *tmp);
void	ft_exec(int ac, char **av, t_philo philo, pthread_t *t1);

#endif
