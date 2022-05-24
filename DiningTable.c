#include"philosophers.h"

void	ft_print(char *messege, int p)
{
	printf("%lld %d %s\n", ft_get_time(), p, messege);
}

void	eat(t_philo *ph)
{
	ft_print("is eating", ph->nbr + 1);
	ph->nbr_eat++;
	if (ph->nbr_eat == ph->data->must_eat)
		ph->data->philo_have_eaten++;
	usleep(1000);
}

void	ft_sleep(t_philo *ph)
{
	ft_print("is sleeping", ph->nbr + 1);
	usleep((ph->data->time_sleep) * 1000);
}

void    takeFork(t_philo *ph)
{
	pthread_mutex_lock(&(ph->left_fork));
	ft_print("taking left fork", ph->nbr + 1);
	pthread_mutex_lock(ph->right_fork);
	ft_print("taking right fork", ph->nbr + 1);
	eat(ph);
	pthread_mutex_unlock(&(ph->left_fork));
	//ft_print("put left fork", ph->nbr + 1);
	pthread_mutex_unlock(ph->right_fork);
	//ft_print("put right fork", ph->nbr + 1);
}

void    *ft_actions(void *philo)
{
	t_philo *ph;

	ph = philo;

	if (ph->nbr % 2 == 0)
		usleep(100);
	while (1)
	{
		takeFork(ph);
		ft_sleep(ph);
		ft_print("is thinking", ph->nbr);
		usleep(3000);
	}
}