/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:37:16 by aboudoun          #+#    #+#             */
/*   Updated: 2022/05/26 11:40:59 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	end_diner(t_data *data)
{
	int	i;
	int	deth;

	i = -1;
	while (++i <= data->nb_philo)
	{
		if (data->philo_have_eaten == data->nb_philo)
		{
			ft_print("we are done", i + 1, data);
			break ;
		}
		deth = (ft_get_time() - data->philo[i].start_time);
		if (deth >= data->time_die)
		{
			data->on_dead = 1;
			ft_print("died", i + 1, data);
			break ;
		}
		if (i == data->nb_philo - 1)
			i = -1;
	}
	ft_destroy(data);
	return (0);
}

void	get_philodata(t_data *data)
{
	int	i;

	pthread_mutex_init(&(data->print), NULL);
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	i = -1;
	data->print_time = ft_get_time();
	while (++i < data->nb_philo)
	{
		data->philo[i].nbr = i;
		pthread_mutex_init(&(data->philo[i].left_fork), NULL);
		data->philo[i].data = data;
	}
	i = -1;
	while (++i < data->nb_philo)
	{
		data->philo[i].nbr_eat = 0;
		data->philo[i].start_time = ft_get_time();
		if (i == data->nb_philo - 1)
			data->philo[i].right_fork = &(data->philo[0].left_fork);
		else
			data->philo[i].right_fork = &(data->philo[i + 1].left_fork);
		pthread_create(&(data->philo->philo_t), \
				NULL, &ft_actions, &data->philo[i]);
		pthread_detach(data->philo->philo_t);
	}
}
