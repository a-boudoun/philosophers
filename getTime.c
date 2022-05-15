#include "philosophers.h"

long long ft_get_time()
{
    struct timeval current_time;
    long long time;
    gettimeofday(&current_time, NULL);
    time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
    return (time);
}