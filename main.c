#include"philosophers.h"

void    get_data(char **av, t_args *args)
{
    args->nb_philo = av[1];
    args->time_die = av[2];
    args->time_eat = av[3];
    args->time_sleep = av[4];
    if (av[5])
        args->must_eat = av[5];
    else
        args->must_eat = 0;
}
int main(int ac, char **av)
{
    t_args  agrs;

    check_args(ac, av);
    get_data(av, &agrs);
    return(0);
}
    