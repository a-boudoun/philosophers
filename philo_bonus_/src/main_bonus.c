/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:42:39 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/20 20:46:47 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	get_data(char **av, t_data *data)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (av[5])
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = 0;
	data->finish = 0;
	data->philo_have_eaten = 0;
	pthread_mutex_init(&(data->print), NULL);
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!(data->philo))
	{
		printf("malloc error\n");
		return (1);
	}
	get_philodata(data);
	return (0);
}

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 6 && ac != 5)
	{
		printf("%splease enter: ./philo [number_of_philosophers] ", WHT);
		printf("%s[time_to_die] [time_to_eat] [time_to_sleep] [number_of", WHT);
		printf("%s_times_each_philosopher_must_eat(optional argument)]\n ", WHT);
		printf("%s <time must be in milliseconds>\n", RED);
		return (1);
	}
	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			{
				printf("%sall arguments must be positive numbers\n", RED);
				return (1);
			}
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av))
		return (1);
	if (get_data(av, &data))
		return (1);
	ft_destroy(&data);
	return (0);
}
