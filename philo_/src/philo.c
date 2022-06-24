/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:37:16 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/24 21:45:34 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	end_diner(t_data *data)
{
	int		i;

	i = -1;
	while (++i <= data->nb_philo)
	{
		pthread_mutex_lock(&(data->philo[i].eat));
		if ((ft_get_time() - data->philo[i].last_eat) >= data->time_die)
		{
			data->finish = 1;
			usleep(200);
			ft_print_dead("died", i + 1, data);
			break ;
		}
		pthread_mutex_unlock(&(data->philo[i].eat));
		if (data->philo_have_eaten == data->nb_philo)
		{
			data->finish = 1;
			break ;
		}
		if (i == data->nb_philo - 1)
			i = -1;
		usleep(50);
	}
	ft_destroy(data);
}

void	get_philodata(t_data *data)
{
	int			i;

	i = -1;
	data->start_time = ft_get_time();
	while (++i < data->nb_philo)
	{
		data->philo[i].nbr = i;
		pthread_mutex_init(&(data->philo[i].left_fork), NULL);
		pthread_mutex_init(&(data->philo[i].eat), NULL);
		data->philo[i].data = data;
	}
	i = -1;
	while (++i < data->nb_philo)
	{
		data->philo[i].nbr_eat = 0;
		data->philo[i].last_eat = ft_get_time();
		if (i == data->nb_philo - 1)
			data->philo[i].right_fork = &(data->philo[0].left_fork);
		else
			data->philo[i].right_fork = &(data->philo[i + 1].left_fork);
		pthread_create(&(data->philo[i].philo_t), \
				NULL, &ft_actions, &data->philo[i]);
		pthread_detach(data->philo[i].philo_t);
	}
	end_diner(data);
}
