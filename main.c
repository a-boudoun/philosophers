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
        if (data.philo_have_eaten == data.nb_philo)
        {
            printf("we are done\n");
            return(0);
        }
    }
    return(0);
}
    // printf("time to die %d\n", data.time_die);
    // printf("time to eat  %d\n", data.time_eat);
    // printf("time to sleep %d\n", data.time_sleep);
    // printf("nbr must eat %d\n", data.must_eat);