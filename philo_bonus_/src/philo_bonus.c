/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:37:16 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/22 22:24:51 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*end_diner(void *ndata)
{
	int		i;
	t_data	*data;

	data = ndata;
	i = -1;
	while (++i <= data->nb_philo)
	{
		if ((ft_get_time() - data->philo[i].last_eat) >= data->time_die)
		{
			usleep(200);
			ft_print_dead("died", i + 1, data);
			break ;
		}
		if (i == data->nb_philo - 1)
			i = -1;
		usleep(100);
	}
	return (NULL);
}

void	get_philodata(t_data *data)
{
	int	i;
	int pid;
	
	i = -1;
	data->start_time = ft_get_time();
	while (++i < data->nb_philo)
	{
		data->philo[i].nbr = i;
		data->philo[i].data = data;
		data->philo[i].nbr_eat = 0;
		data->philo[i].last_eat = ft_get_time();
		pid = fork();
		if (pid == 0)
			ft_actions(data->philo[i]);
		data->table_id[i] = pid;
	}
}
