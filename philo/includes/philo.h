/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:13:33 by engo              #+#    #+#             */
/*   Updated: 2022/12/17 17:06:07 by engo             ###   ########.fr       */
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
	pthread_mutex_t	time;
	pthread_mutex_t	death;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int				l_died;
}				t_data;

typedef struct s_philo
{
	pthread_mutex_t	write;
	int				n_philo;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				meal;
	t_data			*data;
}				t_philo;

int		ft_atoi(char *str);

int		check_isalnum(int ac, char **av);
int		check_intmax(int ac, char **av);
int		check_args(int ac, char **av);

void	init_struct(int ac, char **av, t_philo *philo);
void	init_forks(t_philo *philo);

void	*routine(void *tmp);
void	*routine(void *tmp);
void	ft_exec(int ac, char **av, t_philo philo, pthread_t *t1);

#endif
