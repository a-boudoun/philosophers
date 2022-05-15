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

typedef struct s_args
{
    int nb_philo;
    int time_eat;
    int time_die;
    int time_sleep;
    int must_eat;

}       t_agrs;

/*****MAIN_FUNCYIONS****/
long long   ft_get_time();
int         check_args(int ac, char **av);

#endif