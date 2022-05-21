#include"philosophers.h"

int main(int ac, char **av)
{
    t_data  data;

    check_args(ac, av);
    get_data(av, &data);
    return(0);
}