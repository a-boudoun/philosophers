/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoUtils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:41:18 by aboudoun          #+#    #+#             */
/*   Updated: 2022/05/23 16:59:47 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	get_philodata(t_data *data)
{
	int	i;

	pthread_mutex_init(&(data->print), NULL);
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	i = -1;
	while (++i < data->nb_philo)
	{
		data->philo[i].nbr = i;
		pthread_mutex_init(&(data->philo[i].left_fork), NULL);
	}
	i = -1;
	while (++i < data->nb_philo)
	{
		if (i == data->nb_philo - 1)
			data->philo[i].right_fork = &(data->philo[0].left_fork);
		else
			data->philo[i].right_fork = &(data->philo[i + 1].left_fork);
		pthread_create(&(data->philo->philo_t), \
            NULL, &ft_actions, &data->philo[i]);
	}
	while (i)
	{
		pthread_join(data->philo[i].philo_t, NULL);
		i--;
	}
}

void	get_data(char **av, t_data *data)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (av[5])
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = 0;
}

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 6 && ac != 5)
	{
		printf("%swrong arguments\n", RED);
		printf("%splease enter: ./philo [number_of_philosophers] ", WHT);
		printf("%s[time_to_die] [time_to_eat] [time_to_sleep] ", WHT);
		printf("%s[number_of_times_each_philosopher_must_eat (optional argument)]\n ", WHT);
		printf("%s <time must be in milliseconds>\n", GRN);
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
				printf("%swrong arguments\n", RED);
				printf("%sall arguments must be a positive number\n", RED);
				return (1);
			}
		}
	}
	return (0);
}

long long	ft_get_time(void)
{
	struct timeval	current_time;
	long long		time;

	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
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
