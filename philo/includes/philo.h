/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:13:33 by engo              #+#    #+#             */
/*   Updated: 2022/12/22 16:34:08 by engo             ###   ########.fr       */
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
# include <stdbool.h>

# define SLEEP 1
# define EAT 2
# define THINK 3
# define LOCK_FORK 4
# define DIE 5

typedef struct s_philo
{
	int				nb_philo;
	int				t2d;
	int				t2e;
	int				t2s;
	int				max_eat;
	int				die;
	long			time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	write;
	pthread_mutex_t	check_max_eat;
	pthread_mutex_t	check_last_eat;
	pthread_mutex_t	check_die;
}				t_philo;

typedef struct t_data
{
	int				id;
	int				nb_meal;
	long			last_eat;
	pthread_t		philo_thread;
	struct s_philo	*philo_ptr;
}				t_data;

int		ft_atoi(char *str);

int		check_isalnum(int ac, char **av);
int		check_intmax(int ac, char **av);
int		check_args(int ac, char **av);
long	current_time(void);

int		init_struct(int ac, char **av, t_philo *philo);
int		init_fork_mutex(t_philo *philo);
int		init_thread(t_philo *philo, t_data *data);
t_data	*init_philo_struct(t_philo *philo);

void	ft_garbage(t_philo *philo);
int		ft_check_death(t_data *data);
void	*ft_loop(t_data *data);
int		max_meals(t_data *data);

void	ft_usleep(t_data *data, long t2s);
void	ft_eat(t_data *data);
void	ft_sleep(t_data *data, long time2sleep);
void	ft_think(t_data *data);
void	ft_death(t_data *data, t_philo *philo);

void	display(t_data *data, int str);
void	ft_lock_fork(t_data *data);
void	ft_unlock_fork(t_data *data);

#endif
