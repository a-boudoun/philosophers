/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:42:39 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/22 22:22:07 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
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
	get_philodata(data);
}

void	check_args(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 6 && ac != 5)
	{
		print_err("%splease enter: ./philo [number_of_philosophers] ");
		print_err("%s[time_to_die] [time_to_eat] [time_to_sleep] [number_of");
		print_err("%s_times_each_philosopher_must_eat(optional argument)]\n ");
		print_err("%s <time must be in milliseconds>\n");
	}
	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				print_err("%sall arguments must be positive numbers\n");
		}
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	check_args(ac, av);
	get_data(av, &data);
	ft_destroy(&data);
	return (0);
}
