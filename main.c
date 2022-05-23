#include"philosophers.h"

int main(int ac, char **av)
{
    t_data  data;

    if (check_args(ac, av))
        return(0);
    get_data(av, &data);
    get_philodata(&data);
    while (1)
    {

    }
    return(0);
}
    // printf("nbr of philosophers %d\n", data.nb_philo);
    // printf("time to die %d\n", data.time_die);
    // printf("time to eat  %d\n", data.time_eat);
    // printf("time to sleep %d\n", data.time_sleep);
    // printf("nbr must eat %d\n", data.must_eat);