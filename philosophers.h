#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <sys/time.h>
#include <time.h>
#include<unistd.h>
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
    long long start_time;
    struct s_data   *data;

}   t_philo;

typedef struct s_data
{
    t_philo   *philo;
    int on_dead;
    int nb_philo;
    int time_eat;
    int time_die;
    int time_sleep;
    int must_eat;
    int philo_have_eaten;
    int print_time;
    pthread_mutex_t print;
}       t_data;


/*****MAIN_FUNCTIONS****/
long long   ft_get_time();
int end_diner(t_data *data);
void	ft_print(char *messege, int p, t_data *data);
void    ft_destroy(t_data *data);
void        get_data(char **av, t_data *data);
void        get_philodata(t_data *data);
int         check_args(int ac, char **av);
int         ft_atoi(char *str);
void        *ft_actions(void    *philo);

#endif