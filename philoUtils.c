#include"philosophers.h"

int check_args(int ac, char **av)
{
    int i;
    int j;

    if (ac != 6 && ac != 5)
    {
        printf("%swrong arguments\n", RED);
        printf("%splease enter: ", WHT);
        printf("%s./philo [number_of_philosophers] [time_to_die] [time_to_eat] ", WHT);
		printf("%s[time_to_sleep] [number_of_times_each_philosopher_must_eat (optional argument)]\n ", WHT);
		printf("%s <time must be in milliseconds>\n", GRN);
        return(1);
    }
    i = 1;
    while(av[i])
    {
        j = 0;
        while(av[i][j])
        {
            if (av[i][j] == '-')
            {
                printf("%swrong arguments\n", RED);
                printf("%smust be a positive number\n", RED);
                return(1);
            }
            j++;
        }
        i++;
    }
    return(0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	s;
	int	n;

	s = 1;
	i = 0;
	n = 0;
	while (str[i] == ' ' || str[i] == '\t' || str [i] == '\f'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		n = n * 10 + ((int)str[i] - '0');
		i++;
	}
	return (n * s);
}