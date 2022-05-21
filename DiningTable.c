#include"philosophers.h"

void    takeFork(t_philo *ph)
{
    pthread_mutex_lock(&(ph->left_fork));
    pthread_mutex_lock(ph->right_fork);
    pthread_mutex_unlock(&(ph->left_fork));
    pthread_mutex_unlock(ph->right_fork);
}

void    Eat(t_philo *ph)
{

}

void    *ft_actions(void *philo)
{
    t_philo *ph;

    ph = philo;
    if (ph->nbr % 2 == 0)
        usleep(200);
    while (1)
    {
        takeFork(ph);
        eat(ph);
    }
}