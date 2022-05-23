#include"philosophers.h"

void    takeFork(t_philo *ph)
{
	pthread_mutex_lock(&(ph->left_fork));
	printf("philosopher %d taking left fork\n", ph->nbr + 1);
	pthread_mutex_lock(ph->right_fork);
	printf("philosopher %d taking right fork\n", ph->nbr + 1);
	printf("philo %d is eating\n", ph->nbr + 1);
	usleep(2000);
	pthread_mutex_unlock(&(ph->left_fork));
	printf("philosopher %d put left fork\n", ph->nbr + 1);
	pthread_mutex_unlock(ph->right_fork);
	printf("philosopher %d put right fork\n", ph->nbr + 1);
	usleep(2000);
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
		usleep(200);
	}
}
