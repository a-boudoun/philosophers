#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <sys/time.h>
#include <time.h>
#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>

/******COLORS******/
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define WHT "\x1B[37m"

typedef struct s_philo
{
    pthread_t philo_t;
    pthread_mutex_t left_fork;
    pthread_mutex_t *right_fork;
    int nbr;
    int nbr_eat;

}   t_philo;

typedef struct s_data
{
    t_philo   *philo;
    int nb_philo;
    int time_eat;
    int time_die;
    int time_sleep;
    int must_eat;
    pthread_mutex_t print;

}       t_data;


/*****MAIN_FUNCTIONS****/
long long   ft_get_time();
void        get_data(char **av, t_data *data);
int         check_args(int ac, char **av);
int         ft_atoi(char *str);
void        *ft_actions(void    *philo);

#endif