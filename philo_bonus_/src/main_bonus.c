/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:42:39 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/23 15:56:25 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"
/*644
  6 > read/write permisson for the user
  4 > read only for the group and others
  */
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
	data->philo_have_eaten = 0;
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	data->table_id = malloc(sizeof(int));
	if (!(data->philo) || !(data->table_id))
		print_err("malloc error\n");
	data->forks = sem_open("forks", O_CREAT, 644, data->nb_philo);
	data->print = sem_open("print", O_CREAT, 644, 1);
	data->finish = sem_open("finish", O_CREAT, 644, 0);
	get_philodata(data);
}

void	check_args(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 6 && ac != 5)
	{
		printf("%splease enter: ./philo [number_of_philosophers] ", WHT);
		printf("%s[time_to_die] [time_to_eat] [time_to_sleep] [number_of", WHT);
		printf("%s_times_each_philosopher_must_eat(optional argument)]\n ", WHT);
		printf("%s <time must be in milliseconds>\n", RED);
		exit(1);
	}
	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				print_err("all arguments must be positive numbers\n");
		}
	}
}

void	semaphore_unlink(void)
{
	sem_unlink("print");
	sem_unlink("finish");
	sem_unlink("forks");
	sem_unlink("eat");
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = -1;
	semaphore_unlink();
	check_args(ac, av);
	get_data(av, &data);
	while (++i < data.nb_philo)
		sem_wait(data.finish);
	ft_destroy(&data);
	return (0);
}
