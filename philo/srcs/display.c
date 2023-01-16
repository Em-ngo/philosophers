#include "philo.h"

<<<<<<< HEAD
void	display(t_data *data, int str)
{
	pthread_mutex_lock(&data->philo_ptr->write);
	if (!ft_check_death(data) && !max_meals(data - (data->id - 1)))
	{
		if (str == THINK)
			printf("%ld - Philosophers %d is thinking\n",
				current_time() - data->philo_ptr->time, data->id);
		else if (str == SLEEP)
			printf("%ld - Philosophers %d is sleeping\n",
				current_time() - data->philo_ptr->time, data->id);
		else if (str == EAT)
			printf("%ld - Philosophers %d is eating\n",
				current_time() - data->philo_ptr->time, data->id);
		else if (str == LOCK_FORK)
			printf("%ld - Philosophers %d has taken a fork\n",
				current_time() - data->philo_ptr->time, data->id);
	}
	else if (str == DIE && !ft_check_death(data - (data->id - 1)))
		printf("%ld - Philosophers %d died\n", \
		current_time() - data->philo_ptr->time, data->id);
	pthread_mutex_unlock(&data->philo_ptr->write);
}

void	ft_think(t_data *data)
{
	if (!ft_check_death(data))
		display(data, THINK);
}

void	ft_sleep(t_data *data, long time2sleep)
{
	if (!ft_check_death(data))
	{
		display(data, SLEEP);
		ft_usleep(data, time2sleep);
	}
}

void	ft_eat(t_data *data)
{
	if (!ft_check_death(data))
	{
		ft_lock_fork(data);
		pthread_mutex_lock(&data->philo_ptr->check_last_eat);
		data->last_eat = current_time() - data->philo_ptr->time;
		pthread_mutex_unlock(&data->philo_ptr->check_last_eat);
		display(data, EAT);
		pthread_mutex_lock(&data->philo_ptr->check_max_eat);
		data->nb_meal++;
		pthread_mutex_unlock(&data->philo_ptr->check_max_eat);
		ft_usleep(data, data->philo_ptr->t2e * 1000);
		ft_unlock_fork(data);
	}
}

void	ft_death(t_data *data, t_philo *philo)
{
	int	i;

	while (!ft_check_death(data))
	{
		i = 0;
		while (i < philo->nb_philo)
		{
			pthread_mutex_lock(&data->philo_ptr->check_last_eat);
			if ((current_time() - philo->time - data[i].last_eat) >= philo->t2d)
			{
				pthread_mutex_unlock(&data->philo_ptr->check_last_eat);
				pthread_mutex_lock(&data->philo_ptr->check_die);
				philo->die = data->id;
				pthread_mutex_unlock(&data->philo_ptr->check_die);
				display(data + i, DIE);
				return ;
			}
			else
				pthread_mutex_unlock(&data->philo_ptr->check_last_eat);
			i++;
		}	
	}
}
=======
void    display(t_philo *philochar *msg)
>>>>>>> 21642b23b12191e8daf7d110b2774531e41f9549
