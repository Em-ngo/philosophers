/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:13:33 by engo              #+#    #+#             */
/*   Updated: 2023/01/20 11:22:42 by engo             ###   ########.fr       */
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

# define GREY "\033[37m"
# define BLUE "\033[94m"
# define RED "\033[91m"
# define CYAN "\033[0;36m"
# define PURPLE "\033[0;35m"

# define SLEEP 1
# define EAT 2
# define THINK 3
# define LOCK_FORK 4
# define DIE 5

typedef int	t_bool;

typedef struct s_data
{
	int				nb_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				max_eat;
	int				die;
	long			time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	write;
	pthread_mutex_t	check_max_eat;
	pthread_mutex_t	check_last_eat;
	pthread_mutex_t	check_die;
}	t_data;

typedef struct s_philo
{
	struct s_data	*data_ptr;
	int				id;
	int				nb_meal;
	long			last_eat;
	pthread_t		philo_thread;
}	t_philo;

int		ft_atoi(const char *str);

int		check_isalnum(int ac, char **av);
int		check_intmax(int ac, char **av);
int		check_args(int ac, char **av);
long	current_time(void);

t_bool	init_struct(int ac, char **av, t_data *data);
t_bool	init_fork_mutex(t_data *data);
t_bool	init_thread(t_data *data, t_philo *philo);
t_philo	*init_philo_struct(t_data *data);

void	ft_garbage(t_data *data);
t_bool	ft_check_death(t_philo *philo);
void	*ft_loop(t_philo *philo);
t_bool	max_meals(t_philo *philo);

void	ft_usleep(t_philo *philo, long long tts);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo, long long tts);
void	ft_think(t_philo *philo);
void	ft_death(t_data *data, t_philo *philo);

void	display(t_philo *philo, int msg);
void	ft_lock_fork(t_philo *philo);
void	ft_unlock_fork(t_philo *philo);

#endif
